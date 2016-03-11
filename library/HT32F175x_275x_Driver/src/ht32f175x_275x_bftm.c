/*********************************************************************************************************//**
 * @file    ht32f175x_275x_bftm.c
 * @version V1.0
 * @date    11/15/2011
 * @brief   This file provides all the firmware functions about BFTM.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x_bftm.h"
#include "ht32f175x_275x_rstcu.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver HT32F175x/275x Peripheral Driver
  * @{
  */

/** @defgroup BFTM BFTM
  * @brief BFTM driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup BFTM_Private_TypesDefinitions BFTM private types definitions
  * @{
  */

/**
  * @}
  */

/* Private define ------------------------------------------------------------------------------------------*/

/** @defgroup BFTM_Private_Define BFTM private definitions
  * @{
  */

/**
  * @}
  */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup BFTM_Private_Macro BFTM private macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------------------------------------*/

/** @defgroup BFTM_Private_Variable BFTM private variables
  * @{
  */

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup BFTM_Private_Function_Prototype BFTM private function prototypes
  * @{
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup BFTM_Private_Function BFTM private functions
  * @{
  */

/*********************************************************************************************************//**
 * @brief Deinitialize the specified BFTM registers to their default values.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @retval None
 ************************************************************************************************************/
void BFTM_DeInit(BFTM_TypeDef* BFTMx)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));

  if (BFTMx == BFTM0)
  {
    RSTCU_APBPerip1Reset(RSTCU_APBRST1_BFTM0, ENABLE);
  }
  else
  {
    RSTCU_APBPerip1Reset(RSTCU_APBRST1_BFTM1, ENABLE);
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the specified BFTM.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @param NewState: new state of the BFTMx peripheral.
 *        This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void BFTM_EnaCmd(BFTM_TypeDef* BFTMx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    BFTMx->CR |= (1UL << 2);
  }
  else
  {
    BFTMx->CR &= ~(1UL << 2);
  }
}

/*********************************************************************************************************//**
 * @brief Configure the CMP register value of the specified BFTM.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @param wCompare: Specify a value to the CMP register.
 * @retval None
 ************************************************************************************************************/
void BFTM_SetCompare(BFTM_TypeDef* BFTMx, u32 wCompare)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));

  BFTMx->CMP = wCompare;
}

/*********************************************************************************************************//**
 * @brief Get the CMP register value of the specified BFTM.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @retval The value of the CMP register
 ************************************************************************************************************/
u32 BFTM_GetCompare(BFTM_TypeDef* BFTMx)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));

  return BFTMx->CMP;
}

/*********************************************************************************************************//**
 * @brief Set the CNTR register value of the specified BFTM.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @param wCounter: Specify a new value to the CNTR register.
 * @retval None
 ************************************************************************************************************/
void BFTM_SetCounter(BFTM_TypeDef* BFTMx, u32 wCounter)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));

  BFTMx->CNTR = wCounter;
}

/*********************************************************************************************************//**
 * @brief Get the CNTR register value of the specified BFTM.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @retval The value of the CNTR register
 ************************************************************************************************************/
u32 BFTM_GetCounter(BFTM_TypeDef* BFTMx)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));

  return BFTMx->CNTR;
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the one shot mode of the specified BFTM.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @param NewState: new state of the BFTMx one shot mode.
 *        This parameter can be ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void BFTM_OneShotModeCmd(BFTM_TypeDef* BFTMx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if(NewState != DISABLE)
  {
    BFTMx->CR |= (1UL << 1);
  }
  else
  {
    BFTMx->CR &= ~(1UL << 1);
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the specified BFTM interrupt.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @param NewState: new state of the BFTMx interrupt.
 *        This parameter can be ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void BFTM_IntConfig(BFTM_TypeDef* BFTMx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if(NewState != DISABLE)
  {
    BFTMx->CR |= BFTM_INT_MATCH;
  }
  else
  {
    BFTMx->CR &= ~BFTM_INT_MATCH;
  }
}

/*********************************************************************************************************//**
 * @brief Get the flag status of the specified BFTM.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @retval SET or RESET
 ************************************************************************************************************/
FlagStatus BFTM_GetFlagStatus(BFTM_TypeDef* BFTMx)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));

  if (BFTMx->SR & BFTM_FLAG_MATCH)
  {
    return SET;
  }
  else
  {
    return RESET;
  }
}

/*********************************************************************************************************//**
 * @brief Clear the interrupt flag of the specified BFTM.
 * @param BFTMx: where the BFTMx is the selected BFTM peripheral, x can be 0 or 1.
 * @retval None
 ************************************************************************************************************/
void BFTM_ClearFlag(BFTM_TypeDef* BFTMx)
{
  /* Check the parameters */
  Assert_Param(IS_BFTM(BFTMx));

  BFTMx->SR &= ~BFTM_FLAG_MATCH;

  /*--------------------------------------------------------------------------------------------------------*/
  /* DSB instruction is added in this function to ensure the write operation which is for clearing interrupt*/
  /* flag is actually completed before exiting ISR. It prevents the NVIC from detecting the interrupt again */
  /* since the write register operation may be pended in the internal write buffer of Cortex-M3 when program*/
  /* has exited interrupt routine. This DSB instruction may be masked if this function is called in the     */
  /* beginning of ISR and there are still some instructions before exiting ISR.                             */
  /*--------------------------------------------------------------------------------------------------------*/
  __DSB();
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
