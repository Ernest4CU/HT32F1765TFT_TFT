 /*********************************************************************************************************//**
 * @file    spi_lcd.c
 * @version V1.0
 * @date    09/08/2011
 * @brief   This file provides a set of functions needed to manage the
 *          communication between SPI peripheral and LCD HX8347-DV.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "spi_lcd.h"
#include "font.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup HT32F1755_2755_Development_Board
  * @{
  */

/** @addtogroup SPI_LCD SPI_LCD
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup SPI_LCD_Private_TypesDefinitions SPI LCD private types definitions
  * @{
  */

/**
  * @}
  */

/* Private define ------------------------------------------------------------------------------------------*/
#define SYSTICKRELOAD   (9000)  // 1ms
/** @defgroup SPI_LCD_Private_Define SPI LCD private definitions
  * @{
  */

/**
  * @}
  */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup SPI_LCD_Private_Macro SPI LCD private macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------------------------------------*/
static u16 Color_Text = 0x0000;  // default: Black
static u16 Color_Back = 0xFFFF;  // default: White
static vu32 DelayTime = 0;
/** @defgroup SPI_LCD_Private_Values SPI LCD private variables
  * @{
  */
extern const u32 DVB_GpioClock[DVB_GPIO_NBR];
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup SPI_LCD_Private_Function_Prototypes SPI LCD private function prototypes
  * @{
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup SPI_LCD_Private_Functions SPI LCD private functions
  * @{
  */

/*********************************************************************************************************//**
  * @brief  Configure SYSTICK.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_SysTick_Config(void)
{
  SYSTICK_ClockSourceConfig(SYSTICK_SRC_STCLK);  // STCLK = 9MHz
  SYSTICK_SetReloadValue(SYSTICKRELOAD);         // 1ms
  SYSTICK_IntConfig(ENABLE);                     // Enable SysTick interrupt
}

/*********************************************************************************************************//**
  * @brief  Insert delay time.
  * @param  nTime: specify the delay time length with milliseconds.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_delay(u32 nTime)
{
  /* Enable the SysTick Counter */
  SYSTICK_CounterCmd(SYSTICK_COUNTER_ENABLE);

  DelayTime = nTime;
  while(DelayTime != 0);
  /* Disable SysTick Counter */
  SYSTICK_CounterCmd(SYSTICK_COUNTER_DISABLE);
  /* Clear SysTick Counter */
  SYSTICK_CounterCmd(SYSTICK_COUNTER_CLEAR);
}

/*********************************************************************************************************//**
  * @brief  Decrement the delayTime variable.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_TimingDelay(void)
{
  if(DelayTime != 0x00)
    DelayTime--;
}

/*********************************************************************************************************//**
  * @brief  Initialize peripherals used by the SPI LCD driver.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_Init(void)
{
  SPI_InitTypeDef  SPI_InitStructure;

  /* Enable AFIO ,SPI SEL pin port, SPI BL pin port, SPI RESET pin port & SPI APB clock */
  CKCU_APBPerip0ClockConfig(CKCU_APBEN0_AFIO | DVB_GpioClock[LCD_SPI_SEL_GPIO_ID] | LCD_SPI_CLK |
  DVB_GpioClock[LCD_SPI_BL_GPIO_ID] | DVB_GpioClock[LCD_SPI_RESET_GPIO_ID], ENABLE);

  /* Configure SPI pins, SEL, SCK, MISO ,MOSI, BL & RESET */
  HT32F_DVB_GPxConfig(LCD_SPI_SEL_GPIO_ID, LCD_SPI_SEL_AFIO_PIN, LCD_SPI_SEL_AFIO_MODE);
  HT32F_DVB_GPxConfig(LCD_SPI_SCK_GPIO_ID, LCD_SPI_SCK_AFIO_PIN, LCD_SPI_SCK_AFIO_MODE);
  HT32F_DVB_GPxConfig(LCD_SPI_MISO_GPIO_ID, LCD_SPI_MISO_AFIO_PIN, LCD_SPI_MISO_AFIO_MODE);
  HT32F_DVB_GPxConfig(LCD_SPI_MOSI_GPIO_ID, LCD_SPI_MOSI_AFIO_PIN, LCD_SPI_MOSI_AFIO_MODE);
  HT32F_DVB_GPxConfig(LCD_SPI_BL_GPIO_ID, LCD_SPI_BL_AFIO_PIN, LCD_SPI_BL_AFIO_MODE);
  HT32F_DVB_GPxConfig(LCD_SPI_RESET_GPIO_ID, LCD_SPI_RESET_AFIO_PIN, LCD_SPI_RESET_AFIO_MODE);

  /* Set output data of BL & RESET as high */
  //GPIO_SetOutBits(LCD_SPI_BL_GPIO_PORT, LCD_SPI_BL_GPIO_PIN);
  GPIO_SetOutBits(LCD_SPI_RESET_GPIO_PORT, LCD_SPI_RESET_GPIO_PIN);

  /* Configure the direction of BL & RESET as output mode */
  GPIO_DirectionConfig(LCD_SPI_BL_GPIO_PORT, LCD_SPI_BL_GPIO_PIN, GPIO_DIR_OUT);
  GPIO_DirectionConfig(LCD_SPI_RESET_GPIO_PORT, LCD_SPI_RESET_GPIO_PIN, GPIO_DIR_OUT);

  /* SPI Configuration */
  SPI_InitStructure.SPI_Mode = SPI_MASTER;
  SPI_InitStructure.SPI_FIFO = SPI_FIFO_DISABLE;
  SPI_InitStructure.SPI_DataLength = SPI_DATALENGTH_8;
  SPI_InitStructure.SPI_SELMode = SPI_SEL_SOFTWARE;
  SPI_InitStructure.SPI_SELPolarity = SPI_SELPOLARITY_LOW;
  SPI_InitStructure.SPI_FirstBit = SPI_FIRSTBIT_MSB;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_LOW;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_FIRST;
  SPI_InitStructure.SPI_FirstBit=SPI_FIRSTBIT_MSB;
  SPI_InitStructure.SPI_RxFIFOTriggerLevel = 0;
  SPI_InitStructure.SPI_TxFIFOTriggerLevel = 0;
  SPI_InitStructure.SPI_ClockPrescaler = 2;
  SPI_Init(LCD_SPI, &SPI_InitStructure);

  SPI_SELOutputCmd(LCD_SPI, ENABLE);

  SPI_Cmd(LCD_SPI, ENABLE);

  SPI_LCD_SysTick_Config();
}

/*********************************************************************************************************//**
  * @brief  Configre the LCD by the SPI lcd driver.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_Config(void)
{
  SPI_LCD_delay(10);

  /* RESET LCD */
  GPIO_ClearOutBits(LCD_SPI_RESET_GPIO_PORT, LCD_SPI_RESET_GPIO_PIN);
  SPI_LCD_delay(5);
  GPIO_SetOutBits(LCD_SPI_RESET_GPIO_PORT, LCD_SPI_RESET_GPIO_PIN);
  SPI_LCD_delay(10);

  /* Driving ability Setting*/
  SPI_LCD_WriteReg(0xE2, 0x00);
  SPI_LCD_WriteReg(0xE4, 0x01);
  SPI_LCD_WriteReg(0xE5, 0x10);
  SPI_LCD_WriteReg(0xE6, 0x01);
  SPI_LCD_WriteReg(0xE7, 0x10);
  SPI_LCD_WriteReg(0xE8, 0x70);  // OPON[7:0]
  SPI_LCD_WriteReg(0xF2, 0x00);  // GEN
  SPI_LCD_WriteReg(0xEA, 0x00);  // PTBA[15:8]
  SPI_LCD_WriteReg(0xEB, 0x20);  // PTBA[7:0]
  SPI_LCD_WriteReg(0xEC, 0x3C);  // STBA[15:8]
  SPI_LCD_WriteReg(0xED, 0xC8);  // STBA[7:0]
  SPI_LCD_WriteReg(0xE9, 0x38);  // OPON1[7:0]
  SPI_LCD_WriteReg(0xF1, 0x01);  // OTPS1B
  SPI_LCD_WriteReg(0x2E, 0x89); 
  SPI_LCD_WriteReg(0x29, 0x8F); 
  SPI_LCD_WriteReg(0x2B, 0x02);

  /* Gamma 2.2 Setting */ 
  SPI_LCD_WriteReg(0x40, 0x00); 
  SPI_LCD_WriteReg(0x41, 0x00);
  SPI_LCD_WriteReg(0x42, 0x00);
  SPI_LCD_WriteReg(0x43, 0x15);
  SPI_LCD_WriteReg(0x44, 0x13);
  SPI_LCD_WriteReg(0x45, 0x3f);
  SPI_LCD_WriteReg(0x47, 0x55);
  SPI_LCD_WriteReg(0x48, 0x00);
  SPI_LCD_WriteReg(0x49, 0x12);
  SPI_LCD_WriteReg(0x4A, 0x19);
  SPI_LCD_WriteReg(0x4B, 0x19);
  SPI_LCD_WriteReg(0x4C, 0x16);
  SPI_LCD_WriteReg(0x50, 0x00);
  SPI_LCD_WriteReg(0x51, 0x2c);
  SPI_LCD_WriteReg(0x52, 0x2a);  
  SPI_LCD_WriteReg(0x53, 0x3F);  
  SPI_LCD_WriteReg(0x54, 0x3F);  
  SPI_LCD_WriteReg(0x55, 0x3F);  
  SPI_LCD_WriteReg(0x56, 0x2a);  
  SPI_LCD_WriteReg(0x57, 0x7e);  
  SPI_LCD_WriteReg(0x58, 0x09);  
  SPI_LCD_WriteReg(0x59, 0x06);  
  SPI_LCD_WriteReg(0x5A, 0x06);  
  SPI_LCD_WriteReg(0x5B, 0x0d);  
  SPI_LCD_WriteReg(0x5C, 0x1F);  
  SPI_LCD_WriteReg(0x5D, 0xFF);  

  /* Power Voltage Setting */
  SPI_LCD_WriteReg(0x1B, 0x1A);	 // VREG1
  SPI_LCD_WriteReg(0x1A, 0x02);
  SPI_LCD_WriteReg(0x24, 0x61);
  SPI_LCD_WriteReg(0x25, 0x5C);

  /* VCOM offset */
  SPI_LCD_WriteReg(0x18, 0x36); 
  SPI_LCD_WriteReg(0x19, 0x01); 
  SPI_LCD_WriteReg(0x23, 0x62);  // write_data(0x00,0x62);
  SPI_LCD_WriteReg(0x1F, 0x88);  // GAS=1, VOMG=00, PON=0, DK=1, XDK=0, DVDH_TRI=0, STB=0
  SPI_LCD_delay(5);
  SPI_LCD_WriteReg(0x1F, 0x80);  // GAS=1, VOMG=00, PON=0, DK=0, XDK=0, DVDH_TRI=1, STB=0
  SPI_LCD_delay(5);
  SPI_LCD_WriteReg(0x1F, 0x90);  // GAS=1, VOMG=00, PON=1, DK=0, XDK=0, DVDH_TRI=1, STB=0
  SPI_LCD_delay(5);
  SPI_LCD_WriteReg(0x1F, 0xD4);  // GAS=1, VOMG=10, PON=1, DK=0, XDK=0, DDVDH_TRI=1, STB=0
  SPI_LCD_delay(5);

  /* 262k or 65k color selection */
  SPI_LCD_WriteReg(0x17, 0x05);  // default 0x06 262k color // 0x05 65k color

  /* SET PANEL */
  #ifdef LCD_2_8
  SPI_LCD_WriteReg(0x36,0x09);
  #else
  SPI_LCD_WriteReg(0x36,0x03);   // SS_P, GS_P, REV_P=1, BGR_P
  #endif 

  /* Display ON Setting */
  SPI_LCD_WriteReg(0x28, 0x38);  // GON=1, DTE=1, DV=1000
  SPI_LCD_delay(40);
  SPI_LCD_WriteReg(0x28, 0x3C);  // GON=1, DTE=1, DV=1100

  /* Set GRAM Area */
  SPI_LCD_WriteReg(0x02, 0x00); 
  SPI_LCD_WriteReg(0x03, 0x00);  // DP_STB='0', out deep sleep
  SPI_LCD_WriteReg(0x04, 0x01);  // OSC_EN='1', start Osc
  SPI_LCD_WriteReg(0x05, 0x3F);  // Column End at 320
  SPI_LCD_WriteReg(0x06, 0x00); 
  SPI_LCD_WriteReg(0x07, 0x00);  // Row Start at 0
  SPI_LCD_WriteReg(0x08, 0x00); 
  SPI_LCD_WriteReg(0x09, 0xEF);  // Row End at 240

  /* Show Direction */
  SPI_LCD_WriteReg(0x16,0x60);

  SPI_LCD_Clear(Black);

  SPI_LCD_delay(200);

  /* Turn on the back light */
  GPIO_SetOutBits(LCD_SPI_BL_GPIO_PORT, LCD_SPI_BL_GPIO_PIN);
}

/*********************************************************************************************************//**
  * @brief  Select the LCD register which is to be accessed.
  * @param  LCD_Reg_Index: address of the selected register.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_WriteRegIndex(u8 LCD_Reg_Index)
{
  /* Select the SPI LCD */
  SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_ACTIVE);

  /* Check on LCD_SPI Tx Buffer empty */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_TXBE));
  /* Send command */
  SPI_SendData(LCD_SPI, START_BYTE | SET_INDEX);

  /* Check on LCD_SPI Tx Buffer empty */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_TXBE));
  /* Send number of register */
  SPI_SendData(LCD_SPI, LCD_Reg_Index);

  /* Wait for transmission finished */
  while(SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_BUSY));

  /* Deselect the SPI LCD */
  SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_INACTIVE);
}

/*********************************************************************************************************//**
  * @brief  Write value to the selected LCD register.
  * @param  LCD_Reg_Index: address of the selected register.
  * @param  LCD_Reg_Value: value of to write the selected register.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_WriteReg(u8 LCD_Reg_Index, u16 LCD_Reg_Value)
{
  SPI_LCD_WriteRegIndex(LCD_Reg_Index);

  /* Select the SPI LCD */
  SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_ACTIVE);

  /* Check on LCD_SPI Tx Buffer empty */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_TXBE));
  /* Send command */
  SPI_SendData(LCD_SPI, START_BYTE | LCD_WRITE_REG);

  /* Check on LCD_SPI Tx Buffer empty */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_TXBE));
  /* Send number of register */
  SPI_SendData(LCD_SPI, LCD_Reg_Value >> 8);
  /* Check on LCD_SPI Tx Buffer empty */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_TXBE));
  /* Send number of register */
  SPI_SendData(LCD_SPI, (LCD_Reg_Value & 0xFF));

  /* Wait for transmission finished */
  while(SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_BUSY));

  /* Deselect the SPI LCD */
  SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_INACTIVE);
}

/*********************************************************************************************************//**
  * @brief  Read the selected LCD Register.
  * @param  LCD_Reg_Index: address of the selected register.
  * @retval Value of the selected register.
  ***********************************************************************************************************/
u16 SPI_LCD_ReadReg(u8 LCD_Reg_Index)
{
  u16 tmp = 0;

  SPI_LCD_WriteRegIndex(LCD_Reg_Index);

  /* Select the SPI LCD */
  SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_ACTIVE);

  /* Receive dummy data in Rx & Rx shift */
  SPI_ReceiveData(LCD_SPI);
  SPI_ReceiveData(LCD_SPI);

  /* Check on LCD_SPI Tx Buffer empty */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_TXBE));
  /* Send command */
  SPI_SendData(LCD_SPI, START_BYTE | LCD_READ_REG);
  /* Check on LCD_SPI Rx Buffer data reception */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_RXBNE));
  /* Receive dummy data */
  SPI_ReceiveData(LCD_SPI);

  /* Release the control of MOSI in order to receive data in 3 wire mode */
  AFIO_GPDConfig(LCD_SPI_MOSI_AFIO_PIN, AFIO_MODE_DEFAULT);

  /* Send dummy data in order to receive the data we want */
  SPI_SendData(LCD_SPI, 0xFF);
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_RXBNE));
  tmp = SPI_ReceiveData(LCD_SPI);

  /* Deselect the SPI LCD */
  SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_INACTIVE);

  /* Recover the control of MOSI */
  AFIO_GPDConfig(LCD_SPI_MOSI_AFIO_PIN , LCD_SPI_MOSI_AFIO_MODE);

  return tmp;
}

/*********************************************************************************************************//**
  * @brief  Set the cursor position.
  * @param  X_Location: specify the X position.
  * @param  Y_Location: specify the Y position.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_StarterSet(u16 X_Location, u16 Y_Location)
{
  SPI_LCD_WriteReg(REG6,((X_Location>>8) & 0xff));
  SPI_LCD_WriteReg(REG7,(X_Location & 0xff));       //Column Start

  SPI_LCD_WriteReg(REG2,((Y_Location>>8) & 0xff));
  SPI_LCD_WriteReg(REG3,(Y_Location & 0xff));       //Row Start
}

/*********************************************************************************************************//**
  * @brief  Prepare to write data to LCD RAM.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_WriteRAMPrior(void)
{
  SPI_LCD_WriteRegIndex(REG34);
}

/*********************************************************************************************************//**
  * @brief  Write to the LCD RAM.
  * @param  RGB_Set: the pixel color in RGB mode (5-6-5).
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_WriteRAM(u16 RGB_Set)
{
  /* Select the SPI LCD */
  SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_ACTIVE);

  /* Check on LCD_SPI Tx Buffer empty */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_TXBE));
  /* Send command */
  SPI_SendData(LCD_SPI, START_BYTE | LCD_WRITE_REG);

  /* Check on LCD_SPI Tx Buffer empty */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_TXBE));
  /* Send number of register */
  SPI_SendData(LCD_SPI, RGB_Set >> 8);
  /* Check on LCD_SPI Tx Buffer empty */
  while(!SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_TXBE));
  /* Send number of register */
  SPI_SendData(LCD_SPI, (RGB_Set & 0xFF));

  /* Wait for transmission finished */
  while(SPI_GetFlagStatus(LCD_SPI, SPI_FLAG_BUSY));

  /* Deselect the SPI LCD */
  SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_INACTIVE);
}

/*********************************************************************************************************//**
  * @brief  Clear the whole LCD.
  * @param  Color: the color to be the background.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_Clear(u16 Color)
{
  u32 i = LCD_Height * LCD_Width;

  SPI_LCD_StarterSet(0, 0);

  /* Prepare to write GRAM */
  SPI_LCD_WriteRAMPrior();

  while(i--) SPI_LCD_WriteRAM(Color);
}

/*********************************************************************************************************//**
  * @brief  Set the background color.
  * @param  Color: background color of RGB 5-6-5.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_BackColorSet(u16 Color)
{
  Color_Back = Color;
}

/*********************************************************************************************************//**
  * @brief  Set the text color.
  * @param  Color: text color of RGB 5-6-5.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_TextColorSet(u16 Color)
{
  Color_Text = Color;
}

/*********************************************************************************************************//**
  * @brief  Display one character (16 dots width, 24 dots height).
  * @param  Line_Num: Where to display the character, should be LINE0 ~ LINE9.
  * @param  Column: start column address.
  * @param  Ascii: character ascii code, must be between 0x20 and 0x7E.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_CharDisplay(u8 Line_Num, u16 Column, u8 Ascii)
{
  Ascii -= 32;
  SPI_LCD_CharDraw(Line_Num, Column, &ASCII_Font_Table[Ascii * 24]);
}

/*********************************************************************************************************//**
  * @brief  Disable the Display.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_DisplayOff(void)
{
  /* Display Off */
  SPI_LCD_WriteReg(REG40, 0);
}

/*********************************************************************************************************//**
  * @brief  Enable the Display.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_DisplayOn(void)
{
  /* Display On */
  SPI_LCD_WriteReg(REG40, 0x3C);
}

/*********************************************************************************************************//**
  * @brief  Display the maximum 20 characters on one line.
  * @param  Line_Num: Where to display the character, should be LINE0 ~ LINE9.
  * @param  Sptr: point to the string data.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_StringLineDisplay(u8 Line_Num, char *Sptr)
{
  u32 i = 0;
  u16 reference_column = 0;

  /* Send character by character on LCD */
  while((*Sptr != 0) & (i < 20))
  {
    SPI_LCD_CharDisplay(Line_Num, reference_column, *Sptr);
    /* Increment the column position by 16, because character is size of 16x24 */
    reference_column += 16;
    /* Point to the next character */
    Sptr ++;

    /* Increase the character counter */
    i ++;
  }
}

/*********************************************************************************************************//**
  * @brief  Draw one character.
  * @param  X_Location: the position of display line, should be LINE0 ~ LINE9.
  * @param  Y_Location: the start position of character.
  * @param  Cptr: point to font data of character.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_CharDraw(u8 X_Location, u16 Y_Location, u16 *Cptr)
{
  u8 xid = 0;
  u32 i = 0, j = 0;

  xid = X_Location;
  SPI_LCD_StarterSet(xid, Y_Location);

  for(i = 0; i < Font_Raw; i ++)
  {
    SPI_LCD_WriteRAMPrior();  // Get ready to write GRAM
    for(j = 0; j < Font_Column; j ++)
    {
      if((Cptr[i] & (1 << j)) == 0x00)
      {
        SPI_LCD_WriteRAM(Color_Back);
      }
      else
      {
        SPI_LCD_WriteRAM(Color_Text);
      }
    }
  xid ++;
  SPI_LCD_StarterSet(xid, Y_Location);
  }
}
/*********************************************************************************************************//**
  * @brief  Display a line.
  * @param  X_Location: specify the X position.
  * @param  Y_Location: specify the Y position.
  * @param  Length: line length.
  * @param  Direction: line direction.
  *   This parameter can be one of the following values:
  *     @arg Vertical
  *     @arg Horizontal
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_LineDraw(u8 X_Location, u16 Y_Location, u16 Length, u8 Direction)
{
  u32 i = 0;

  SPI_LCD_StarterSet(X_Location, Y_Location);

  if(Direction == Horizontal)
  {
    SPI_LCD_WriteRAMPrior();  // Get ready to write GRAM
    for(i = 0; i < Length; i ++)
    {
      SPI_LCD_WriteRAM(Color_Text);
    }
  }
  else
  {
    for(i = 0; i < Length; i ++)
    {
      SPI_LCD_WriteRAMWord(Color_Text);
      X_Location++;
      SPI_LCD_StarterSet(X_Location, Y_Location);
    }
  }
}

/*********************************************************************************************************//**
  * @brief  Display a circle.
  * @param  X_Location: specify the X position.
  * @param  Y_Location: specify the Y position.
  * @param  Radius: radius of the circle.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_CircleDraw(u8 X_Location, u16 Y_Location, u16 Radius)
{
  s32  DV;  // Decision Variable
  u32  X_Value;  // Current X Value
  u32  Y_Value;  // Current Y Value

  DV = 3 - (Radius << 1);
  X_Value = 0;
  Y_Value = Radius;

  while(X_Value <= Y_Value)
  {
    SPI_LCD_StarterSet(X_Location + X_Value, Y_Location + Y_Value);
    SPI_LCD_WriteRAMWord(Color_Text);

    SPI_LCD_StarterSet(X_Location + X_Value, Y_Location - Y_Value);
    SPI_LCD_WriteRAMWord(Color_Text);

    SPI_LCD_StarterSet(X_Location - X_Value, Y_Location + Y_Value);
    SPI_LCD_WriteRAMWord(Color_Text);

    SPI_LCD_StarterSet(X_Location - X_Value, Y_Location - Y_Value);
    SPI_LCD_WriteRAMWord(Color_Text);

    SPI_LCD_StarterSet(X_Location + Y_Value, Y_Location + X_Value);
    SPI_LCD_WriteRAMWord(Color_Text);

    SPI_LCD_StarterSet(X_Location + Y_Value, Y_Location - X_Value);
    SPI_LCD_WriteRAMWord(Color_Text);

    SPI_LCD_StarterSet(X_Location - Y_Value, Y_Location + X_Value);
    SPI_LCD_WriteRAMWord(Color_Text);

    SPI_LCD_StarterSet(X_Location - Y_Value, Y_Location - X_Value);
    SPI_LCD_WriteRAMWord(Color_Text);

    if(DV < 0)
    {
      DV += (X_Value << 2) + 6;
    }
    else
    {
      DV += ((X_Value - Y_Value) << 2) + 10;
      Y_Value--;
    }
    X_Value++;
  }
}

/*********************************************************************************************************//**
  * @brief  Draw a rectangle.
  * @param  X_Location: X position.
  * @param  Y_Location: Y position.
  * @param  Height: rectangle height.
  * @param  Width: rectangle width.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_RectDraw(u8 X_Location, u16 Y_Location, u8 Height, u16 Width)
{
  SPI_LCD_LineDraw(X_Location, Y_Location, Width, Horizontal);
  SPI_LCD_LineDraw((X_Location + Height), Y_Location, Width, Horizontal);

  SPI_LCD_LineDraw(X_Location, Y_Location, Height, Vertical);
  SPI_LCD_LineDraw(X_Location, Y_Location + Width - 1, Height, Vertical);
}

/*********************************************************************************************************//**
  * @brief  Draw a picture.
  * @param  X_Location: X position.
  * @param  Y_Location: Y position.
  * @param  Height: rectangle height.
  * @param  Width: rectangle width.
  * @param  Pptr: point to pixel data of picture.
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_PicDraw(u8 X_Location, u16 Y_Location, u8 Height, u16 Width, uc8 *Pptr)
{
    u8 xid = 0;
    u32 ImgAdds = 0;
    u16 yid = 0;
    u32 i = 0, j = 0, color = 0;

    xid = Height + X_Location;
    yid = Y_Location;
    SPI_LCD_StarterSet(xid, yid);

    for(i = 0; i < Height; i++)
    {
      SPI_LCD_WriteRAMPrior();  // Get ready to write GRAM

      for(j = 0; j < Width ; j++)
      {
        ImgAdds = (i*Width*2) + (j*2);

        color = Pptr[ImgAdds] << 8 | (Pptr[ImgAdds + 1] );

        SPI_LCD_WriteRAM(color);
      }
      xid--;
      SPI_LCD_StarterSet(xid, yid);
    }
}
/*********************************************************************************************************//**
  * @brief  Write 1 word to the LCD RAM.
  * @param  RGB_Set: the pixel color in RGB mode (5-6-5).
  * @retval None
  ***********************************************************************************************************/
void SPI_LCD_WriteRAMWord(u16 RGB_Set)
{
  SPI_LCD_WriteRAMPrior();

  SPI_LCD_WriteRAM(RGB_Set);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
