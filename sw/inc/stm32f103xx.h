/*
 * stm32f103xx.h
 *
 *  Created on: Oct 19, 2020
 *      Author: user
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

#include <stdint.h>

#define __vo volatile


/*
 * base address of flash and SRAM memory
 */

#define FLASH_BASEADDR				0X80000000U							/*BASE ADDRESS OF FLASH MEMORY	*/
#define SRAM1_BASEADDR				0X20000000U							/*BASE ADDRESS OF SRAM1 MEMORY	*/
#define SRAM						SRAM1_BASEADDR						/*BASE ADDRESS OF SRAM MEMORY	*/
#define ROM_BASEADDR				0X1FFFE000U							/*BASE ADDRESS OF ROM MEMORY	*/

/*
 *  AHBx and APBx peripheral bus base address
 */


#define PERIPH_BASEADDR				0x40000000U							/*BASE ADDRESS OF PERIPHERAL      */
#define APB1PERIPH_BASEADDR			PERIPH_BASEADDR						/*BASE ADDRESS OF APB1 PERIPHERAL */
#define APB2PERIPH_BASEADDR			(PERIPH_BASEADDR+0X10000U)			/*BASE ADDRESS OF APB1 PERIPHERAL */
#define AHBPERIPH_BASEADDR			(PERIPH_BASEADDR+0X18000U)			/*BASE ADDRESS OF AHB PERIPHERAL  */

/*
 *  RCC,GPIOx,SPI base address
 */

#define RCC_BASEADDR			(PERIPH_BASEADDR+0X21000U)					/*BASE ADDRESS OF RCC */
#define GPIOA_BASEADDR			(APB2PERIPH_BASEADDR+0X0800U)				/*BASE ADDRESS OF GPIOA */
#define GPIOB_BASEADDR			(APB2PERIPH_BASEADDR+0X0C00U)				/*BASE ADDRESS OF GPIOB */
#define GPIOC_BASEADDR			(APB2PERIPH_BASEADDR+0X1000U)				/*BASE ADDRESS OF GPIOC */
#define GPIOD_BASEADDR			(APB2PERIPH_BASEADDR+0X1400U)				/*BASE ADDRESS OF GPIOD */
#define GPIOE_BASEADDR			(APB2PERIPH_BASEADDR+0X1800U)				/*BASE ADDRESS OF GPIOE */
#define GPIOF_BASEADDR			(APB2PERIPH_BASEADDR+0X1C00U)				/*BASE ADDRESS OF GPIOF */
#define GPIOG_BASEADDR			(APB2PERIPH_BASEADDR+0X2000U)				/*BASE ADDRESS OF GPIOG */
#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR+0X3000U)				/*BASE ADDRESS OF SPI1 */
#define I2C1_BASEADDR  			(PERIPH_BASEADDR+0X5400U)					/*BASE ADDRESS OF I2C1 */
#define I2C2_BASEADDR  			(PERIPH_BASEADDR+0X5800U)					/*BASE ADDRESS OF I2C2 */
#define USART1_BASEADDR  		(APB2PERIPH_BASEADDR+0X3800U)				/*BASE ADDRESS OF USART1 */
#define USART2_BASEADDR  		(APB1PERIPH_BASEADDR+0X4400U)				/*BASE ADDRESS OF USART2 */
#define USART3_BASEADDR  		(APB1PERIPH_BASEADDR+0X4800U)				/*BASE ADDRESS OF USART3 */


/*
 * peripheral reg definition structure for RCC CLK Configuration
 */

typedef struct
{

	__vo uint32_t CR;       	 /* 	 Clock control register							address offset:0x000 */
	__vo uint32_t CFGR;			 /* 	 Clock configuration register 					address offset:0x004 */
	__vo uint32_t CIR;		 	 /* 	 Clock interrupt register  						address offset:0x008 */
	__vo uint32_t APB2RSTR;		 /* 	 APB2 peripheral reset register  				address offset:0x00c */
	__vo uint32_t APB1RSTR;		 /* 	 APB1 peripheral reset register					address offset:0x010 */
	__vo uint32_t AHBENR;		 /* 	 AHB Peripheral Clock enable register 			address offset:0x014 */
	__vo uint32_t APB2ENR;		 /* 	 APB2 peripheral clock enable register  		address offset:0x018 */
	__vo uint32_t APB1ENR;		 /* 	 APB1 peripheral clock enable register			address offset:0x01c */
	__vo uint32_t BDCR;			 /* 	 Backup domain control register 				address offset:0x020 */
	__vo uint32_t CSR;			 /* 	 Control/status register   						address offset:0x024 */
	__vo uint32_t AHBSTR;		 /* 	 AHB peripheral clock reset register  			address offset:0x028 */
	__vo uint32_t CFGR2;		 /* 	 Clock configuration register2  				address offset:0x02C */

}RCC_RegDef_t;



/*
 * peripheral reg definition structure for gpio
 */

typedef struct
{

	__vo uint32_t CRL;        /* 	 Port configuration register low				address offset:0x00 */
	__vo uint32_t CRH;		 /* 	 Port configuration register high 				address offset:0x04 */
	__vo uint32_t IDR;		 /* 	 Port input data register 						address offset:0x08 */
	__vo uint32_t ODR;		 /* 	 Port output data register 						address offset:0x0c */

}GPIO_RegDef_t;




/*
 * peripheral reg definition structure for SPI
 */

typedef struct
{

	__vo uint32_t CR1;       	 /* 	 SPI control register 1							address offset:0x00 */
	__vo uint32_t CR2;			 /* 	 SPI control register 2  						address offset:0x04 */
	__vo uint32_t SR;		 	 /* 	 SPI status register  							address offset:0x08 */
	__vo uint32_t DR;			 /* 	 SPI data register  							address offset:0x0c */
	__vo uint32_t CRCPR;		 /* 	 SPI CRC polynomial register					address offset:0x10 */
	__vo uint32_t RXCRCR;		 /* 	 SPI RX CRC register 							address offset:0x14 */
	__vo uint32_t TXCRCR;		 /* 	 SPI TX CRC register  							address offset:0x18 */
	__vo uint32_t I2SCFGR;		 /* 	 SPI_I2S configuration register					address offset:0x1c */
	__vo uint32_t I2SPR;		 /* 	 SPI_I2S prescaler register 					address offset:0x20 */

}SPI_RegDef_t;

/*
 * peripheral register definition structure for I2C
 */
typedef struct
{
  __vo uint32_t CR1;        /*!< I2C Control register 1,     										Address offset: 0x00 */
  __vo uint32_t CR2;        /*!< I2C Control register 2,     										Address offset: 0x04 */
  __vo uint32_t OAR1;       /*!< I2C Own address register 1,     									Address offset: 0x08 */
  __vo uint32_t OAR2;       /*!< I2C Own address register 2,     									Address offset: 0x0C */
  __vo uint32_t DR;         /*!< I2C Data register ,     											Address offset: 0x10 */
  __vo uint32_t SR1;        /*!< I2C Status register 1 ,     										Address offset: 0x14 */
  __vo uint32_t SR2;        /*!< I2C Status register 2,     										Address offset: 0x18 */
  __vo uint32_t CCR;        /*!< I2C Clock control register ,     									Address offset: 0x1C */
  __vo uint32_t TRISE;      /*!< I2C TRISE register,     											Address offset: 0x20 */

}I2C_RegDef_t;

/*
 * peripheral register definition structure for USART
 */
typedef struct
{
	__vo uint32_t SR;         /*!< Status register,     											Address offset: 0x00 */
	__vo uint32_t DR;         /*!< Data register,     												Address offset: 0x04 */
	__vo uint32_t BRR;        /*!< Baud rate register ,     										Address offset: 0x08 */
	__vo uint32_t CR1;        /*!< Control register 1 ,     										Address offset: 0x0C */
	__vo uint32_t CR2;        /*!< Control register 2 ,     										Address offset: 0x10 */
	__vo uint32_t CR3;        /*!< Control register 3 ,     										Address offset: 0x14 */
	__vo uint32_t GTPR;       /*!< Guard time and prescaler register,     							Address offset: 0x18 */
} USART_RegDef_t;


/*
 * peripheral definition macros
 */

#define RCC 				((RCC_RegDef_t*)RCC_BASEADDR)						/* macro def for rcc peripheral addr */
#define GPIOA				((GPIO_RegDef_t*)GPIOA_BASEADDR)					/* macro def for gpioa peripheral addr */
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASEADDR)					/* macro def for gpiob peripheral addr */
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASEADDR)					/* macro def for gpioc peripheral addr */
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASEADDR)					/* macro def for gpiod peripheral addr */

#define SPI1 				((SPI_RegDef_t*)SPI1_BASEADDR)						/* macro def for SPI peripheral addr */

#define I2C1  				((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2  				((I2C_RegDef_t*)I2C2_BASEADDR)


#define USART1  			((USART_RegDef_t*)USART1_BASEADDR)
#define USART2  			((USART_RegDef_t*)USART2_BASEADDR)
#define USART3  			((USART_RegDef_t*)USART3_BASEADDR)

/*
 * clock disable macro for gpio peripheral
 */


#define GPIOA_PCLK_DI()		(RCC->APB2ENR &= ~(1<<2))
#define GPIOB_PCLK_DI()		(RCC->APB2ENR &= ~(1<<3))
#define GPIOC_PCLK_DI()		(RCC->APB2ENR &= ~(1<<4))
#define GPIOD_PCLK_DI()		(RCC->APB2ENR &= ~(1<<5))


/*
 * clock enable macro for gpio peripheral
 */


#define GPIOA_PCLK_EN()		(RCC->APB2ENR |= (1<<2))
#define GPIOB_PCLK_EN()		(RCC->APB2ENR |= (1<<3))
#define GPIOC_PCLK_EN()		(RCC->APB2ENR |= (1<<4))
#define GPIOD_PCLK_EN()		(RCC->APB2ENR |= (1<<5))

/*
 * Clock Enable Macros for SPIx peripheralsbu
 */
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))


/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))




/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCCK_EN() (RCC->APB2ENR |= (1 << 14))
#define USART2_PCCK_EN() (RCC->APB1ENR |= (1 << 17))
#define USART3_PCCK_EN() (RCC->APB1ENR |= (1 << 18))



/******************************************************************************************
 *Bit position definitions of SPI peripheral
 ******************************************************************************************/
/*
 * Bit position definitions SPI_CR1
 */
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_DFF     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15

/*
 * Bit position definitions SPI_CR2
 */
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7


/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7

/******************************************************************************************
 *Bit position definitions of I2C peripheral
 ******************************************************************************************/
/*
 * Bit position definitions I2C_CR1
 */
#define I2C_CR1_PE						0
#define I2C_CR1_NOSTRETCH  				7
#define I2C_CR1_START 					8
#define I2C_CR1_STOP  				 	9
#define I2C_CR1_ACK 				 	10
#define I2C_CR1_SWRST  				 	15

/*
 * Bit position definitions I2C_CR2
 */
#define I2C_CR2_FREQ				 	0
#define I2C_CR2_ITERREN				 	8
#define I2C_CR2_ITEVTEN				 	9
#define I2C_CR2_ITBUFEN 			    10

/*
 * Bit position definitions I2C_OAR1
 */
#define I2C_OAR1_ADD0    				 0
#define I2C_OAR1_ADD71 				 	 1
#define I2C_OAR1_ADD98  			 	 8
#define I2C_OAR1_ADDMODE   			 	15

/*
 * Bit position definitions I2C_SR1
 */

#define I2C_SR1_SB 					 	0
#define I2C_SR1_ADDR 				 	1
#define I2C_SR1_BTF 					2
#define I2C_SR1_ADD10 					3
#define I2C_SR1_STOPF 					4
#define I2C_SR1_RXNE 					6
#define I2C_SR1_TXE 					7
#define I2C_SR1_BERR 					8
#define I2C_SR1_ARLO 					9
#define I2C_SR1_AF 					 	10
#define I2C_SR1_OVR 					11
#define I2C_SR1_TIMEOUT 				14

/*
 * Bit position definitions I2C_SR2
 */
#define I2C_SR2_MSL						0
#define I2C_SR2_BUSY 					1
#define I2C_SR2_TRA 					2
#define I2C_SR2_GENCALL 				4
#define I2C_SR2_DUALF 					7

/*
 * Bit position definitions I2C_CCR
 */

#define I2C_CCR_CCR 					 0
#define I2C_CCR_DUTY 					14
#define I2C_CCR_FS  				 	15

/******************************************************************************************
 *Bit position definitions of USART peripheral
 ******************************************************************************************/

/*
 * Bit position definitions USART_CR1
 */
#define USART_CR1_SBK					0
#define USART_CR1_RWU 					1
#define USART_CR1_RE  					2
#define USART_CR1_TE 					3
#define USART_CR1_IDLEIE 				4
#define USART_CR1_RXNEIE  				5
#define USART_CR1_TCIE					6
#define USART_CR1_TXEIE					7
#define USART_CR1_PEIE 					8
#define USART_CR1_PS 					9
#define USART_CR1_PCE 					10
#define USART_CR1_WAKE  				11
#define USART_CR1_M 					12
#define USART_CR1_UE 					13




/*
 * Bit position definitions USART_CR2
 */
#define USART_CR2_ADD   				0
#define USART_CR2_LBDL   				5
#define USART_CR2_LBDIE  				6
#define USART_CR2_LBCL   				8
#define USART_CR2_CPHA   				9
#define USART_CR2_CPOL   				10
#define USART_CR2_STOP   				12
#define USART_CR2_LINEN   				14


/*
 * Bit position definitions USART_CR3
 */
#define USART_CR3_EIE   				0
#define USART_CR3_IREN   				1
#define USART_CR3_IRLP  				2
#define USART_CR3_HDSEL   				3
#define USART_CR3_NACK   				4
#define USART_CR3_SCEN   				5
#define USART_CR3_DMAR  				6
#define USART_CR3_DMAT   				7
#define USART_CR3_RTSE   				8
#define USART_CR3_CTSE   				9
#define USART_CR3_CTSIE   				10


/*
 * Bit position definitions USART_SR
 */

#define USART_SR_PE        				0
#define USART_SR_FE        				1
#define USART_SR_NE        				2
#define USART_SR_ORE       				3
#define USART_SR_IDLE       			4
#define USART_SR_RXNE        			5
#define USART_SR_TC        				6
#define USART_SR_TXE        			7
#define USART_SR_LBD        			8
#define USART_SR_CTS        			9

//some generic macros

#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET
#define FLAG_RESET          RESET
#define FLAG_SET 			SET


#include "stm32f103xx_gpio_driver.h"
#include "stm32f103xx_uart_driver.h"

#endif /* INC_STM32F103XX_H_ */
