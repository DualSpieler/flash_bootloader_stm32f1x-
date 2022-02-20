


#ifndef _FLASH_H_
#define _FLASH_H_

#include<stdint.h>


#define PAGE_1  0x0801C000		//session admin datas
#define PAGE_2  0x0801C400    //Config message
#define PAGE_3  0x0801C800	  
#define PAGE_4  0x0801CC00	  //session 1
#define PAGE_5  0x0801D000		//session 2
#define PAGE_6  0x0801D400		//session 3
#define PAGE_7  0x0801D800		//session 4
#define PAGE_8 	0x0801DC00		//session 5
#define PAGE_9 	0x0801E000		//session 6
#define PAGE_10 0x0801E400		//session 7
#define PAGE_11 0x0801E800		//session 8
#define PAGE_12 0x0801EC00		//session 9
#define PAGE_13 0x0801F000		//session 10
#define PAGE_14 0x0801F400		//session 11
#define PAGE_15 0x0801F800    //session 12
#define PAGE_16 0x0801FC00  

extern void Flash_Write(uint32_t address , uint32_t *wt_data,uint8_t len);

extern void Flash_Read(uint32_t address,volatile uint8_t *data,uint8_t size);

extern void Flash_Erase(uint32_t address);

extern void	Flash_Unlock(void);

extern void	Flash_Lock(void);

#endif  /* _FLASH_H_ */
