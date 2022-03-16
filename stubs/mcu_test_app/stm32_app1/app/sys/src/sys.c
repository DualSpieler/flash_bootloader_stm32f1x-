#include <platform.h>

void Sys_Init(void);
void Sys_Run(void);
void Sys_Delay(void);

int main(void)
{
	Sys_Init();

	Sys_Run();
}

void Sys_Init(void)
{
	/*< port A clock initialization */
	GPIO_Clock_Init();

	/*< communication initialization */
	Comm_Init();
}

void Sys_Run(void)
{
	while (1)
	{
		SI_Rx_Handler();
	}
}




