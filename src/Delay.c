#include "Delay.h"



/*********************************************************************************************************//**
* @brief  Configures GPTM0 for time estimate.
* @retval None
***********************************************************************************************************/
void GPTM_Configuration(void)
{
	GPTM_TimeBaseInitTypeDef TimeBaseInit;

	TimeBaseInit.CounterMode = GPTM_CNT_MODE_UP;
	TimeBaseInit.CounterReload = SystemCoreClock / (1000 * 2);
	TimeBaseInit.Prescaler = 1;
	TimeBaseInit.PSCReloadTime = GPTM_PSC_RLD_IMMEDIATE;
	GPTM_TimeBaseInit(GPTM0, &TimeBaseInit);
	GPTM_Cmd(GPTM0, ENABLE);
}
/*********************************************************************************************************//**
* @brief  Used to delay x ms.
* @retval None
***********************************************************************************************************/
void DelayMS(u32 ms)
{
	GPTM_SetCounter(GPTM0, 0);

	while(ms--)
	{
		 GPTM_ClearFlag(GPTM0, GPTM_FLAG_UEV);
		 while(!GPTM_GetFlagStatus(GPTM0, GPTM_FLAG_UEV));
	}
}
