
/* Includes ------------------------------------------------------------------*/
#include <stm32f10x.h>
#include "Flash_EEPROM.h"
#include<stdint.h>
typedef unsigned char uint8_t;

void	Flash_Unlock()
{
		FLASH->CR = 0x00000000; //reset
	
		/*authorize flass access*/
		FLASH->KEYR=0x45670123;
		FLASH->KEYR=0xCDEF89AB;

}
	
void	Flash_Lock()
{
	
	FLASH->CR = (1<<7); //lock bit
}

void Flash_Erase(uint32_t address)
{	
		while(FLASH->SR & (1<<0));//check busy	
	
		FLASH->CR |= (1<<1);  //Page erase bit
		
		FLASH->AR =address;
	
		FLASH->CR |= (1<<6);  //STRT: Start erase
	
		while(FLASH->SR & (1<<0));//check busy		
	
}

void Flash_Write(uint32_t address ,uint32_t *wt_data, uint8_t len)
{	
	unsigned int idx=0;		
	
	unsigned int index=0;

	uint8_t word_size= (len/4);
	
	if(( len%4) >0)
	{
		word_size++;		
	}
	
	Flash_Unlock(); //write access
	
	Flash_Erase(address);
	
	FLASH->CR = 0x00000000;  //reset erase
	
	while(FLASH->SR & (1<<0));//check busy	
	
	FLASH->CR |= (1<<0);//enable programming bit PG(programming)
	
	while(index<word_size)
	{
		for(idx=0;idx<2	;idx++) //min 2 byte have to write
		{
			*(uint16_t*)address = (uint16_t)(wt_data[index]>>(16*idx));//little endian
			address+=2;
			while(FLASH->SR & (1<<0));//check busy			
		}		
		index++;
	}	
	
	Flash_Lock();
	
}

void Flash_Read(uint32_t address,volatile uint8_t *data,uint8_t size)
{
	
	static unsigned char i=0;
	
	for(i=0;i<size;i++)
	{
		*data=*(volatile uint8_t *)address;
		address++;
		data++;			
	}

}


