#ifndef __SERIAL_INTERFACE__
#define __SERIAL_INTERFACE__

#include <stdint.h>

/**********************************************************************************************************************************
 *                                                     Type definitions
 *********************************************************************************************************************************/

/*< callback function pointer declaration */
typedef void(*si_callback_ptr)(uint8_t*, uint8_t);


typedef struct SI_Message_Tag
{
	uint8_t SI_MsgId;                  /*< message id */
	uint8_t SI_MsgSize;                /*< message size */
	si_callback_ptr SI_CallBack;       /*< callback function of the message */
}SI_Message;


/**********************************************************************************************************************************
 *                                                   Function declaration
 *********************************************************************************************************************************/

/**
 * @brief: 
 * @param:
 * @return:
 **/

extern void SI_Rx_Handler(void);

#endif //__SERIAL_INTERFACE__