/*
 * bootmanger.c
 *
 *  Created on: Feb 12, 2022
 *      Author: MAHESH
 */

/*
 * main.c
 *
 *  Created on: Oct 19, 2020
 *      Author: user
 */

#include "stm32f103xx.h"
#include <stdio.h>

//extern void initialise_monitor_handles(void);


void delay(void)
{
	unsigned int i,j;

	for (i=0; i<1000; i++)
	{
		for (j=0; j<100; j++);  //5000
	}
}

int main()
{

	//initialise_monitor_handles(); //openocd semihosting enable only for debugging ,for normal test command this line

	GPIO_Handle_t led;

	led.pGPIOx = GPIOC;
	led.GPIO_PinConfig.PinNumber=GPIO_PIN_NO_13 ;
	led.GPIO_PinConfig.PinMode=GPIO_MODE_OUT_10mhz;
	led.GPIO_PinConfig.PinType=GPIO_OP_TYPE_PP;
	GPIO_Init(&led);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOC,GPIO_PIN_NO_13);
		//printf("led_toggling\r\n");
		delay();
	}

	return 0;
}


