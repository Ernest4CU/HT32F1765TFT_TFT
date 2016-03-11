/*********************************************************************************************************//**
 * @file    ht32f175x_275x_flash.h
 * @version V1.0
 * @date    11/15/2011
 * @brief   The header file of the Flash Control library.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __HT32F175x_275x_FLASH_H
#define __HT32F175x_275x_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */

/* Exported types ------------------------------------------------------------------------------------------*/

/** @defgroup FLASH_Exported_Types FLASH exported types
  * @{
  */

/**
 * @brief  Enumeration of FLASH return status.
 */
typedef enum
{
  FLASH_COMPLETE              = 0,
  FLASH_BUSY                  = 1,
  FLASH_ERR_ADDR_OUT_OF_RANGE = 2,
  FLASH_ERR_COMMAND           = 3,
  FLASH_ERR_WRITE_PROTECTED   = 4,
  FLASH_ERR_PROGRAM           = 5,
  FLASH_ERR_ERASE             = 6,
  FLASH_ERR_ERROR             = 7,
  FLASH_TIME_OUT              = 8
}FLASH_State;

/**
 * @brief  Enumeration of FLASH security status.
 */
typedef enum
{
  FLASH_SEC_DISABLE = 0x00000000,
  FLASH_SEC_MAIN    = 0x00000001,
  FLASH_SEC_OB      = 0x00000002,
  FLASH_SEC_BOTH    = 0x00000003
}FLASH_Security;

/**
 * @brief  Enumeration of FLASH boot mode.
 */
typedef enum
{
  FLASH_BOOT_SRAM   = 0x00000000,
  FLASH_BOOT_LOADER = 0x00000001,
  FLASH_BOOT_MAIN   = 0x00000002
}FLASH_Vector;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/

/** @defgroup FLASH_Exported_Constants FLASH exported constants
  * @{
  */

/* Flash Information                                                                                        */
#define FLASH_PAGE_SIZE               (0x00000400)   /* Flash page size (1K)                                */

/* Flash Wait State                                                                                         */
#define FLASH_WAITSTATE_0             (0x00000001)   /* FLASH zero latency cycle                            */
#define FLASH_WAITSTATE_1             (0x00000002)   /* FLASH one latency cycle                             */
#define FLASH_WAITSTATE_2             (0x00000003)   /* FLASH two latency cycle                             */

/* FLASH OISR Flags                                                                                         */
#define FLASH_FLAG_ORFF               (0x00000001)   /* Operation Finished Flag                             */
#define FLASH_FLAG_ITADF              (0x00000002)   /* Invalid Target Address Flag                         */
#define FLASH_FLAG_OBEF               (0x00000004)   /* Option Byte Check Sum Error Flag                    */
#define FLASH_FLAG_IOCMF              (0x00000008)   /* Invalid Operation Command Flag                      */
#define FLASH_FLAG_OREF               (0x00000010)   /* Operation Error Flag                                */
#define FLASH_FLAG_RORFF              (0x00010000)   /* Raw Operation Finished Flag                         */
#define FLASH_FLAG_PPEF               (0x00020000)   /* Page Erase/Program Protected Error Flag             */

/* FLASH OIER                                                                                               */
#define FLASH_INT_ORFIEN              (0x00000001)   /* Flash Operation Finished Interrupt Enable           */
#define FLASH_INT_ITADIEN             (0x00000002)   /* Invalid Target Address Interrupt Enable             */
#define FLASH_INT_OBEIEN              (0x00000004)   /* Option Byte Checksum Error Interrupt Enable         */
#define FLASH_INT_IOCMIEN             (0x00000008)   /* Invalid Operation Command Interrupt Enable          */
#define FLASH_INT_OREIEN              (0x00000010)   /* Operation Error Interrupt Enable                    */
#define FLASH_INT_ALL                 (0x0000001F)   /* Flash all Interrupt Enable                          */

/* Option Bytes Address                                                                                     */
#define OPTION_BYTE_BASE              (0x1FF00000)   /* Option Byte Base Address                            */
#define OB_PP0                        (0x1FF00000)   /* Option Byte: Write Protection 0                     */
#define OB_PP1                        (0x1FF00004)   /* Option Byte: Write Protection 1                     */
#define OB_PP2                        (0x1FF00008)   /* Option Byte: Write Protection 2                     */
#define OB_PP3                        (0x1FF0000C)   /* Option Byte: Write Protection 3                     */
#define OB_CP                         (0x1FF00010)   /* Option Byte: Secutity Protection                    */
#define OB_CHECKSUM                   (0x1FF00020)   /* Option Byte: Checksum                               */

/* Flash Write Protection Page Mask                                                                         */
#define FLASH_WP_PAGE00               (0x00000001)
#define FLASH_WP_PAGE01               (0x00000002)
#define FLASH_WP_PAGE02               (0x00000004)
#define FLASH_WP_PAGE03               (0x00000008)
#define FLASH_WP_PAGE04               (0x00000010)
#define FLASH_WP_PAGE05               (0x00000020)
#define FLASH_WP_PAGE06               (0x00000040)
#define FLASH_WP_PAGE07               (0x00000080)
#define FLASH_WP_PAGE08               (0x00000100)
#define FLASH_WP_PAGE09               (0x00000200)
#define FLASH_WP_PAGE10               (0x00000400)
#define FLASH_WP_PAGE11               (0x00000800)
#define FLASH_WP_PAGE12               (0x00001000)
#define FLASH_WP_PAGE13               (0x00002000)
#define FLASH_WP_PAGE14               (0x00004000)
#define FLASH_WP_PAGE15               (0x00008000)
#define FLASH_WP_PAGE16               (0x00010000)
#define FLASH_WP_PAGE17               (0x00020000)
#define FLASH_WP_PAGE18               (0x00040000)
#define FLASH_WP_PAGE19               (0x00080000)
#define FLASH_WP_PAGE20               (0x00100000)
#define FLASH_WP_PAGE21               (0x00200000)
#define FLASH_WP_PAGE22               (0x00400000)
#define FLASH_WP_PAGE23               (0x00800000)
#define FLASH_WP_PAGE24               (0x01000000)
#define FLASH_WP_PAGE25               (0x02000000)
#define FLASH_WP_PAGE26               (0x04000000)
#define FLASH_WP_PAGE27               (0x08000000)
#define FLASH_WP_PAGE28               (0x10000000)
#define FLASH_WP_PAGE29               (0x20000000)
#define FLASH_WP_PAGE30               (0x40000000)
#define FLASH_WP_PAGE31               (0x80000000)

#define FLASH_WP_PAGE32               (0x00000001)
#define FLASH_WP_PAGE33               (0x00000002)
#define FLASH_WP_PAGE34               (0x00000004)
#define FLASH_WP_PAGE35               (0x00000008)
#define FLASH_WP_PAGE36               (0x00000010)
#define FLASH_WP_PAGE37               (0x00000020)
#define FLASH_WP_PAGE38               (0x00000040)
#define FLASH_WP_PAGE39               (0x00000080)
#define FLASH_WP_PAGE40               (0x00000100)
#define FLASH_WP_PAGE41               (0x00000200)
#define FLASH_WP_PAGE42               (0x00000400)
#define FLASH_WP_PAGE43               (0x00000800)
#define FLASH_WP_PAGE44               (0x00001000)
#define FLASH_WP_PAGE45               (0x00002000)
#define FLASH_WP_PAGE46               (0x00004000)
#define FLASH_WP_PAGE47               (0x00008000)
#define FLASH_WP_PAGE48               (0x00010000)
#define FLASH_WP_PAGE49               (0x00020000)
#define FLASH_WP_PAGE50               (0x00040000)
#define FLASH_WP_PAGE51               (0x00080000)
#define FLASH_WP_PAGE52               (0x00100000)
#define FLASH_WP_PAGE53               (0x00200000)
#define FLASH_WP_PAGE54               (0x00400000)
#define FLASH_WP_PAGE55               (0x00800000)
#define FLASH_WP_PAGE56               (0x01000000)
#define FLASH_WP_PAGE57               (0x02000000)
#define FLASH_WP_PAGE58               (0x04000000)
#define FLASH_WP_PAGE59               (0x08000000)
#define FLASH_WP_PAGE60               (0x10000000)
#define FLASH_WP_PAGE61               (0x20000000)
#define FLASH_WP_PAGE62               (0x40000000)
#define FLASH_WP_PAGE63               (0x80000000)

#define FLASH_WP_PAGE64               (0x00000001)
#define FLASH_WP_PAGE65               (0x00000002)
#define FLASH_WP_PAGE66               (0x00000004)
#define FLASH_WP_PAGE67               (0x00000008)
#define FLASH_WP_PAGE68               (0x00000010)
#define FLASH_WP_PAGE69               (0x00000020)
#define FLASH_WP_PAGE70               (0x00000040)
#define FLASH_WP_PAGE71               (0x00000080)
#define FLASH_WP_PAGE72               (0x00000100)
#define FLASH_WP_PAGE73               (0x00000200)
#define FLASH_WP_PAGE74               (0x00000400)
#define FLASH_WP_PAGE75               (0x00000800)
#define FLASH_WP_PAGE76               (0x00001000)
#define FLASH_WP_PAGE77               (0x00002000)
#define FLASH_WP_PAGE78               (0x00004000)
#define FLASH_WP_PAGE79               (0x00008000)
#define FLASH_WP_PAGE80               (0x00010000)
#define FLASH_WP_PAGE81               (0x00020000)
#define FLASH_WP_PAGE82               (0x00040000)
#define FLASH_WP_PAGE83               (0x00080000)
#define FLASH_WP_PAGE84               (0x00100000)
#define FLASH_WP_PAGE85               (0x00200000)
#define FLASH_WP_PAGE86               (0x00400000)
#define FLASH_WP_PAGE87               (0x00800000)
#define FLASH_WP_PAGE88               (0x01000000)
#define FLASH_WP_PAGE89               (0x02000000)
#define FLASH_WP_PAGE90               (0x04000000)
#define FLASH_WP_PAGE91               (0x08000000)
#define FLASH_WP_PAGE92               (0x10000000)
#define FLASH_WP_PAGE93               (0x20000000)
#define FLASH_WP_PAGE94               (0x40000000)
#define FLASH_WP_PAGE95               (0x80000000)

#define FLASH_WP_PAGE96               (0x00000001)
#define FLASH_WP_PAGE97               (0x00000002)
#define FLASH_WP_PAGE98               (0x00000004)
#define FLASH_WP_PAGE99               (0x00000008)
#define FLASH_WP_PAGE100              (0x00000010)
#define FLASH_WP_PAGE101              (0x00000020)
#define FLASH_WP_PAGE102              (0x00000040)
#define FLASH_WP_PAGE103              (0x00000080)
#define FLASH_WP_PAGE104              (0x00000100)
#define FLASH_WP_PAGE105              (0x00000200)
#define FLASH_WP_PAGE106              (0x00000400)
#define FLASH_WP_PAGE107              (0x00000800)
#define FLASH_WP_PAGE108              (0x00001000)
#define FLASH_WP_PAGE109              (0x00002000)
#define FLASH_WP_PAGE110              (0x00004000)
#define FLASH_WP_PAGE111              (0x00008000)
#define FLASH_WP_PAGE112              (0x00010000)
#define FLASH_WP_PAGE113              (0x00020000)
#define FLASH_WP_PAGE114              (0x00040000)
#define FLASH_WP_PAGE115              (0x00080000)
#define FLASH_WP_PAGE116              (0x00100000)
#define FLASH_WP_PAGE117              (0x00200000)
#define FLASH_WP_PAGE118              (0x00400000)
#define FLASH_WP_PAGE119              (0x00800000)
#define FLASH_WP_PAGE120              (0x01000000)
#define FLASH_WP_PAGE121              (0x02000000)
#define FLASH_WP_PAGE122              (0x04000000)
#define FLASH_WP_PAGE123              (0x08000000)
#define FLASH_WP_PAGE124              (0x10000000)
#define FLASH_WP_PAGE125              (0x20000000)
#define FLASH_WP_PAGE126              (0x40000000)

#define FLASH_WP_ALLPAGES             (0xFFFFFFFF)

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------------------------------------*/

/** @defgroup FLASH_Exported_Macro FLASH exported macro
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/

/** @defgroup FLASH_Exported_Functions FLASH exported functions
  * @{
  */

void FLASH_SetWaitState(u32 FLASH_WaitState);
void FLASH_PrefetchBufferCmd(ControlStatus NewState);
void FLASH_DcodeCacheCmd(ControlStatus NewState);
void FLASH_BranchCacheCmd(ControlStatus NewState);
ErrStatus FLASH_FlashHalfCycleCmd(ControlStatus NewState);
ErrStatus FLASH_FlashZwPwrSavingCmd(ControlStatus NewState);
void FLASH_SetRemappingMode(FLASH_Vector RemapMode);
FLASH_State FLASH_ErasePage(u32 PageAddress);
FLASH_State FLASH_EraseOptionByte(void);
FLASH_State FLASH_MassErase(void);
FLASH_State FLASH_ProgramWordData(u32 Address, u32 Data);
FLASH_State FLASH_EnablePage0to31WriteProtection(u32 FLASH_Pages);
FLASH_State FLASH_EnablePage32to63WriteProtection(u32 FLASH_Pages);
FLASH_State FLASH_EnablePage64to95WriteProtection(u32 FLASH_Pages);
FLASH_State FLASH_EnablePage96to126WriteProtection(u32 FLASH_Pages);
FLASH_State FLASH_EnableSecurity(FLASH_Security SecurityMode);
FLASH_State FLASH_SetOptionByteChecksum(void);
u32 FLASH_GetPage0to31WriteProtectionStatus(void);
u32 FLASH_GetPage32to63WriteProtectionStatus(void);
u32 FLASH_GetPage64to95WriteProtectionStatus(void);
u32 FLASH_GetPage96to126WriteProtectionStatus(void);
u32 FLASH_GetSecurityStatus (void);
void FLASH_IntConfig(u32 FLASH_INT, ControlStatus Cmd);
FlagStatus FLASH_GetIntStatus(u32 FLASH_FLAG);
void FLASH_ClearIntFlag(u32 FLASH_FLAG);
FLASH_State FLASH_WaitForOperationEnd(void);

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

#endif /* __HT32F175x_275x_FLASH_H -------------------------------------------------------------------------*/
