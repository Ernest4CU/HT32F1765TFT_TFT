/*********************************************************************************************************//**
 * @file    ht32f175x_275x_bftm.h
 * @version V1.0
 * @date    09/08/2011
 * @brief   The header file of BFTM library.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __HT32F175x_275x_BFTM_H
#define __HT32F175x_275x_BFTM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver
  * @{
  */

/** @addtogroup BFTM
  * @{
  */

/* Exported types ------------------------------------------------------------------------------------------*/

/** @defgroup BFTM_Exported_Types BFTM exported types
  * @{
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/

/** @defgroup BFTM_Exported_Constants BFTM exported constants
  * @{
  */
#define IS_BFTM(x) ((x == BFTM0) || (x == BFTM1))

#define BFTM_FLAG_MATCH           (1UL << 0)
#define BFTM_INT_MATCH            (1UL << 0)

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------------------------------------*/

/** @defgroup BFTM_Exported_Macro BFTM exported macro
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/

/** @defgroup BFTM_Exported_Functions BFTM exported functions
  * @{
  */

void BFTM_DeInit(BFTM_TypeDef* BFTMx);
void BFTM_EnaCmd(BFTM_TypeDef* BFTMx, ControlStatus NewState);
void BFTM_SetCompare(BFTM_TypeDef* BFTMx, u32 wCompare);
u32 BFTM_GetCompare(BFTM_TypeDef* BFTMx);
void BFTM_SetCounter(BFTM_TypeDef* BFTMx, u32 wCounter);
u32 BFTM_GetCounter(BFTM_TypeDef* BFTMx);
void BFTM_OneShotModeCmd(BFTM_TypeDef* BFTMx, ControlStatus NewState);
void BFTM_IntConfig(BFTM_TypeDef* BFTMx, ControlStatus NewState);
FlagStatus BFTM_GetFlagStatus(BFTM_TypeDef* BFTMx);
void BFTM_ClearFlag(BFTM_TypeDef* BFTMx);

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

#endif /* __HT32F175x_275x_BFTM_H --------------------------------------------------------------------------*/
