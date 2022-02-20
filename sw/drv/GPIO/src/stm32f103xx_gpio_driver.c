/*
 * stm32f103xx_gpio_driver.c
 *
 *  Created on: Oct 29, 2020
 *      Author: user
 */


#include "stm32f103xx_gpio_driver.h"




/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
#if 1

	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}

	}
#endif

}




/*********************************************************************
 * @fn      		  - GPIO_Init
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	 uint32_t temp=0; //temp. register

	 //enable the peripheral clock

	// GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);



	if(pGPIOHandle->GPIO_PinConfig.PinNumber <=7)

	{
		//1 . configure the mode of gpio mode

		temp = (pGPIOHandle->GPIO_PinConfig.PinMode << (4 * (pGPIOHandle->GPIO_PinConfig.PinNumber%8) ) );
		pGPIOHandle->pGPIOx->CRL &= ~( 0x3 << (4 * pGPIOHandle->GPIO_PinConfig.PinNumber)); //clearing
		pGPIOHandle->pGPIOx->CRL |= temp; //setting


		//2. configure the gpio type
		temp = (pGPIOHandle->GPIO_PinConfig.PinType << (( 4 * (pGPIOHandle->GPIO_PinConfig.PinNumber%8))+2));
		pGPIOHandle->pGPIOx->CRL &= ~( 0x3 << (( 4 * (pGPIOHandle->GPIO_PinConfig.PinNumber%8))+2)); //clearing
		pGPIOHandle->pGPIOx->CRL |= temp;
	}

	else
	{
		//1 . configure the mode of gpio mode

		temp = (pGPIOHandle->GPIO_PinConfig.PinMode << (4 * (pGPIOHandle->GPIO_PinConfig.PinNumber%8) ) );
		pGPIOHandle->pGPIOx->CRH &= ~( 0x3 << (4 * pGPIOHandle->GPIO_PinConfig.PinNumber)); //clearing
		pGPIOHandle->pGPIOx->CRH |= temp; //setting


		//2. configure the gpio type
		temp = (pGPIOHandle->GPIO_PinConfig.PinType << (( 4 * (pGPIOHandle->GPIO_PinConfig.PinNumber%8))+2));
		pGPIOHandle->pGPIOx->CRH &= ~( 0x3 << (( 4 * (pGPIOHandle->GPIO_PinConfig.PinNumber%8))+2)); //clearing
		pGPIOHandle->pGPIOx->CRH |= temp;
	}



}


/*********************************************************************
 * @fn      		  - GPIO_DeInit
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{


}



/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   0 or 1
 *
 * @Note              -

 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
   uint8_t value;

   value = (uint8_t )((pGPIOx->IDR  >> PinNumber) & 0x00000001 ) ;

   return value;
}


/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;

	value = (uint16_t)pGPIOx->IDR;

	return value;
}


/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{

	if(Value == GPIO_PIN_SET)
	{
		//write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx->ODR |= ( 1 << PinNumber);
	}else
	{
		//write 0
		pGPIOx->ODR &= ~( 1 << PinNumber);
	}
}


/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR  = Value;
}


/*********************************************************************
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR  ^= ( 1 << PinNumber);
}



/*********************************************************************
 * @fn      		  - GPIO_IRQConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */

