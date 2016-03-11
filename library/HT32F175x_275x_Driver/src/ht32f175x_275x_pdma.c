/*********************************************************************************************************//**
 * @file    ht32f175x_275x_pdma.c
 * @version V1.0
 * @date    09/08/2011
 * @brief   The file provides all the PDMA firmware functions.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x_pdma.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver HT32F175x/275x Peripheral Driver
  * @{
  */

/** @defgroup PDMA PDMA
  * @brief PDMA driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup PDMA_Private_TypesDefinitions PDMA private types definitions
  * @{
  */

/**
  * @}
  */  /* End of PDMA_Private_TypesDefinitions group */

/* Private define ------------------------------------------------------------------------------------------*/

/** @defgroup PDMA_Private_Define PDMA private definitions
  * @{
  */

/**
  * @}
  */  /* End of PDMA_Private_Define group */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup PDMA_Private_Macro PDMA private macros
  * @{
  */

/**
  * @}
  */  /* End of PDMA_Private_Macro group */

/* Private variables ---------------------------------------------------------------------------------------*/

/** @defgroup PDMA_Private_Variable PDMA private variables
  * @{
  */

/**
  * @}
  */  /* End of PDMA_Private_Variable group */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup PDMA_Private_Function_Prototype PDMA private function prototypes
  * @{
  */

/**
  * @}
  */  /* End of PDMA_Private_Function_Prototype group */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup PDMA_Private_Function PDMA private functions
  * @{
  */

/*********************************************************************************************************//**
  * @brief  Configure specific PDMA channel
  * @param  PDMA_Ch: PDMA_CH0 ~ PDMACH11
  * @param  PDMACH_InitStruct: pointer to a PDMACH_InitTypeDef structure that contains the configuration
  * @retval None
  ***********************************************************************************************************/
void PDMA_Config(u32 PDMA_Ch, PDMACH_InitTypeDef *PDMACH_InitStruct)
{
  PDMACH_TypeDef *PDMACHx = (PDMACH_TypeDef *)(PDMA_BASE + PDMA_Ch*6*4);

  /* Check the parameters */
  Assert_Param(IS_PDMA_CH(PDMA_Ch));
  Assert_Param(IS_PDMA_WIDTH(PDMACH_InitStruct->PDMACH_DataSize));
  Assert_Param(IS_PDMA_PRIO(PDMACH_InitStruct->PDMACH_Priority));
  Assert_Param(IS_PDMA_ADR_MOD(PDMACH_InitStruct->PDMACH_AdrMod));
  Assert_Param(IS_PDMA_BLK_CNT(PDMACH_InitStruct->PDMACH_BlkCnt));
  Assert_Param(IS_PDMA_BLK_LEN(PDMACH_InitStruct->PDMACH_BlkLen));

  /* PDMA channel x configuration */
  PDMACHx->CR = (PDMACH_InitStruct->PDMACH_DataSize | PDMACH_InitStruct->PDMACH_Priority | PDMACH_InitStruct->PDMACH_AdrMod);

  PDMACHx->SADR = PDMACH_InitStruct->PDMACH_SrcAddr;

  PDMACHx->DADR = PDMACH_InitStruct->PDMACH_DstAddr;

  PDMACHx->TSR = (PDMACH_InitStruct->PDMACH_BlkCnt << 16) | PDMACH_InitStruct->PDMACH_BlkLen;
}

/*********************************************************************************************************//**
  * @brief  PDMA_TranSizeConfig
  * @param  PDMA_Ch: PDMA_CH0 ~ PDMACH11
  * @param  BlkCnt: Number of blocks for a transfer
  * @param  BlkLen: Number of data for a block
  * @retval None
  ***********************************************************************************************************/
void PDMA_TranSizeConfig(u32 PDMA_Ch, u32 BlkCnt, u32 BlkLen)
{
  PDMACH_TypeDef *PDMACHx = (PDMACH_TypeDef *)(PDMA_BASE + PDMA_Ch*6*4);

  /* Check the parameters */
  Assert_Param(IS_PDMA_CH(PDMA_Ch));
  Assert_Param(IS_PDMA_BLK_CNT(BlkCnt));
  Assert_Param(IS_PDMA_BLK_LEN(BlkLen));

  /* transfer size configuration */
  PDMACHx->TSR = ((BlkCnt << 16) | BlkLen);
}

/*********************************************************************************************************//**
  * @brief  Enable the specific PDMA channel interrupts
  * @param  PDMA_Ch: PDMA_CH0 ~ PDMACH11
  * @param  PDMA_Int: PDMA_INT_GE, PDMA_INT_BE, PDMA_INT_HT, PDMA_INT_TC, PDMA_INT_TE
  * @param  NewState: This parameter can be ENABLE or DISABLE.
  * @retval None
  ***********************************************************************************************************/
void PDMA_IntConig(u32 PDMA_Ch, u32 PDMA_Int, ControlStatus NewState)
{
  u32 *PdmaIntEnReg = (PDMA_Ch < 6) ? ((u32 *)(&PDMA->IER0)) : ((u32 *)(&PDMA->IER1));
  u32 BitShift = (PDMA_Ch < 6) ? (PDMA_Ch*5) : ((PDMA_Ch - 6)*5);

  /* Check the parameters */
  Assert_Param(IS_PDMA_CH(PDMA_Ch));
  Assert_Param(IS_PDMA_INT(PDMA_Int));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    *PdmaIntEnReg |= (PDMA_Int << BitShift);
  }
  else
  {
    *PdmaIntEnReg &= ~(PDMA_Int << BitShift);
  }
}

/*********************************************************************************************************//**
  * @brief  Enable a specific PDMA channel
  * @param  PDMA_Ch: PDMA_CH0 ~ PDMACH11
  * @param  NewState: This parameter can be ENABLE or DISABLE.
  * @retval None
  ************************************************************************************************************/
void PDMA_EnaCmd(u32 PDMA_Ch, ControlStatus NewState)
{
  PDMACH_TypeDef *PDMACHx = (PDMACH_TypeDef *)(PDMA_BASE + PDMA_Ch*6*4);

  /* Check the parameters */
  Assert_Param(IS_PDMA_CH(PDMA_Ch));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    SetBit_BB((u32)(&PDMACHx->CR), 0);
  }
  else
  {
    ResetBit_BB((u32)(&PDMACHx->CR), 0);
  }
}

/*********************************************************************************************************//**
  * @brief  Software trigger a specific PDMA channel
  * @param  PDMA_Ch: PDMA_CH0 ~ PDMACH11
  * @param  NewState: This parameter can be ENABLE or DISABLE.
  * @retval None
  ************************************************************************************************************/
void PDMA_SwTrigCmd(u32 PDMA_Ch, ControlStatus NewState)
{
  PDMACH_TypeDef *PDMACHx = (PDMACH_TypeDef *)(PDMA_BASE + PDMA_Ch*6*4);

  /* Check the parameters */
  Assert_Param(IS_PDMA_CH(PDMA_Ch));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    SetBit_BB((u32)(&PDMACHx->CR), 1);
  }
  else
  {
    ResetBit_BB((u32)(&PDMACHx->CR), 1);
  }
}

/*********************************************************************************************************//**
  * @brief  Get the specific PDMA channel interrupt flag
  * @param  PDMA_Ch: PDMA_CH0 ~ PDMACH11
  * @param  PDMA_Flag: PDMA_FLAG_GE, PDMA_FLAG_BE, PDMA_FLAG_HT, PDMA_FLAG_TC, PDMA_FLAG_TE
  * @retval SET or RESET
  ***********************************************************************************************************/
FlagStatus PDMA_GetFlagStatus(u32 PDMA_Ch, u32 PDMA_Flag)
{
  u32 *PdmaIntStatReg = (PDMA_Ch < 6) ? ((u32 *)(&PDMA->ISR0)) : ((u32 *)(&PDMA->ISR1));
  u32 BitShift = (PDMA_Ch < 6) ? (PDMA_Ch*5) : ((PDMA_Ch - 6)*5);

  /* Check the parameters */
  Assert_Param(IS_PDMA_CH(PDMA_Ch));
  Assert_Param(IS_PDMA_FLAG(PDMA_Flag));

  if((*PdmaIntStatReg & (PDMA_Flag << BitShift)) != RESET)
  {
    return SET;
  }
  else
  {
    return RESET;
  }
}

/*********************************************************************************************************//**
  * @brief  Clear the specific PDMA channel interrupt flags
  * @param  PDMA_Ch: PDMA_CH0 ~ PDMACH11
  * @param  PDMA_Flag: PDMA_FLAG_GE, PDMA_FLAG_BE, PDMA_FLAG_HT, PDMA_FLAG_TC, PDMA_FLAG_TE
  * @retval None
  ***********************************************************************************************************/
void PDMA_ClearFlag(u32 PDMA_Ch, u32 PDMA_Flag)
{
  u32 *PdmaIntStatClrReg = (PDMA_Ch < 6) ? ((u32 *)(&PDMA->ISCR0)) : ((u32 *)(&PDMA->ISCR1));
  u32 BitShift = (PDMA_Ch < 6) ? (PDMA_Ch*5) : ((PDMA_Ch - 6)*5);

  /* Check the parameters */
  Assert_Param(IS_PDMA_CH(PDMA_Ch));
  Assert_Param(IS_PDMA_CLEAR_FLAG(PDMA_Flag));

  *PdmaIntStatClrReg |= (PDMA_Flag << BitShift);
}

/**
  * @}
  */  /* End of PDMA_Private_Function group */

/**
  * @}
  */  /* End of PDMA_Peripheral_Group group */

/**
  * @}
  */  /* End of HT32F175x_275x_Peripheral_Driver group */
