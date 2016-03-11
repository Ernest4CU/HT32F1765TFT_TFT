/*****************************************************************************//**
 * @file    ht32f175x_275x_exti.c
 * @version V1.0
 * @date    11/16/2010
 * @brief   This file provides all the EXTI firmware functions.
 **********************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 *********************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x_exti.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver HT32F175x/275x Peripheral Driver
  * @{
  */

/** @defgroup  EXTI EXTI
  * @brief EXTI driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup EXTI_Private_TypesDefinitions Definitions of EXTI private types
  * @{
  */

/**
  * @}
  */

/* Private define ------------------------------------------------------------------------------------------*/

/** @defgroup EXTI_Private_Define EXTI private definitions
  * @{
  */

/* EXTI EVWUPIEN mask */
#define WAKUPCR_EVWUPIEN_SET      ((u32)0x80000000)
#define WAKUPCR_EVWUPIEN_RESET    ((u32)0x7FFFFFFF)

/**
  * @}
  */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup EXTI_Private_Macro EXTI private macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------------------------------------*/

/** @defgroup EXTI_Private_Variable EXTI private variables
  * @{
  */

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup EXTI_Private_Function_Prototype EXTI private function prototypes
  * @{
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup EXTI_Private_Function EXTI private functions
  * @{
  */

/*********************************************************************************************************//**
  * @brief  Deinitialize the EXTI peripheral registers.
  * @param  EXTI_Channel: can be 0, 1 to 15 to select the EXTI Channel.
  *   This parameter can be one of the following values:
  *     @arg EXTI_CHANNEL_0
  *     @arg EXTI_CHANNEL_1
  *     @arg EXTI_CHANNEL_2
  *     @arg EXTI_CHANNEL_3
  *     @arg EXTI_CHANNEL_4
  *     @arg EXTI_CHANNEL_5
  *     @arg EXTI_CHANNEL_6
  *     @arg EXTI_CHANNEL_7
  *     @arg EXTI_CHANNEL_8
  *     @arg EXTI_CHANNEL_9
  *     @arg EXTI_CHANNEL_10
  *     @arg EXTI_CHANNEL_11
  *     @arg EXTI_CHANNEL_12
  *     @arg EXTI_CHANNEL_13
  *     @arg EXTI_CHANNEL_14
  *     @arg EXTI_CHANNEL_15
  * @retval None
  ***********************************************************************************************************/
void EXTI_DeInit(u32 EXTI_Channel)
{
  u32 tmp;

  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_Channel));

  tmp = 1 << EXTI_Channel;

  *((u32 *) EXTI + EXTI_Channel ) = 0x0;
  EXTI->CR &= (~tmp);
  EXTI->EDGEFLGR = tmp;
  EXTI->EDGESR = tmp;
  EXTI->SSCR &= (~tmp);
  EXTI->WAKUPCR &= (~tmp);
  EXTI->WAKUPPOLR &= (~tmp);
  EXTI->WAKUPFLG = tmp;
}

/*********************************************************************************************************//**
  * @brief  Initialize the EXTI peripheral.
  * @param  EXTI_InitStruct: pointer to a EXTI_InitTypeDef structure.
  * @retval None
  ***********************************************************************************************************/
void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct)
{
  u32 regval;

  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_InitStruct->EXTI_Channel));
  Assert_Param(IS_EXTI_DEBOUNCE_TYPE(EXTI_InitStruct->EXTI_Debounce));
  Assert_Param(IS_EXTI_DEBOUNCE_SIZE(EXTI_InitStruct->EXTI_DebounceCnt));
  Assert_Param(IS_EXTI_INT_TYPE(EXTI_InitStruct->EXTI_IntType));

  /* Set EXTI interrupt configuration */
  regval = (EXTI_InitStruct->EXTI_Debounce << 31) | (EXTI_InitStruct->EXTI_IntType << 28) | (EXTI_InitStruct->EXTI_DebounceCnt);
  *( (u32 *) EXTI + EXTI_InitStruct->EXTI_Channel ) = regval;
}

/*********************************************************************************************************//**
  * @brief  Enable or Disable the specified EXTI channelx interrupts.
  * @param  EXTI_Channel: can be 0, 1 to 15 to select the EXTI Channel.
  *   This parameter can be one of the following values:
  *     @arg EXTI_CHANNEL_0
  *     @arg EXTI_CHANNEL_1
  *     @arg EXTI_CHANNEL_2
  *     @arg EXTI_CHANNEL_3
  *     @arg EXTI_CHANNEL_4
  *     @arg EXTI_CHANNEL_5
  *     @arg EXTI_CHANNEL_6
  *     @arg EXTI_CHANNEL_7
  *     @arg EXTI_CHANNEL_8
  *     @arg EXTI_CHANNEL_9
  *     @arg EXTI_CHANNEL_10
  *     @arg EXTI_CHANNEL_11
  *     @arg EXTI_CHANNEL_12
  *     @arg EXTI_CHANNEL_13
  *     @arg EXTI_CHANNEL_14
  *     @arg EXTI_CHANNEL_15
  * @param  NewState: new state of the EXTI Interrupt.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  ***********************************************************************************************************/
void EXTI_IntConfig(u32 EXTI_Channel, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_Channel));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  /* Configure EXTI interrupt */
  if (NewState == ENABLE)
  {
    EXTI->CR |= (1 << EXTI_Channel);
  }
  else
  {
    EXTI->CR &= ~(1 << EXTI_Channel);
  }
}

/*********************************************************************************************************//**
  * @brief  Configure the EXTI channelx event wakeup function.
  * @param  EXTI_Channel: can be 0, 1 to 15 to select the EXTI Channel.
  *   This parameter can be one of the following values:
  *     @arg EXTI_CHANNEL_0
  *     @arg EXTI_CHANNEL_1
  *     @arg EXTI_CHANNEL_2
  *     @arg EXTI_CHANNEL_3
  *     @arg EXTI_CHANNEL_4
  *     @arg EXTI_CHANNEL_5
  *     @arg EXTI_CHANNEL_6
  *     @arg EXTI_CHANNEL_7
  *     @arg EXTI_CHANNEL_8
  *     @arg EXTI_CHANNEL_9
  *     @arg EXTI_CHANNEL_10
  *     @arg EXTI_CHANNEL_11
  *     @arg EXTI_CHANNEL_12
  *     @arg EXTI_CHANNEL_13
  *     @arg EXTI_CHANNEL_14
  *     @arg EXTI_CHANNEL_15
  * @param  EXTI_WakuUpType: determines the type of signal to trigger EXTI interrupt.
  *   This parameter can be one of the following values:
  *     @arg EXTI_WAKEUP_HIGH_LEVEL
  *     @arg EXTI_WAKEUP_LOW_LEVEL
  * @param  NewState: new state of the event wakeup of EXTI.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  ***********************************************************************************************************/
void EXTI_WakeupEventConfig(u32 EXTI_Channel, u8 EXTI_WakuUpType, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_Channel));
  Assert_Param(IS_EXTI_WAKEUP_TYPE(EXTI_WakuUpType));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState == ENABLE)
  {
    if (EXTI_WakuUpType == EXTI_WAKEUP_HIGH_LEVEL)
    {
      EXTI->WAKUPPOLR &= ~(1 << EXTI_Channel);
    }
    else
    {
      EXTI->WAKUPPOLR |= (1 << EXTI_Channel);
    }

    EXTI->WAKUPCR |=  (1 << EXTI_Channel);
  }
  else
  {
    EXTI->WAKUPCR &= ~(1 << EXTI_Channel);
  }
}

/*********************************************************************************************************//**
  * @brief  Enable or Disable the EXTI channelx event wakeup interrupt.
  * @param  NewState: new state of the event wakeup interrupt of the EXTI.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  ***********************************************************************************************************/
void EXTI_WakeupEventIntConfig(ControlStatus NewState)
{
  if (NewState == ENABLE)
  {
    /* Set EVWUPIEN bit */
    EXTI->WAKUPCR |= WAKUPCR_EVWUPIEN_SET;
  }
  else
  {
    /* Clear EVWUPIEN bit */
    EXTI->WAKUPCR &= WAKUPCR_EVWUPIEN_RESET;
  }
}

/*********************************************************************************************************//**
  * @brief  Clear the specified EXTI channelx edge flag.
  * @param  EXTI_Channel: can be 0, 1 to 15 to select the EXTI Channel.
  *   This parameter can be one of the following values:
  *     @arg EXTI_CHANNEL_0
  *     @arg EXTI_CHANNEL_1
  *     @arg EXTI_CHANNEL_2
  *     @arg EXTI_CHANNEL_3
  *     @arg EXTI_CHANNEL_4
  *     @arg EXTI_CHANNEL_5
  *     @arg EXTI_CHANNEL_6
  *     @arg EXTI_CHANNEL_7
  *     @arg EXTI_CHANNEL_8
  *     @arg EXTI_CHANNEL_9
  *     @arg EXTI_CHANNEL_10
  *     @arg EXTI_CHANNEL_11
  *     @arg EXTI_CHANNEL_12
  *     @arg EXTI_CHANNEL_13
  *     @arg EXTI_CHANNEL_14
  *     @arg EXTI_CHANNEL_15
  * @retval None
  ***********************************************************************************************************/
void EXTI_ClearEdgeFlag(u32 EXTI_Channel)
{
  u32 tmp;

  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_Channel));

  tmp = 1 << EXTI_Channel;

  /* Write 1 to clear both edge detection flag     */
  EXTI->EDGEFLGR = tmp;
  /* Write 1 to clear positive edge detection flag */
  EXTI->EDGESR = tmp;
}

/*********************************************************************************************************//**
  * @brief  Clear the specified EXTI channelx wakeup flag.
  * @param  EXTI_Channel: can be 0, 1 to 15 to select the EXTI Channel.
  *   This parameter can be one of the following values:
  *     @arg EXTI_CHANNEL_0
  *     @arg EXTI_CHANNEL_1
  *     @arg EXTI_CHANNEL_2
  *     @arg EXTI_CHANNEL_3
  *     @arg EXTI_CHANNEL_4
  *     @arg EXTI_CHANNEL_5
  *     @arg EXTI_CHANNEL_6
  *     @arg EXTI_CHANNEL_7
  *     @arg EXTI_CHANNEL_8
  *     @arg EXTI_CHANNEL_9
  *     @arg EXTI_CHANNEL_10
  *     @arg EXTI_CHANNEL_11
  *     @arg EXTI_CHANNEL_12
  *     @arg EXTI_CHANNEL_13
  *     @arg EXTI_CHANNEL_14
  *     @arg EXTI_CHANNEL_15
  * @retval None
  ***********************************************************************************************************/
void EXTI_ClearWakeupFlag(u32 EXTI_Channel)
{
  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_Channel));

  /* Write 1 to clear wake up flag  */
  EXTI->WAKUPFLG = 1 << EXTI_Channel;

  /*--------------------------------------------------------------------------------------------------------*/
  /* DSB instruction is added in this function to ensure the write operation which is for clearing interrupt*/
  /* flag is actually completed before exiting ISR. It prevents the NVIC from detecting the interrupt again */
  /* since the write register operation may be pended in the internal write buffer of Cortex-M3 when program*/
  /* has exited interrupt routine. This DSB instruction may be masked if this function is called in the     */
  /* beginning of ISR and there are still some instructions before exiting ISR.                             */
  /*--------------------------------------------------------------------------------------------------------*/
  __DSB();
}

/*********************************************************************************************************//**
  * @brief  Get the specified EXTI channelx edge status.
  * @param  EXTI_Channel: can be 0, 1 to 15 to select the EXTI Channel.
  *   This parameter can be one of the following values:
  *     @arg EXTI_CHANNEL_0
  *     @arg EXTI_CHANNEL_1
  *     @arg EXTI_CHANNEL_2
  *     @arg EXTI_CHANNEL_3
  *     @arg EXTI_CHANNEL_4
  *     @arg EXTI_CHANNEL_5
  *     @arg EXTI_CHANNEL_6
  *     @arg EXTI_CHANNEL_7
  *     @arg EXTI_CHANNEL_8
  *     @arg EXTI_CHANNEL_9
  *     @arg EXTI_CHANNEL_10
  *     @arg EXTI_CHANNEL_11
  *     @arg EXTI_CHANNEL_12
  *     @arg EXTI_CHANNEL_13
  *     @arg EXTI_CHANNEL_14
  *     @arg EXTI_CHANNEL_15
  * @param  EXTI_Edge: can be status of edge that user want to monitor.
  *   This parameter can be one of the following values:
  *     @arg EXTI_EDGE_POSITIVE
  *     @arg EXTI_EDGE_NEGATIVE
  * @retval SET or RESET
  ***********************************************************************************************************/
FlagStatus EXTI_GetEdgeStatus(u32 EXTI_Channel, u32 EXTI_Edge)
{
  FlagStatus status = RESET;

  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_Channel));
  Assert_Param(IS_EXTI_EDGE(EXTI_Edge));

  if( EXTI->EDGEFLGR & (1 << EXTI_Channel) )
  {
    if( BitBand((u32)&EXTI->EDGESR, EXTI_Channel) ^ EXTI_Edge)
    {
      status = SET;
    }
    else
    {
      status = RESET;
    }
  }
  else
  {
    status = RESET;
  }

  return status;
}

/*********************************************************************************************************//**
  * @brief  Get the specified EXTI channelx wakeup flag.
  * @param  EXTI_Channel: can be 0, 1 to 15 to select the EXTI Channel.
  *   This parameter can be one of the following values:
  *     @arg EXTI_CHANNEL_0
  *     @arg EXTI_CHANNEL_1
  *     @arg EXTI_CHANNEL_2
  *     @arg EXTI_CHANNEL_3
  *     @arg EXTI_CHANNEL_4
  *     @arg EXTI_CHANNEL_5
  *     @arg EXTI_CHANNEL_6
  *     @arg EXTI_CHANNEL_7
  *     @arg EXTI_CHANNEL_8
  *     @arg EXTI_CHANNEL_9
  *     @arg EXTI_CHANNEL_10
  *     @arg EXTI_CHANNEL_11
  *     @arg EXTI_CHANNEL_12
  *     @arg EXTI_CHANNEL_13
  *     @arg EXTI_CHANNEL_14
  *     @arg EXTI_CHANNEL_15
  * @retval SET or RESET
  ***********************************************************************************************************/
FlagStatus EXTI_GetWakeupFlagStatus(u32 EXTI_Channel)
{
  FlagStatus status = RESET;

  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_Channel));

  if ( EXTI->WAKUPFLG & (1 << EXTI_Channel) )
  {
    status = SET;
  }
  else
  {
    status = RESET;
  }

  return status;
}

/*********************************************************************************************************//**
  * @brief  Activate or Deactivate an EXTI channelx interrupt by software.
  * @param  EXTI_Channel: can be 0, 1 to 15 to select the EXTI Channel.
  *   This parameter can be one of the following values:
  *     @arg EXTI_CHANNEL_0
  *     @arg EXTI_CHANNEL_1
  *     @arg EXTI_CHANNEL_2
  *     @arg EXTI_CHANNEL_3
  *     @arg EXTI_CHANNEL_4
  *     @arg EXTI_CHANNEL_5
  *     @arg EXTI_CHANNEL_6
  *     @arg EXTI_CHANNEL_7
  *     @arg EXTI_CHANNEL_8
  *     @arg EXTI_CHANNEL_9
  *     @arg EXTI_CHANNEL_10
  *     @arg EXTI_CHANNEL_11
  *     @arg EXTI_CHANNEL_12
  *     @arg EXTI_CHANNEL_13
  *     @arg EXTI_CHANNEL_14
  *     @arg EXTI_CHANNEL_15
  * @param  NewState: new state of EXTI channelx interrupt condition.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  ***********************************************************************************************************/
void EXTI_SWIntCmd(u32 EXTI_Channel, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_Channel));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if(NewState == ENABLE)
  {
    EXTI->SSCR = 1 << EXTI_Channel;
  }
  else
  {
    EXTI->SSCR &= ~(1 << EXTI_Channel);
  }
}

/*********************************************************************************************************//**
  * @brief  Get the specified EXTI channelx software command register bit.
  * @param  EXTI_Channel: can be 0, 1 to 15 to select the EXTI Channel.
  *   This parameter can be one of the following values:
  *     @arg EXTI_CHANNEL_0
  *     @arg EXTI_CHANNEL_1
  *     @arg EXTI_CHANNEL_2
  *     @arg EXTI_CHANNEL_3
  *     @arg EXTI_CHANNEL_4
  *     @arg EXTI_CHANNEL_5
  *     @arg EXTI_CHANNEL_6
  *     @arg EXTI_CHANNEL_7
  *     @arg EXTI_CHANNEL_8
  *     @arg EXTI_CHANNEL_9
  *     @arg EXTI_CHANNEL_10
  *     @arg EXTI_CHANNEL_11
  *     @arg EXTI_CHANNEL_12
  *     @arg EXTI_CHANNEL_13
  *     @arg EXTI_CHANNEL_14
  *     @arg EXTI_CHANNEL_15
  * @retval SET or RESET
  ***********************************************************************************************************/
u32 EXTI_GetSWCmdStatus(u32 EXTI_Channel)
{
  u32 status = RESET;

  /* Check the parameters */
  Assert_Param(IS_EXTI_CHANNEL(EXTI_Channel));

  if ( EXTI->SSCR & (1 << EXTI_Channel) )
  {
    status = SET;
  }
  else
  {
    status = RESET;
  }

  return status;
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
