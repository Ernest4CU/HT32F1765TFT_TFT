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
#include "picture.h"




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
	int i=0;
#if (HT32_LIB_DEBUG == 1)
  debug();
#endif
	SPI_LCD_Init();
	SPI_LCD_Config();
	  /* Set back color as black */
  SPI_LCD_BackColorSet(Blue);

  /* Set text color as yellow */
  SPI_LCD_TextColorSet(Yellow);

  /* Display words on LCD */

  SPI_LCD_StringLineDisplay(Line3, "        TJCJ        ");
	SPI_LCD_BackColorSet(Red);
	SPI_LCD_CharDisplay(Line0,4,'A');
	SPI_LCD_LineDraw(Line2,20,100,Horizontal);
	
	
	SPI_LCD_RectDraw(Line1,50,10,30);
	
	SPI_LCD_DisplayOff();
	SPI_LCD_delay(1000);
	SPI_LCD_DisplayOn();
	SPI_LCD_CircleDraw(Line7,30,30);
	SPI_LCD_delay(500);
	SPI_LCD_Clear(Red);
	for(i=0;i<100;i++){
	SPI_LCD_TextColorSet(Yellow);
	SPI_LCD_CircleDraw(Line7,i,30);
	SPI_LCD_TextColorSet(Red);
	SPI_LCD_CircleDraw(Line7,i,30);
	}
	
	/* Show pictures on LCD */
  SPI_LCD_PicDraw((0),(0),16,16,HT32_Table);
	
	while(1);
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
