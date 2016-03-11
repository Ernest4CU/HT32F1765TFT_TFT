/*********************************************************************************************************//**
 * @file    spi_flash.h
 * @version V1.0
 * @date    09/08/2011
 * @brief   The header file of spi_flash.c module.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H

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

/** @addtogroup SPI_FLASH SPI_FLASH
  * @{
  */

/* Exported types ------------------------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Exported_Types SPI FLASH exported types
  * @{
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Exported_Constants SPI FLASH exported constants
  * @{
  */
#define SPI_FLASH_CMD_BP                0x02  /* Program one data byte instruction */
#define SPI_FLASH_CMD_AAI               0xAD  /* Auto Address Increment Program instruction */
#define SPI_FLASH_CMD_WRSR              0x01  /* Write Status Register instruction */
#define SPI_FLASH_CMD_WREN              0x06  /* Write enable instruction */
#define SPI_FLASH_CMD_WRDI              0x04  /* Write disable instruction */

#define SPI_FLASH_CMD_READ              0x03  /* Read Data instruction */
#define SPI_FLASH_CMD_RDSR              0x05  /* Read Status Register instruction  */
#define SPI_FLASH_CMD_RDID              0x90  /* Read ID instruction  */
#define SPI_FLASH_CMD_JEDECID           0x9F  /* Read JEDEC ID instruction  */
#define SPI_FLASH_CMD_SE                0x20  /* Sector Erase instruction */
#define SPI_FLASH_CMD_CE                0x60  /* Chip Erase instruction */

#define SPI_FLASH_BUSY_FLAG             0x01  /* Write operation in progress */

#define SPI_FLASH_DUMMY_BYTE            0x00

#define SST25VF016B_FLASH_JEDEC_ID      0xBF2541
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Exported_Macros SPI FLASH exported macros
  * @{
  */
#define SPI_FLASH_SEL_ACTIVE()      GPIO_ClearOutBits(FLASH_SPI_SEL_GPIO_PORT, FLASH_SPI_SEL_GPIO_PIN)

#define SPI_FLASH_SEL_INACTIVE()    GPIO_SetOutBits(FLASH_SPI_SEL_GPIO_PORT, FLASH_SPI_SEL_GPIO_PIN)
/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Exported_Functions SPI FLASH exported functions
  * @{
  */
void SPI_FLASH_Init(void);
void SPI_FLASH_SectorErase(u32 SectorAddr);
void SPI_FLASH_ChipErase(void);
void SPI_FLASH_ByteWrite(u8 DataByte, u32 WriteAddr);
void SPI_FLASH_AAIWrite(u8* WriteBuffer, u32 WriteAddr, u16 NumOfWriteByte);
void SPI_FLASH_BufferWrite(u8* WriteBuffer, u32 WriteAddr, u16 NumOfWriteByte);
void SPI_FLASH_BufferRead(u8* ReadBuffer, u32 ReadAddr, u16 NumOfReadByte);
u32 SPI_FLASH_ReadJEDECID(void);
void SPI_FLASH_WriteStatus(u8 Value);
u8 SPI_FLASH_SendByte(u8 byte);
void SPI_FLASH_WriteEnable(void);
void SPI_FLASH_WriteDisable(void);
void SPI_FLASH_WaitForWriteEnd(void);

#ifdef __cplusplus
}
#endif

/**
  * @}
  */

#endif /* __SPI_FLASH_H ---------------------------------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
