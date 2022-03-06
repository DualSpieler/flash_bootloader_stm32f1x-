#include "../api/serial_interface_msg_def.h"
#include <platform.h>


/**********************************************************************************************************************************
 *                                      Serial interface message callback function declaration
 *********************************************************************************************************************************/

#undef SI_MESSAGE
#define SI_MESSAGE(MsgId, MsgSize, MsgDescription) static void MsgId##_SI_Callback(uint8_t*, uint8_t);

SI_MESSAGE_DECLARATION

/**********************************************************************************************************************************
 *                                           Serial interface Rx/Tx message definition
 *********************************************************************************************************************************/

#undef SI_MESSAGE
#define SI_MESSAGE(MsgId, MsgSize, MsgDescription) { MsgId, MsgSize, MsgId##_SI_Callback },

SI_Message SI_Msg[] = {
		SI_MESSAGE_DECLARATION
};

/**
 * global variable to store the rx frame data
 */
uint8_t SI_Rx_Frame[QUEUE_STATIC_BUFFER_SIZE];

/**
 * @brief : this function calculates 8bit checksum, last byte of the passed array is considered as the checksum to be validated against
 **/
extern uint8_t SI_Validate_Checksum(uint8_t* rx_bytes, uint8_t size);

/**
 * @brief : this function calls the callback of the passed message id
 **/
extern uint8_t SI_Rx_Callback(uint8_t* rx_bytes, uint8_t size);

/**
 * @brief : this function returns the index of the passed message id
 **/
extern uint8_t SI_Get_MessageIndex(uint8_t MsgId, uint8_t* index);


void SI_Rx_Handler(void)
{
	uint8_t byte;

	/*< in frame_state lower nibble is used to store the frame reception state, upper nibble is reserved for frame reception timeout  */
	static uint8_t frame_state = 0;
	static uint8_t frame_index = 0;

	while (Comm_Rx_Byte(&byte))
	{
		if (((SI_STX != byte) && (SI_ETX != byte) && (SI_DTX != byte)) || (0X01 & frame_state))
		{
			SI_Rx_Frame[frame_index] = byte;
			frame_index++;

			if (0X01 & frame_state)
			{
				frame_state &= 0XF0;
			}
		}
		else if (SI_DTX == byte)
		{
			frame_state |= 0X01;
		}
		else if (SI_ETX == byte)
		{
			SI_Rx_Callback(&SI_Rx_Frame[0], frame_index);

			frame_index = 0;
		}
		else
		{
			/*< do nothing */
		}
	}
}

/**
 * note: refer function declaration for more info
 **/
uint8_t SI_Get_MessageIndex(uint8_t MsgId, uint8_t* index)
{
	uint8_t i;
	uint8_t retval = 0;

	for (i = 0; i < SI_TxMsgId_End; i++)
	{
		if (MsgId == SI_Msg[i].SI_MsgId)
		{
			*index = i;

			retval = 1;
		}
	}

	return retval;
}

/**
 * note: refer function declaration for more info
 **/
uint8_t SI_Rx_Callback(uint8_t* rx_bytes, uint8_t size)
{
	uint8_t retval = 1;
	uint8_t index = 0;

	if (SI_Validate_Checksum(&rx_bytes[0], size))
	{
		/*< exclude the checksum byte */
		size--;

		if (SI_Get_MessageIndex(rx_bytes[0], &index))
		{
			/*< send only data byte to the callback function */
			size--;
			SI_Msg[index].SI_CallBack(&rx_bytes[1], size);
		}
		else
		{
			/*< invalid id */
			retval = 0;
		}
	}
	else
	{
		/*< invalid checksum send nack */
		if (SI_Get_MessageIndex(MsgNack, &index))
		{
			SI_Msg[index].SI_CallBack((void*)0, 0);
		}
	}

	return retval;
}

/**
 * note: refer function declaration for more info
 **/
uint8_t SI_Validate_Checksum(uint8_t* rx_bytes, uint8_t size)
{
	uint8_t retval = 0;
	uint16_t sum = 0; // if all bytes are 0xff the maximum value would be 65025
	uint8_t i;

	for (i = 0; i < (size-1); i++)
	{
		sum += rx_bytes[i];
	}

	sum = ~sum;
	sum += 1;

	if ((sum & 0XFF) == rx_bytes[size - 1])
	{
		retval = 1;
	}

	return retval;
}

/**********************************************************************************************************************************
 *                                            Serial interface callback function definition
 *********************************************************************************************************************************/

static void MsgAlive_SI_Callback(uint8_t *rx_bytes,uint8_t size)
{
	uint8_t index = 0;

	/*< send acknowledgment */
	if (SI_Get_MessageIndex(MsgAck, &index))
	{
		SI_Msg[index].SI_CallBack((void*)0, 0);
	}
}

static void MsgAck_SI_Callback(uint8_t* rx_bytes, uint8_t size)
{
	uint8_t bytes[1] = {
			0X01
	};

	Comm_Tx_Frame(&bytes[0], 1);
}

static void MsgNack_SI_Callback(uint8_t* rx_bytes, uint8_t size)
{
	uint8_t bytes[1] = {
				0X02
		};

	Comm_Tx_Frame(&bytes[0], 1);
}

static void MsgInvalidId_SI_Callback(uint8_t* rx_bytes, uint8_t size)
{
	uint8_t bytes[1] = {
				0X03
		};

	Comm_Tx_Frame(&bytes[0], 1);
}
