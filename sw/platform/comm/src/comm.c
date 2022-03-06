#include <platform.h>

/**
 * @brief: uart handle used by the comm manager
 */
UART_Handle_T CommUart_Handle = NULL;

/**
 * @brief: comm buffer used for rx bytes
 */
MyQueueStatic CommBuffer;

/**
 * @brief: This function enqueues the data received by uart receive buffer, this function is passed as a rx callback while uart configuration
 */
extern void Comm_Rx_Handler(uint8_t byte);

extern uint8_t Comm_Get_Checksum(uint8_t *frame, uint8_t size);

void Comm_Init(void)
{
	/*< initialize queue buffer */
	MyStaticQueue_Init(&CommBuffer);

	/*< gpio pin initialization for uart rx/tx */
	GPIO_Params_T PA;

	PA.GPIO_Port = DEVICE_PORT_A;
	PA.GPIO_Pin = DEVICE_PORT_PIN_09;
	PA.GPIO_Mode = DEVICE_PIN_CONFIG_FUNC_ALT_OUT_PUSH_PULL;
    PA.GPIO_Config_Func = DEVICE_PIN_MODE_OUT_50Mhz;
    GPIO_SetConfig(&PA); // tx

	PA.GPIO_Port = DEVICE_PORT_A;
	PA.GPIO_Pin = DEVICE_PORT_PIN_10;
	PA.GPIO_Mode = DEVICE_PIN_CONFIG_FUNC_ALT_OUT_PUSH_PULL;
	PA.GPIO_Config_Func = DEVICE_PIN_MODE_OUT_50Mhz;

	GPIO_SetConfig(&PA); // rx

	/*< uart peripheral initialization */
	UART_Params_T uart0;
	uart0.uart_Channel = DEVICE_UART_CHANNEL_1;
	uart0.uart_OperatingMode = DEVICE_UART_MODE_TXRX;
	uart0.uart_WordLength = DEVICE_UART_WORD_LEN_8;
	uart0.uart_StopBits = DEVICE_UART_STOP_BIT_1;
	uart0.uart_Parity = DEVICE_UART_PARITY_NONE;
	uart0.uart_Baudrate = DEVICE_UART_BR_9600;
	uart0.uart_TxCallBack = 0;
	uart0.uart_RxCallBack = Comm_Rx_Handler;

	CommUart_Handle = UART_SetConfig(&uart0);
}

void Comm_Rx_Handler(uint8_t byte)
{
	MyStaticQueue_EnQueue(&CommBuffer, byte);
}

uint8_t Comm_Rx_Byte(uint8_t* byte)
{
	return MyStaticQueue_DeQueue(&CommBuffer, byte);
}

void Comm_Tx_Frame(uint8_t* frame, uint8_t size)
{
	uint8_t i;
	UART_TxByte(CommUart_Handle, SI_STX);

	for (i = 0; i < size; i++)
	{
		UART_TxByte(CommUart_Handle, frame[i]);
	}

	UART_TxByte(CommUart_Handle, Comm_Get_Checksum(frame, size));

	UART_TxByte(CommUart_Handle, SI_ETX);
}

uint8_t Comm_Get_Checksum(uint8_t *frame, uint8_t size)
{
	uint8_t i;
	uint16_t sum = 0;

	for (i = 0; i < size; i++)
	{
		sum += frame[i];
	}

	sum = ~sum;
	sum += 1;

	return (sum & 0XFF);
}

#if 0
void Comm_TxFrame(void)
{
	char string[] = "Test String\n\r";

	while (1)
	{
		UART_TxString(CommUart_Handle, (uint8_t*)string, strlen(string));
		Comm_Delay();
	}
}

void Comm_Delay(void)
{
	uint16_t i, j;

	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j < 500; j++);
	}
}
#endif
