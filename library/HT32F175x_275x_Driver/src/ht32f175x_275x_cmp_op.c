/*********************************************************************************************************//**
 * @file    ht32f175x_275x_cmp_op.c
 * @version V1.0
 * @date    04/11/2011
 * @brief   This file provides all the firmware functions about CMP_OP.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x_cmp_op.h"
#include "ht32f175x_275x_rstcu.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver HT32F175x/275x Peripheral Driver
  * @{
  */

/** @defgroup  CMP_OP CMP_OP
  * @brief CMP_OP driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Private_TypesDefinitions CMP_OP private types definitions
  * @{
  */

/**
  * @}
  */


/* Private define ------------------------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Private_Define CMP_OP private definitions
  * @{
  */

#define CMP_OP_ENABLE                 (0x00000001ul)
#define CMP_OP_CANCELLATION_MODE      (0x00000004ul)

/**
  * @}
  */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Private_Macro CMP_OP private macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Private_Variable CMP_OP private variables
  * @{
  */

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Private_Function_Prototype CMP_OP private function prototypes
  * @{
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Private_Function CMP_OP private functions
  * @{
  */

/*********************************************************************************************************//**
 * @brief Deinitialize the CMP_OP peripheral registers to their default reset values.
 * @param CMP_OPx: where x can be 0 or 1 to select the CMP_OP peripheral.
 * @retval None
 ************************************************************************************************************/
void CMP_OP_DeInit(CMP_OP_TypeDef* CMP_OPx)
{
  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));

  if(CMP_OPx == CMP_OP0)
  {
    RSTCU_APBPerip1Reset(RSTCU_APBRST1_OPA0, ENABLE);
  }
  else
  {
    RSTCU_APBPerip1Reset(RSTCU_APBRST1_OPA1, ENABLE);
  }
}

/*********************************************************************************************************//**
 * @brief Configure the CMP_OP peripheral as OPA or CMP mode and fill the cancellation value.
 * @param CMP_OPx: where CMP_OP is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @param mode: Specify the CMP_OPx peripheral mode
 *   This parameter can be any combination of the following values:
 *     @arg OP_MODE     : Operational Amplifier mode
 *     @arg CMP_MODE    : Comparator Mode Selection
 * @param cancellation: Specify the input offset voltage cancellation value .
 * @retval None
************************************************************************************************************/
void CMP_OP_Config(CMP_OP_TypeDef* CMP_OPx, u32 mode, u32 cancellation)
{
  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));
  Assert_Param(IS_CMP_OP_MODE(mode));
  Assert_Param(IS_CMP_OP_IOVC(cancellation));
  
  CMP_OPx->OPACR = (CMP_OPx->OPACR & CMP_OP_ENABLE) | mode; 
  CMP_OPx->OFVCR = cancellation;
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the specified CMP_OP peripheral.
 * @param CMP_OPx: where CMP_OPx is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @param  NewState: new state of the CMP_OPx peripheral.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
************************************************************************************************************/
void CMP_OP_Cmd(CMP_OP_TypeDef* CMP_OPx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));
  Assert_Param(IS_CONTROL_STATUS(NewState));
    
  if (NewState != DISABLE)
  {
    /* Enable the selected CMP_OPx peripheral */
    CMP_OPx->OPACR |= CMP_OP_ENABLE;
  }
  else
  {
    /* Disable the selected CMP_OPx peripheral */
    CMP_OPx->OPACR &= ~(u32)CMP_OP_ENABLE;
  }
}

/*********************************************************************************************************//**
 * @brief Configure the CMP_OP peripheral as cancellation mode and select the source of reference input.
 * @param CMP_OPx: where CMP_OPx is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @param CMP_OP_REF_INPUT: Specify the the source of reference input.
 *   This parameter can be any combination of the following values:
 *     @arg CMP_OP_NEGATIVE_INPUT
 *     @arg CMP_OP_POSITIVE_INPUT
 * @retval None
************************************************************************************************************/
void CMP_OP_CancellationModeConfig(CMP_OP_TypeDef* CMP_OPx, u16 CMP_OP_REF_INPUT)
{
  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));
  Assert_Param(IS_CMP_OP_REF(CMP_OP_REF_INPUT));

  CMP_OPx->OPACR = (CMP_OPx->OPACR & CMP_OP_ENABLE) | CMP_OP_CANCELLATION_MODE | CMP_OP_REF_INPUT;
}

/*********************************************************************************************************//**
 * @brief Set input offset voltage cancellation value.
 * @param CMP_OPx: where CMP_OPx is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @param cancellation: Specify the input offset voltage cancellation value .
 * @retval None
************************************************************************************************************/
void CMP_OP_SetCancellationVaule(CMP_OP_TypeDef* CMP_OPx, u32 cancellation)
{
  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));
  Assert_Param(IS_CMP_OP_IOVC(cancellation));

  CMP_OPx->OFVCR = cancellation;
}

/*********************************************************************************************************//**
 * @brief Get input offset voltage cancellation value.
 * @param CMP_OPx: where CMP_OPx is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @retval The input offset voltage cancellation value.
************************************************************************************************************/
u32 CMP_OP_GetCancellationVaule(CMP_OP_TypeDef* CMP_OPx)
{
  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));

  return CMP_OPx->OFVCR;
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the specified CMP_OP interrupts.
 * @param CMP_OPx: where CMP_OPx is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @param CMP_OP_INT: Specify the CMP_OP interrupt sources that is to be enabled or disabled.
 *        This parameter can be any combination of the following values:
 *        - CMP_OP_INT_FALLING:
 *        - CMP_OP_INT_RISING:
 * @param NewState new state of the specified ADC interrupts.
 *        This parameter can be: ENABLE or DISABLE.
 * @retval None
************************************************************************************************************/
void CMP_OP_IntConfig(CMP_OP_TypeDef* CMP_OPx, u32 CMP_OP_INT, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));
  Assert_Param(IS_CMP_OP_INT(CMP_OP_INT));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if(NewState != DISABLE)
  {
    CMP_OPx->CMPIER |= CMP_OP_INT ;
  }
  else
  {
    CMP_OPx->CMPIER &= ~CMP_OP_INT ;
  }
}

/*********************************************************************************************************//**
 * @brief Check whether the specified ADC interrupt has occurred.
 * @param CMP_OPx: where CMP_OPx is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @param CMP_OP_INT: Specify the interrupt status to check.
 *        This parameter can be any combination of the following values:
 *        - CMP_OP_INT_FALLING:
 *        - CMP_OP_INT_RISING:
 * @retval SET or RESET
************************************************************************************************************/
FlagStatus CMP_OP_GetIntStatus(CMP_OP_TypeDef* CMP_OPx, u32 CMP_OP_INT)
{
  FlagStatus Status;

  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));
  Assert_Param(IS_CMP_OP_INT(CMP_OP_INT));

  if((CMP_OPx->CMPISR & CMP_OP_INT) != 0x0)
  {
    Status = SET ;
  }
  else
  {
    Status = RESET ;
  }

  return Status ;
}

/*********************************************************************************************************//**
 * @brief Check whether the specified CMP_OP flag has been set.
 * @param CMP_OPx: where CMP_OPx is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @param CMP_OP_FLAG: Specify the flag to check.
 *        This parameter can be any combination of the following values:
 *        - CMP_OP_FLAG_FALLING:
 *        - CMP_OP_FLAG_RISING:
 * @retval SET or RESET
************************************************************************************************************/
FlagStatus CMP_OP_GetFlagStatus(CMP_OP_TypeDef* CMP_OPx, u32 CMP_OP_FLAG)
{
  FlagStatus Status;

  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));
  Assert_Param(IS_CMP_OP_FLAG(CMP_OP_FLAG));

  if((CMP_OPx->CMPRSR & CMP_OP_FLAG) != 0x0)
  {
    Status = SET ;
  }
  else
  {
    Status = RESET ;
  }

  return Status ;
}


/*********************************************************************************************************//**
 * @brief Clear the CMP_OPx interrupt pending bits.
 * @param CMP_OPx: where CMP_OPx is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @param CMP_OP_INT: specifies the interrupt pending bits to be cleared.
 *        This parameter can be any combination of the following values:
 *        - CMP_OP_INT_FALLING:
 *        - CMP_OP_INT_RISING:
 * @retval None
************************************************************************************************************/
void CMP_OP_ClearIntPendingBit(CMP_OP_TypeDef* CMP_OPx, u32 CMP_OP_INT)
{
  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));
  Assert_Param(IS_CMP_OP_INT(CMP_OP_INT));

  CMP_OPx->CMPICLR = CMP_OP_INT ;
}

/*********************************************************************************************************//**
 * @brief Get the output status of CMP_OPx.
 * @param CMP_OPx: where CMP_OPx is the selected CMP_OP from the CMP_OP peripherals, x can be 0 or 1.
 * @retval SET or RESET
************************************************************************************************************/
FlagStatus CMP_OP_GetOutputStatus(CMP_OP_TypeDef* CMP_OPx)
{
  /* Check the parameters */
  Assert_Param(IS_CMP_OP_ALL_PERIPH(CMP_OPx));

  if((CMP_OPx->OPACR & 0x00000100) != 0x0)
  {
    return SET ;
  }
  else
  {
    return RESET ;
  }
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
