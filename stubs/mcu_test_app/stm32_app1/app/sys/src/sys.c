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
	/*< GPIO clock initialization */
#if 0
	GPIO_Clock_Init();
#endif

	/*< communication initialization */
	Comm_Init();
}

void Sys_Run(void)
{
	while (1)
	{
		Comm_TxString();

		Sys_Delay();
	}
}

void Sys_Delay(void)
{
	uint16_t i, j;

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++);
	}
}




