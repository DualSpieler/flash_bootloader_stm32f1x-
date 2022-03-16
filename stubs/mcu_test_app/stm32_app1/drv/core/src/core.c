#include <drv.h>

volatile uint32_t jill = 1;

void CortexM3_Init(void)
{
#if 0
	/*< Enable fault exceptions */
	NVIC_EnableIRQ(NonMaskableInt_IRQn);

	NVIC_EnableIRQ(MemoryManagement_IRQn);

	NVIC_EnableIRQ(BusFault_IRQn);

	NVIC_EnableIRQ(UsageFault_IRQn);
#endif
}

void NMI_Handler(void)
{
    volatile uint8_t i = 1;
    while (i)
    {
    	i = 2;
    }
}

void HardFault_Handler(void)
{
    volatile uint32_t jill = 1;
    while (jill)
    {
    	jill = 2;
#if 0
		jill = SCB->CFSR;

		jill = (0XFF & ((uint32_t)(jill >> 24)));

		jill = jill;
#endif
    }
}

void MemManage_Handler(void)
{
    volatile uint8_t i = 1;
    while (i)
    {
    	i = 2;
    }
}

void BusFault_Handler(void)
{
    volatile uint8_t i = 1;
    while (i)
    {
    	i = 2;
    }
}

void UsageFault_Handler(void)
{
    volatile uint8_t i = 1;
    while (i)
    {
    	i = 2;
    }
}
