/*********************************************************************************************************//**
 * @file    i2c_eeprom.h
 * @version V1.0
 * @date    09/08/2011
 * @brief   The header file of i2c_eeprom.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/
#ifndef __I2C_EEPROM_H
#define __I2C_EEPROM_H

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

/** @addtogroup I2C_EEPROM I2C_EEPROM
  * @{
  */

/* Exported types ------------------------------------------------------------------------------------------*/

/** @defgroup I2C_EEPROM_Exported_Types I2C EEPROM exported types
  * @{
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/

/** @defgroup I2C_EEPROM_Exported_Constants I2C EEPROM exported constants
  * @{
  */
#define I2C_EEPROM_SPEED         (400000)                                       /*!< I2C speed              */
#define I2C_EEPROM_CAPACITY      (256)                                          /*!< capacity in bytes      */
#define I2C_EEPROM_PAGE_SIZE     (8)                                            /*!< page size in bytes     */
#define I2C_EEPROM_ADDR_MASK     (I2C_EEPROM_CAPACITY - 1)                      /*!< address mask           */
#define I2C_EEPROM_PAGE_MASK     (I2C_EEPROM_PAGE_SIZE - 1)                     /*!< page size mask         */
#define I2C_EEPROM_DEV_ADDR      (0x51)                                         /*!< I2C device address     */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------------------------------------*/

/** @defgroup I2C_EEPROM_Exported_Macros I2C EEPROM exported macros
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/

/** @defgroup I2C_EEPROM_Exported_Functions I2C EEPROM exported functions
  * @{
  */
void I2C_EEPROM_Init(void);
void I2C_EEPROM_PageWrite(u8* pBuffer, u8 WriteAddr, u16 NumByteToWrite);
void I2C_EEPROM_BufferWrite(u8* pBuffer, u8 WriteAddr, u16 NumByteToWrite);
void I2C_EEPROM_BufferRead(u8* pBuffer, u8 ReadAddr, u16 NumByteToRead);
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

#ifdef __cplusplus
}
#endif

#endif /* __I2C_EEPROM_H -----------------------------------------------------------------------------------*/
