#ifndef __COMM_H__
#define __COMM_H__

extern void Comm_Init(void);

extern void Comm_TxFrame(void);

extern uint8_t Comm_Rx_Byte(uint8_t* byte);

extern void Comm_Tx_Frame(uint8_t* frame, uint8_t size);

#endif //__COMM_H__
