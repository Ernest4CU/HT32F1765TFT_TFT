/*********************************************************************************************************//**
 * @file    GPIO/InputOutput/main.c
 * @version V1.0
 * @date    04/11/2011
 * @brief   Main program.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x.h"
#include "ht32f175x_275x_board.h"
#include "Delay.h"





/** @addtogroup HT32F175x_275x_Peripheral_Examples HT32F175x/275x Peripheral Examples
  * @{
  */

/** @addtogroup GPIO_Examples GPIO
  * @{
  */

/** @addtogroup InputOutput
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/
/* Private define ------------------------------------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------------------------------------*/
extern const u32 DVB_GpioClock[DVB_GPIO_NBR];

/* Private function prototypes -----------------------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------------------------------------*/

/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  * @note At this stage the microcontroller clock setting should has already been configured.
  *       This can be done through SystemInit() function which is called from startup
  *       file (startup_ht32f175x.s) before branching to application main().
  *       To reconfigure the default setting of SystemInit() function, please refer to
  *       system_ht32f125x.c file
  * @details The main function works as the following:
  *    - Check if the backup domain is ready for access so as to disable isolation.
  *      Because some GPIO pins(PB4, PB5 and PB6) are located in the backup bomain.
  *    - Enable AFIO peripheral clock
  *    - Configure WEAKUP, KEY1, KEY2 pins as the input function
  *      - Enable GPIO peripheral clock of input pins
  *      - Configure AFIO mode of input pins
  *      - Configure GPIO direction of input pins
  *    - Configure LED1, LED2, LED3 pins as the output function
  *      - Enable GPIO peripheral clock of output pins
  *      - Configure AFIO mode of output pins
  *      - Configure GPIO direction of output pins
  *    - Infinite loop to read data from the input pin and then output to LED
  *      - Read WEAKUP and then output via LED1
  *      - Read KEY1 and then output via LED2
  *      - Read KEY2 and then output via LED3
  *
  ***********************************************************************************************************/
int main(void)
{
#if (HT32_LIB_DEBUG == 1)
  debug();
#endif

  /* Check if the backup domain is ready for access so as to disable isolation.
     Because some GPIO pins(PB4, PB5 and PB6) are located in backup bomain. */
  CKCU_APBPerip1ClockConfig(CKCU_APBEN1_RTC, ENABLE);
  if(PWRCU_CheckReadyAccessed() != PWRCU_OK)
  {
    while(1);
  }

	  /* Enable AFIO peripheral clock */
	CKCU_APBPerip0ClockConfig(CKCU_APBEN0_AFIO, ENABLE);  //定时器算是AFIO设备
	CKCU_APBPerip1ClockConfig(CKCU_APBEN1_GPTM0, ENABLE);
	GPTM_Configuration();               /* GPTM configuration */      
	
  /* Configure LED1, LED2, LED3 pins as output function */

  /* Enable GPIO peripheral clock of output pins */
  CKCU_APBPerip0ClockConfig(DVB_GpioClock[LED1_GPIO_ID], ENABLE);
  CKCU_APBPerip0ClockConfig(DVB_GpioClock[LED2_GPIO_ID], ENABLE);
  CKCU_APBPerip0ClockConfig(DVB_GpioClock[LED3_GPIO_ID], ENABLE);

  /* Configure AFIO mode of output pins */
  HT32F_DVB_GPxConfig(LED1_GPIO_ID, LED1_AFIO_PIN, LED1_AFIO_MODE);
  HT32F_DVB_GPxConfig(LED2_GPIO_ID, LED2_AFIO_PIN, LED2_AFIO_MODE);
  HT32F_DVB_GPxConfig(LED3_GPIO_ID, LED2_AFIO_PIN, LED3_AFIO_MODE);

  /* Configure GPIO direction of output pins */
  GPIO_DirectionConfig(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_DIR_OUT);
  GPIO_DirectionConfig(LED2_GPIO_PORT, LED2_GPIO_PIN, GPIO_DIR_OUT);
  GPIO_DirectionConfig(LED3_GPIO_PORT, LED3_GPIO_PIN, GPIO_DIR_OUT);

  /* Infinite loop to read data from input pin and then output to LED */
  while(1)
  {
		
    /* Read WEAKUP and then output to LED1 */
    GPIO_WriteOutBits(LED1_GPIO_PORT, LED1_GPIO_PIN, SET);

    /* Read KEY1 and then output to LED2 */
    GPIO_WriteOutBits(LED2_GPIO_PORT, LED2_GPIO_PIN, SET);

    /* Read KEY2 and then output to LED3 */
    GPIO_WriteOutBits(LED3_GPIO_PORT, LED3_GPIO_PIN, SET);
		DelayMS(1000);
		
		    /* Read WEAKUP and then output to LED1 */
    GPIO_WriteOutBits(LED1_GPIO_PORT, LED1_GPIO_PIN, RESET);

    /* Read KEY1 and then output to LED2 */
    GPIO_WriteOutBits(LED2_GPIO_PORT, LED2_GPIO_PIN, RESET);

    /* Read KEY2 and then output to LED3 */
    GPIO_WriteOutBits(LED3_GPIO_PORT, LED3_GPIO_PIN, RESET);
		DelayMS(1000);
		
  }
}

#if (HT32_LIB_DEBUG == 1)
/*********************************************************************************************************//**
  * @brief  Reports both the error name of the source file and the source line number.
  * @param  filename: pointer to the source file name.
  * @param  uline: error line source number.
  * @retval None
  ***********************************************************************************************************/
void assert_error(u8* filename, u32 uline)
{
  /*
     This function is called by IP library that the invalid parameters has been passed to the library API.
     Debug message can be added here.
  */

  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
