/*********************************************************************************************************//**
 * @file    spi_lcd.h
 * @version V1.0
 * @date    09/08/2011
 * @brief   The header file of spi_lcd.c module.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __SPI_LCD_H
#define __SPI_LCD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f1755_2755_dvb.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup HT32F1755_2755_Development_Board
  * @{
  */

/** @addtogroup SPI_LCD SPI_LCD
  * @{
  */

/* Exported types ------------------------------------------------------------------------------------------*/

/** @defgroup SPI_LCD_Exported_Types SPI LCD exported types
  * @{
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/

/** @defgroup SPI_LCD_Exported_Constants SPI LCD exported constants
  * @{
  */

/* LCD Registers */
#define REG0             0x00
#define REG1             0x01
#define REG2             0x02
#define REG3             0x03
#define REG4             0x04
#define REG5             0x05
#define REG6             0x06
#define REG7             0x07
#define REG8             0x08
#define REG9             0x09
#define REG10            0x0A
#define REG12            0x0C
#define REG13            0x0D
#define REG14            0x0E
#define REG15            0x0F
#define REG16            0x10
#define REG17            0x11
#define REG18            0x12
#define REG19            0x13
#define REG20            0x14
#define REG21            0x15
#define REG22            0x16
#define REG23            0x17
#define REG24            0x18
#define REG25            0x19
#define REG26            0x1A
#define REG27            0x1B
#define REG28            0x1C
#define REG29            0x1D
#define REG30            0x1E
#define REG31            0x1F
#define REG32            0x20
#define REG33            0x21
#define REG34            0x22
#define REG36            0x24
#define REG37            0x25
#define REG40            0x28
#define REG41            0x29
#define REG43            0x2B
#define REG45            0x2D
#define REG48            0x30
#define REG49            0x31
#define REG50            0x32
#define REG51            0x33
#define REG52            0x34
#define REG53            0x35
#define REG54            0x36
#define REG55            0x37
#define REG56            0x38
#define REG57            0x39
#define REG59            0x3B
#define REG60            0x3C
#define REG61            0x3D
#define REG62            0x3E
#define REG63            0x3F
#define REG64            0x40
#define REG65            0x41
#define REG66            0x42
#define REG67            0x43
#define REG68            0x44
#define REG69            0x45
#define REG70            0x46
#define REG71            0x47
#define REG72            0x48
#define REG73            0x49
#define REG74            0x4A
#define REG75            0x4B
#define REG76            0x4C
#define REG77            0x4D
#define REG78            0x4E
#define REG79            0x4F
#define REG80            0x50
#define REG81            0x51
#define REG82            0x52
#define REG83            0x53
#define REG96            0x60
#define REG97            0x61
#define REG106           0x6A
#define REG118           0x76
#define REG128           0x80
#define REG129           0x81
#define REG130           0x82
#define REG131           0x83
#define REG132           0x84
#define REG133           0x85
#define REG134           0x86
#define REG135           0x87
#define REG136           0x88
#define REG137           0x89
#define REG139           0x8B
#define REG140           0x8C
#define REG141           0x8D
#define REG143           0x8F
#define REG144           0x90
#define REG145           0x91
#define REG146           0x92
#define REG147           0x93
#define REG148           0x94
#define REG149           0x95
#define REG150           0x96
#define REG151           0x97
#define REG152           0x98
#define REG153           0x99
#define REG154           0x9A
#define REG157           0x9D
#define REG192           0xC0
#define REG193           0xC1
#define REG227           0xE3
#define REG229           0xE5
#define REG231           0xE7
#define REG239           0xEF

/* LCD color */
#define White          0xFFFF
#define Black          0x0000
#define Grey           0xF7DE
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

#define Line0          0
#define Line1          24
#define Line2          48
#define Line3          72
#define Line4          96
#define Line5          120
#define Line6          144
#define Line7          168
#define Line8          192
#define Line9          216

#define Horizontal     0x00
#define Vertical       0x01

#define START_BYTE      0x70
#define SET_INDEX       0x00
#define READ_STATUS     0x01
#define LCD_WRITE_REG   0x02
#define LCD_READ_REG    0x03

#define LCD_Width       320
#define LCD_Height      240 

/**
  * @}
  */
/* Exported functions --------------------------------------------------------------------------------------*/

/** @defgroup SPI_LCD_Exported_Functions SPI LCD exported functions
  * @{
  */
void SPI_LCD_SysTick_Config(void);
void SPI_LCD_delay(u32 nTime);
void SPI_LCD_TimingDelay(void);    
void SPI_LCD_Init(void);
void SPI_LCD_Config(void);
void SPI_LCD_WriteRegIndex(u8 LCD_Reg_Index);
void SPI_LCD_WriteReg(u8 LCD_Reg_Index, u16 LCD_Reg_Value);
u16  SPI_LCD_ReadReg(u8 LCD_Reg_Index);
void SPI_LCD_StarterSet(u16 X_Location, u16 Y_Location);
void SPI_LCD_WriteRAMPrior(void);
void SPI_LCD_WriteRAM(u16 RGB_Set);
void SPI_LCD_Clear(u16 Clocr);
void SPI_LCD_BackColorSet(u16 Color);
void SPI_LCD_TextColorSet(u16 Color);
void SPI_LCD_CharDisplay(u8 Line_Num, u16 Column, u8 Ascii);
void SPI_LCD_DisplayOff(void);
void SPI_LCD_DisplayOn(void);
void SPI_LCD_StringLineDisplay(u8 Line_Number, char *Sptr);
void SPI_LCD_CharDraw(u8 X_Location, u16 Y_Location, u16 *Cptr);
void SPI_LCD_LineDraw(u8 X_Location, u16 Y_Location, u16 Length, u8 Direction);
void SPI_LCD_CircleDraw(u8 X_Location, u16 Y_Location, u16 Radius);
void SPI_LCD_RectDraw(u8 X_Location, u16 Y_Location, u8 Height, u16 Width);
void SPI_LCD_PicDraw(u8 X_Location, u16 Y_Location, u8 Height, u16 Width, uc8 *Cptr);
void SPI_LCD_WriteRAMWord(u16 RGB_Set);

#ifdef __cplusplus
}
#endif

/**
  * @}
  */

#endif /* __SPI_LCD_H ---------------------------------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
