/*********************************************************************************************************//**
 * @file    ht32f175x_275x_flash.c
 * @version V1.0
 * @date    11/15/2011
 * @brief   This file provides all the firmware functions about FLASH.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x_flash.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver HT32F175x/275x Peripheral Driver
  * @{
  */

/** @defgroup FLASH FLASH
  * @brief FLASH driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup FLASH_Private_TypesDefinitions FLASH private types definitions
  * @{
  */

/**
  * @}
  */

/* Private define ------------------------------------------------------------------------------------------*/

/** @defgroup FLASH_Private_Define FLASH private definitions
  * @{
  */

/* Delay definition */
#define FLASH_TIMEOUT                 (0x000FFFFF)

/* FLASH OCMR */
#define FLASH_CMD_STADNBY             (0x00000000)
#define FLASH_CMD_PROGRAM             (0x00000004)
#define FLASH_CMD_PAGEERASE           (0x00000008)
#define FLASH_CMD_MASSERASE           (0x0000000A)

/* FLASH OPCR */
#define FLASH_READY                   (0x0000000C)
#define FLASH_SEND_MAIN               (0x00000014)

/* FLASH CFCR */
#define CFCR_WAIT_MASK                (0xFFFFFFF8)

#define FLASH_PREFETCHBUF_ON          (0x00000010)
#define FLASH_PREFETCHBUF_OFF         (0xFFFFFFEF)

#define FLASH_BRANCHCACHE_ON          (0x00001000)
#define FLASH_BRANCHCACHE_OFF         (0xFFFFEFFF)

#define FLASH_DCODECACHE_ON           (0xFFFFFF7F)
#define FLASH_DCODECACHE_OFF          (0x00000080)

#define FLASH_HALFCYCLE_ON            (0x00008000)
#define FLASH_HALFCYCLE_OFF           (0xFFFF7FFF)

#define FLASH_ZWPWRSAVING_ON          (0x00010000)
#define FLASH_ZWPWRSAVING_OFF         (0xFFFEFFFF)

/**
  * @}
  */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup FLASH_Private_Macro FLASH private macros
  * @{
  */

/**
 * @brief Check parameter of the FLASH wait state.
 */
#define IS_FLASH_WAITSTATE(WAIT)      ((WAIT == FLASH_WAITSTATE_0) || \
                                       (WAIT == FLASH_WAITSTATE_1) || \
                                       (WAIT == FLASH_WAITSTATE_2))

/**
 * @brief Check parameter of the FLASH vector mapping.
 */
#define IS_FLASH_VECTOR_MODE(MODE)          ((MODE == FLASH_BOOT_LOADER) || \
                                             (MODE == FLASH_BOOT_SRAM)   || \
                                             (MODE == FLASH_BOOT_MAIN))

/**
 * @brief Check parameter of the FLASH address.
 */
#define IS_FLASH_ADDRESS(ADDRESS)     (ADDRESS < 0x20000000)  /* Code 0.5GB Area */

/**
 * @brief Check parameter of the FLASH page 0 to 31.
 */
#define IS_FLASH_PAGE0TO31(PAGES)     (PAGES != 0)

/**
 * @brief Check parameter of the FLASH page 32 to 63.
 */
#define IS_FLASH_PAGE32TO63(PAGES)    (PAGES != 0)

/**
 * @brief Check parameter of the FLASH page 64 to 95.
 */
#define IS_FLASH_PAGE64TO95(PAGES)    (PAGES != 0)

/**
 * @brief Check parameter of the FLASH page 96 to 126.
 */
#define IS_FLASH_PAGE96TO126(PAGES)   ((PAGES != 0) && ((PAGES & 0x80000000) != 0x80000000))

/**
 * @brief Check parameter of the FLASH security.
 */
#define IS_FLASH_SECURITY(TYPE)       ((TYPE == FLASH_SEC_OB)   || \
                                       (TYPE == FLASH_SEC_MAIN) || \
                                       (TYPE == FLASH_SEC_BOTH))

/**
 * @brief Check parameter of the FLASH interrupt status.
 */
#define IS_FLASH_WC_FLAG(FLAG)        ((FLAG & 0x0000001F) != 0)

/**
 * @brief Check parameter of the FLASH interrupt flag.
 */
#define IS_FLASH_FLAG(FLAG)           ((FLAG & 0x0003001F) != 0)

/**
 * @brief Check parameter of the FLASH interrupt.
 */
#define IS_FLASH_INT(IT)              ((IT & 0x0000001F) != 0)

/**
  * @}
  */

/* Private variables ---------------------------------------------------------------------------------------*/

/** @defgroup FLASH_Private_Variable FLASH private variables
  * @{
  */

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup FLASH_Private_Function_Prototype FLASH private function prototypes
  * @{
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup FLASH_Private_Function FLASH private functions
  * @{
  */

/*********************************************************************************************************//**
 * @brief Configure the FLASH wait state.
 * @param FLASH_WaitState: Setting of FLASH wait state.
 *        This parameter can be:
 *        @arg FLASH_WAITSTATE_0: zero wait state.
 *        @arg FLASH_WAITSTATE_1: one wait state.
 *        @arg FLASH_WAITSTATE_2: two wait state.
 * @retval None
 ************************************************************************************************************/
void FLASH_SetWaitState(u32 FLASH_WaitState)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_WAITSTATE(FLASH_WaitState));

  FLASH->CFCR = (FLASH->CFCR & CFCR_WAIT_MASK) | FLASH_WaitState;
}

/*********************************************************************************************************//**
 * @brief Enable or Disable FLASH pre-fetch buffer.
 * @param NewState: new state of the FLASH pre-fetch buffer.
 *        This parameter can be: ENABLE or DISABLE
 * @retval None
 ************************************************************************************************************/
void FLASH_PrefetchBufferCmd(ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    FLASH->CFCR |= FLASH_PREFETCHBUF_ON;
  }
  else
  {
    FLASH->CFCR &= FLASH_PREFETCHBUF_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable FLASH DCODE cache mode.
 * @param NewState: new state of the FLASH DCODE cache.
 *        This parameter can be: ENABLE or DISABLE
 * @retval None
 ************************************************************************************************************/
void FLASH_DcodeCacheCmd(ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    FLASH->CFCR &= FLASH_DCODECACHE_ON;
  }
  else
  {
    FLASH->CFCR |= FLASH_DCODECACHE_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable FLASH branch cache.
 * @param NewState: new state of the FLASH branch cache.
 *        This parameter can be: ENABLE or DISABLE
 * @retval None
 ************************************************************************************************************/
void FLASH_BranchCacheCmd(ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    FLASH->CFCR |= FLASH_BRANCHCACHE_ON;
  }
  else
  {
    FLASH->CFCR &= FLASH_BRANCHCACHE_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable FLASH half cycle access.
 * @param NewState: new state of the FLASH half cycle access.
 *        This parameter can be: ENABLE or DISABLE
 * @retval ERROR or SUCCESS
 ************************************************************************************************************/
ErrStatus FLASH_FlashHalfCycleCmd(ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if ((FLASH->CFCR & ~CFCR_WAIT_MASK) == FLASH_WAITSTATE_0)
  {
    if (NewState != DISABLE)
    {
      FLASH->CFCR |= FLASH_HALFCYCLE_ON;
    }
    else
    {
      FLASH->CFCR &= FLASH_HALFCYCLE_OFF;
    }

    return SUCCESS;
  }

  return ERROR;
}

/*********************************************************************************************************//**
 * @brief Enable or Disable FLASH zero wait state power saving.
 * @param NewState: new state of the FLASH zero wait state power saving.
 *        This parameter can be: ENABLE or DISABLE
 * @retval ERROR or SUCCESS
 ************************************************************************************************************/
ErrStatus FLASH_FlashZwPwrSavingCmd(ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if ((FLASH->CFCR & ~CFCR_WAIT_MASK) == FLASH_WAITSTATE_0)
  {
    if (NewState != DISABLE)
    {
      FLASH->CFCR |= FLASH_ZWPWRSAVING_ON;
    }
    else
    {
      FLASH->CFCR &= FLASH_ZWPWRSAVING_OFF;
    }

    return SUCCESS;
  }

  return ERROR;
}

/*********************************************************************************************************//**
 * @brief Set vector remapping mode.
 * @param RemapMode: Booting mode.
 *        This parameter can be:
 *        @arg FLASH_BOOT_LOADER: Boot loader mode.
 *        @arg FLASH_BOOT_SRAM  : SRAM booting mode.
 *        @arg FLASH_BOOT_MAIN  : Main FLASH mode.
 * @retval None
 ************************************************************************************************************/
void FLASH_SetRemappingMode(FLASH_Vector RemapMode)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_VECTOR_MODE(RemapMode));

  FLASH->VMCR = RemapMode;
}

/*********************************************************************************************************//**
 * @brief Erase a specific FLASH page.
 * @param PageAddress: Address of the erased page.
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_ErasePage(u32 PageAddress)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_ADDRESS(PageAddress));

  FLASH->TADR = PageAddress;
  FLASH->OCMR = FLASH_CMD_PAGEERASE;
  FLASH->OPCR = FLASH_SEND_MAIN;

  return FLASH_WaitForOperationEnd();
}

/*********************************************************************************************************//**
 * @brief Erase FLASH Option Byte page.
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT, FLASH_ERR_WRITE_PROTECTED
 ************************************************************************************************************/
FLASH_State FLASH_EraseOptionByte(void)
{
  /*!< Check the write protection status of Option Byte */
  if ((FLASH_Security)(~FLASH_GetSecurityStatus()) >= FLASH_SEC_OB)
  {
    return FLASH_ERR_WRITE_PROTECTED;
  }

  FLASH->TADR = OPTION_BYTE_BASE;
  FLASH->OCMR = FLASH_CMD_PAGEERASE;
  FLASH->OPCR = FLASH_SEND_MAIN;

  return FLASH_WaitForOperationEnd();
}

/*********************************************************************************************************//**
 * @brief Erase the entire FLASH.
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_MassErase(void)
{
  FLASH->OCMR = FLASH_CMD_MASSERASE;
  FLASH->OPCR = FLASH_SEND_MAIN;

  return FLASH_WaitForOperationEnd();
}

/*********************************************************************************************************//**
 * @brief Program one word data.
 * @param Address: The specific FLASH address to be programmed.
 * @param Data: The specific FLASH data to be programmed.
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_ProgramWordData(u32 Address, u32 Data)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_ADDRESS(Address));

  FLASH->TADR = Address;
  FLASH->WRDR = Data;
  FLASH->OCMR = FLASH_CMD_PROGRAM;
  FLASH->OPCR = FLASH_SEND_MAIN;

  return FLASH_WaitForOperationEnd();
}

/*********************************************************************************************************//**
 * @brief Enable write-protection for FLASH page 0 to 31.
 * @param FLASH_Pages: The specific pages to be write-protected.
 *        This parameter can be:
 *        @arg FLASH_WP_PAGE00 ~ FLASH_WP_PAGE31
 *        @arg FLASH_WP_ALLPAGES
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_EnablePage0to31WriteProtection(u32 FLASH_Pages)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_PAGE0TO31(FLASH_Pages));

  return FLASH_ProgramWordData(OB_PP0, ~FLASH_Pages);
}

/*********************************************************************************************************//**
 * @brief Enable write-protection for FLASH page 32 to 63.
 * @param FLASH_Pages: The specific pages to be write-protected.
 *        This parameter can be:
 *        @arg FLASH_WP_PAGE32 ~ FLASH_WP_PAGE63
 *        @arg FLASH_WP_ALLPAGES
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_EnablePage32to63WriteProtection(u32 FLASH_Pages)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_PAGE32TO63(FLASH_Pages));

  return FLASH_ProgramWordData(OB_PP1, ~FLASH_Pages);
}

/*********************************************************************************************************//**
 * @brief Enable write-protection for FLASH page 64 to 95.
 * @param FLASH_Pages: The specific pages to be write-protected.
 *        This parameter can be:
 *        @arg FLASH_WP_PAGE64 ~ FLASH_WP_PAGE95
 *        @arg FLASH_WP_ALLPAGES
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_EnablePage64to95WriteProtection(u32 FLASH_Pages)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_PAGE64TO95(FLASH_Pages));

  return FLASH_ProgramWordData(OB_PP2, ~FLASH_Pages);
}

/*********************************************************************************************************//**
 * @brief Enable write-protection for FLASH page 96 to 126.
 * @param FLASH_Pages: The specific pages to be write-protected.
 *        This parameter can be:
 *        @arg FLASH_WP_PAGE96 ~ FLASH_WP_PAGE126
 *        @arg FLASH_WP_ALLPAGES
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_EnablePage96to126WriteProtection(u32 FLASH_Pages)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_PAGE96TO126(FLASH_Pages));

  return FLASH_ProgramWordData(OB_PP3, ~FLASH_Pages);
}

/*********************************************************************************************************//**
 * @brief Enable security lock for the option byte or the page of main FLASH.
 * @param SecurityType: The security lock type.
 *        This parameter can be:
 *        @arg FLASH_SEC_MAIN: Main FLASH lock.
 *        @arg FLASH_SEC_OB: Option Byte Page lock.
 *        @arg FLASH_SEC_BOTH: Both Page lock of the Main FLASH and Option Byte.
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_EnableSecurity(FLASH_Security SecurityType)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_SECURITY(SecurityType));

  return FLASH_ProgramWordData(OB_CP, ~SecurityType);
}

/*********************************************************************************************************//**
 * @brief Set the Option Byte Checksum.
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_SetOptionByteChecksum(void)
{
  u32 checksum;

  if ((rw(OB_PP0) == 0xFFFFFFF) && (rw(OB_PP1) == 0xFFFFFFF) && (rw(OB_PP2) == 0xFFFFFFF) &&
      (rw(OB_PP3) == 0xFFFFFFF) && (rw(OB_CP) == 0xFFFFFFF))
  {
    checksum = 0xFFFFFFFF;
  }
  else
  {
    checksum = rw(OB_PP0);
    checksum += rw(OB_PP1);
    checksum += rw(OB_PP2);
    checksum += rw(OB_PP3);
    checksum += rw(OB_CP);
  }

  return FLASH_ProgramWordData(OB_CHECKSUM, checksum);
}

/*********************************************************************************************************//**
 * @brief Return write-protection status of FLASH page 0 to 31.
 * @retval Write-protection status of the FLASH.
 ************************************************************************************************************/
u32 FLASH_GetPage0to31WriteProtectionStatus(void)
{
  return (FLASH->PPSR[0]);
}

/*********************************************************************************************************//**
 * @brief Get write-protection status of FLASH page 32 to 63.
 * @retval Write-protection status of the FLASH.
 ************************************************************************************************************/
u32 FLASH_GetPage32to63WriteProtectionStatus(void)
{
  return (FLASH->PPSR[1]);
}

/*********************************************************************************************************//**
 * @brief Get write-protection status of FLASH page 64 to 95.
 * @retval Write-protection status of the FLASH.
 ************************************************************************************************************/
u32 FLASH_GetPage64to95WriteProtectionStatus(void)
{
  return (FLASH->PPSR[2]);
}

/*********************************************************************************************************//**
 * @brief Get write-protection status of FLASH page 96 to 126.
 * @retval Write-protection status of the FLASH.
 ************************************************************************************************************/
u32 FLASH_GetPage96to126WriteProtectionStatus(void)
{
  return (FLASH->PPSR[3]);
}

/*********************************************************************************************************//**
 * @brief Return security status of the FLASH.
 * @retval Security status of the FLASH.
 ************************************************************************************************************/
u32 FLASH_GetSecurityStatus(void)
{
  return (FLASH->CPSR);
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the specific FLASH interrupts.
 * @param FLASH_INT: The specific FLASH interrupt.
 *        This parameter can be:
 *        @arg FLASH_INT_ORFIE, FLASH_INT_ITADIE, FLASH_INT_OBEIE, FLASH_INT_IOCMIE,
 *             FLASH_INT_OREIE, FLASH_INT_ALL.
 * @param Cmd: The status of the FLASH interrupt.
 *        This parameter can be:
 *        @arg DISABLE, ENABLE
 * @retval None
 ************************************************************************************************************/
void FLASH_IntConfig(u32 FLASH_INT, ControlStatus Cmd)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_INT(FLASH_INT));
  Assert_Param(IS_CONTROL_STATUS(Cmd));

  if (Cmd != DISABLE)
  {
    /* Enable the interrupt sources */
    FLASH->OIER |= FLASH_INT;
  }
  else
  {
    /* Disable the interrupt sources */
    FLASH->OIER &= ~FLASH_INT;
  }
}

/*********************************************************************************************************//**
 * @brief Return flag status of the FLASH interrupt.
 * @param FLASH_FLAG: Flag of the FLASH interrupt.
 *        This parameter can be:
 *        @arg FLASH_FLAG_OREF, FLASH_FLAG_IOCMF, FLASH_FLAG_OBEF, FLASH_FLAG_ITADF, FLASH_FLAG_ORFF,
 *             FLASH_FLAG_PPERF, FLASH_FLAG_RORFF
 * @retval SET or RESET
 ************************************************************************************************************/
FlagStatus FLASH_GetIntStatus(u32 FLASH_FLAG)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_FLAG(FLASH_FLAG));

  if ((FLASH->OISR & FLASH_FLAG) != (u32)RESET)
  {
    return SET;
  }
  else
  {
    return RESET;
  }
}

/*********************************************************************************************************//**
 * @brief Clear specific interrupt flags of FLASH.
 * @param FLASH_FLAG: interrupt flag of FLASH.
 *        This parameter can be:
 *        @arg FLASH_FLAG_OREF, FLASH_FLAG_IOCMF, FLASH_FLAG_OBEF, FLASH_FLAG_ITADF, FLASH_FLAG_ORFF
 * @retval None
 ************************************************************************************************************/
void FLASH_ClearIntFlag(u32 FLASH_FLAG)
{
  /* Check the parameters */
  Assert_Param(IS_FLASH_WC_FLAG(FLASH_FLAG));

  /* Clear the flags */
  FLASH->OISR = FLASH_FLAG;
}

/*********************************************************************************************************//**
 * @brief Wait untill the FLASH operation has finished or time-out has occurred.
 * @retval FLASH_COMPLETE, FLASH_TIME_OUT
 ************************************************************************************************************/
FLASH_State FLASH_WaitForOperationEnd(void)
{
  u32 Timeout = FLASH_TIMEOUT;

  /* Waits till the FLASH operation has finished or time-out has occurred */
  while (Timeout--)
  {
    if ((FLASH->OPCR & FLASH_READY) == FLASH_READY)
    {
      return FLASH_COMPLETE;
    }
  }

  return FLASH_TIME_OUT;
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
