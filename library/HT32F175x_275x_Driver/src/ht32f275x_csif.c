/*****************************************************************************//**
 * @file    ht32f275x_csif.c
 * @version V1.0
 * @date    09/08/2011
 * @brief   This file provides all the CSIF firmware functions.
 **********************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 *********************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f275x_csif.h"
#include "ht32f175x_275x_rstcu.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver HT32F175x/275x Peripheral Driver
  * @{
  */

/** @defgroup CSIF CSIF
  * @brief CSIF driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup CSIF_Private_TypesDefinitions CSIF private types definitions
  * @{
  */

/**
  * @}
  */

/* Private define ------------------------------------------------------------------------------------------*/

/** @defgroup CSIF_Private_Define CSIF private definitions
  * @{
  */

/* CSIF CSIFEN mask */
#define ENR_CSIFEN_SET           ((u32)0x80000000)
#define ENR_CSIFEN_RESET         ((u32)0x00000000)


/**
  * @}
  */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup CSIF_Private_Macro CSIF private macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------------------------------------*/

/** @defgroup CSIF_Private_Variable CSIF private variables
  * @{
  */

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup CSIF_Private_Function_Prototype Prototypes of CSIF private functions
  * @{
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup CSIF_Private_Function CSIF private functions
  * @{
  */

/*********************************************************************************************************//**
  * @brief  Deinitializes the CSIF peripheral registers to their default reset values.
  * @retval None
  ************************************************************************************************************/
void CSIF_DeInit(void)
{
  RSTCU_AHBPeripReset(RSTCU_AHBRST_CSIF, ENABLE);
}

/*********************************************************************************************************//**
  * @brief  Initializes the CSIF peripheral according to the specified parameters in the CSIF_BasicInitStruct.
  * @param  CSIF_BasicInitStruct: pointer to a CSIF_BasicInitTypeDef structure that contains the configuration
  *   information for the specified CSIF peripheral.
  * @retval None
  ************************************************************************************************************/
void CSIF_BasicInit(CSIF_BasicInitTypeDef* CSIF_BasicInitStruct)
{
  /* Check the parameters */
  Assert_Param(IS_CSIF_FORMAT(CSIF_BasicInitStruct->CSIF_Format));
  Assert_Param(IS_CSIF_VSYNC_TYPE(CSIF_BasicInitStruct->CSIF_VSYNCType));
  Assert_Param(IS_CSIF_HSYNC_TYPE(CSIF_BasicInitStruct->CSIF_HSYNCType));
  Assert_Param(IS_CSIF_SAMPLE_EDGE(CSIF_BasicInitStruct->CSIF_SampleEdge));
  Assert_Param(IS_CSIF_VSYNC_POLARITY(CSIF_BasicInitStruct->CSIF_VSYNCPolarity));
  Assert_Param(IS_CSIF_HSYNC_POLARITY(CSIF_BasicInitStruct->CSIF_HSYNCPolarity));
  Assert_Param(IS_CSIF_LINE_DELAY(CSIF_BasicInitStruct->CSIF_LineDelay));
  Assert_Param(IS_CSIF_FRAME_DELAY(CSIF_BasicInitStruct->CSIF_FrameDelay));
  Assert_Param(IS_CSIF_IMAGE_WIDTH(CSIF_BasicInitStruct->CSIF_ImageWidth));
  Assert_Param(IS_CSIF_IMAGE_HEIGHT(CSIF_BasicInitStruct->CSIF_ImageHeight));

  /*------------------------ CSIF Control Register Configuration --------------------------------------------*/
  CSIF->CR = CSIF_BasicInitStruct->CSIF_Format | CSIF_BasicInitStruct->CSIF_VSYNCType | CSIF_BasicInitStruct->CSIF_HSYNCType |
             CSIF_BasicInitStruct->CSIF_SampleEdge | CSIF_BasicInitStruct->CSIF_VSYNCPolarity |
             CSIF_BasicInitStruct->CSIF_HSYNCPolarity | (CSIF_BasicInitStruct->CSIF_LineDelay << 8) |
             (CSIF_BasicInitStruct->CSIF_FrameDelay << 16);

  /*------------------------ CSIF Image Width/Height Register Configuration ---------------------------------*/
  CSIF->IMGWH = (CSIF_BasicInitStruct->CSIF_ImageWidth-1) | ((CSIF_BasicInitStruct->CSIF_ImageHeight-1) << 16);
}

/*********************************************************************************************************//**
  * @brief  Fills each CSIF_BasicInitStruct member with its default value.
  * @param  CSIF_BasicInitStruct: pointer to an CSIF_BasicInitTypeDef structure which will be initialized.
  * @retval None
  ************************************************************************************************************/
void CSIF_BasicStructInit(CSIF_BasicInitTypeDef* CSIF_BasicInitStruct)
{
  /* Initialize the CSIF_Format member */
  CSIF_BasicInitStruct->CSIF_Format = CSIF_FORMAT_RAWRGB;

  /* Initialize the CSIF_VSYNCType member */
  CSIF_BasicInitStruct->CSIF_VSYNCType = CSIF_VSYNCTYPE_PULSE;

  /* Initialize the CSIF_HSYNCType member */
  CSIF_BasicInitStruct->CSIF_HSYNCType = CSIF_HSYNCTYPE_CONTINUOUS;

  /* Initialize the CSIF_SampleEdge member */
  CSIF_BasicInitStruct->CSIF_SampleEdge = CSIF_SAMPLEEDGE_FALLING;

  /* Initialize the CSIF_VSYNCPolarity member */
  CSIF_BasicInitStruct->CSIF_VSYNCPolarity = CSIF_VSYNCPOLARITY_HIGH;

  /* Initialize the CSIF_HSYNCPolarity member */
  CSIF_BasicInitStruct->CSIF_HSYNCPolarity = CSIF_HSYNCPOLARITY_HIGH;

  /* Initialize the CSIF_LineDelay member */
  CSIF_BasicInitStruct->CSIF_LineDelay = 0;

  /* Initialize the CSIF_FrameDelay member */
  CSIF_BasicInitStruct->CSIF_FrameDelay = 0;

  /* Initialize the CSIF_ImageWidth member */
  CSIF_BasicInitStruct->CSIF_ImageWidth = 0;

  /* Initialize the CSIF_ImageHeight member */
  CSIF_BasicInitStruct->CSIF_ImageHeight = 0;

}

/*********************************************************************************************************//**
  * @brief  Initializes the CSIF peripheral according to the specified parameters in the CSIF_WindowInitStruct.
  * @param  CSIF_WindowInitStruct: pointer to a CSIF_WindowInitTypeDef structure that contains the configuration
  *   information for the specified CSIF peripheral.
  * @retval None
  ************************************************************************************************************/
void CSIF_WindowInit(CSIF_WindowInitTypeDef* CSIF_WindowInitStruct)
{
  /* Check the parameters */
  Assert_Param(IS_CSIF_WINDOW(CSIF_WindowInitStruct->CSIF_Window));
  Assert_Param(IS_CSIF_HORSTART_POINT(CSIF_WindowInitStruct->CSIF_HorizontalStartPoint));
  Assert_Param(IS_CSIF_VERSTART_POINT(CSIF_WindowInitStruct->CSIF_VerticalStartPoint));
  Assert_Param(IS_CSIF_WINDOW_WIDTH(CSIF_WindowInitStruct->CSIF_WindowWidth));
  Assert_Param(IS_CSIF_WINDOW_HEIGHT(CSIF_WindowInitStruct->CSIF_WindowHeight));

  /*------------------------ CSIF Window Capture Register 0 Configuration ----------------------------------*/
  CSIF->WCR0 = CSIF_WindowInitStruct->CSIF_Window | CSIF_WindowInitStruct->CSIF_HorizontalStartPoint |
               (CSIF_WindowInitStruct->CSIF_VerticalStartPoint << 16);

  /*------------------------ CSIF Window Capture Register 1 Configuration ----------------------------------*/
  CSIF->WCR1 = (CSIF_WindowInitStruct->CSIF_WindowWidth-1) | ((CSIF_WindowInitStruct->CSIF_WindowHeight-1) << 16);
}

/*********************************************************************************************************//**
  * @brief  Fills each CSIF_WindowStructInit member with its default value.
  * @param  CSIF_WindowInitStruct: pointer to an CSIF_WindowInitTypeDef structure which will be initialized.
  * @retval None
  ************************************************************************************************************/
void CSIF_WindowStructInit(CSIF_WindowInitTypeDef* CSIF_WindowInitStruct)
{
  /* Initialize the CSIF_Window member */
  CSIF_WindowInitStruct->CSIF_Window = CSIF_WINDOW_DISABLE;

  /* Initialize the CSIF_HorizontalStartPoint member */
  CSIF_WindowInitStruct->CSIF_HorizontalStartPoint = 0;

  /* Initialize the CSIF_VerticalStartPoint member */
  CSIF_WindowInitStruct->CSIF_VerticalStartPoint = 0;

  /* Initialize the CSIF_WindowWidth member */
  CSIF_WindowInitStruct->CSIF_WindowWidth = 0;

  /* Initialize the CSIF_WindowHeight member */
  CSIF_WindowInitStruct->CSIF_WindowHeight = 0;
}

/*********************************************************************************************************//**
  * @brief  Initializes the CSIF peripheral according to the specified parameters in the CSIF_SubSampleInitStruct.
  * @param  CSIF_SubSampleInitStruct: pointer to a CSIF_SubSampleInitTypeDef structure that contains the configuration
  *   information for the specified CSIF peripheral.
  * @retval None
  ************************************************************************************************************/
void CSIF_SubSampleInit(CSIF_SubSampleInitTypeDef* CSIF_SubSampleInitStruct)
{
  /* Check the parameters */
  Assert_Param(IS_CSIF_SUB_SAMPLE(CSIF_SubSampleInitStruct->CSIF_SubSample));
  Assert_Param(IS_CSIF_MASK_LENGTH(CSIF_SubSampleInitStruct->CSIF_ColumnSkipMaskLength));
  Assert_Param(IS_CSIF_MASK_LENGTH(CSIF_SubSampleInitStruct->CSIF_RowSkipMaskLength));

  /*------------------------ CSIF Row & Column Sub-Sample RegisterConfiguration ----------------------------*/
  CSIF->SMP = CSIF_SubSampleInitStruct->CSIF_SubSample | (CSIF_SubSampleInitStruct->CSIF_ColumnSkipMaskLength << 8) |
              (CSIF_SubSampleInitStruct->CSIF_RowSkipMaskLength << 16);

  /*------------------------ CSIF Column Sub-Sample Register Configuration ---------------------------------*/
  CSIF->SMPCOL = CSIF_SubSampleInitStruct->CSIF_ColumnSkipMask;

  /*------------------------ CSIF Row Sub-Sample Register Configuration ------------------------------------*/
  CSIF->SMPROW = CSIF_SubSampleInitStruct->CSIF_RowSkipMask;
}

/*********************************************************************************************************//**
  * @brief  Fills each CSIF_SubSampleInitStruct member with its default value
  * @param  CSIF_SubSampleInitStruct: pointer to an CSIF_SubSampleInitTypeDef structurewhich will be initialized.
  * @retval None
  ************************************************************************************************************/
void CSIF_SunSampleStructInit(CSIF_SubSampleInitTypeDef* CSIF_SubSampleInitStruct)
{
  /* Initialize the CSIF_SubSample member */
  CSIF_SubSampleInitStruct->CSIF_SubSample = CSIF_SUBSAMPLE_DISABLE;

  /* Initialize the CSIF_ColumnSkipMaskLength member */
  CSIF_SubSampleInitStruct->CSIF_ColumnSkipMaskLength = CSIF_MASKLENGTH_32B;

  /* Initialize the CSIF_RowSkipMaskLength member */
  CSIF_SubSampleInitStruct->CSIF_RowSkipMaskLength = CSIF_MASKLENGTH_32B;

  /* Initialize the CSIF_ColumnSkipMask member */
  CSIF_SubSampleInitStruct->CSIF_ColumnSkipMask = 0;

  /* Initialize the CSIF_RowSkipMask member */
  CSIF_SubSampleInitStruct->CSIF_RowSkipMask = 0;
}

/*********************************************************************************************************//**
  * @brief  Enables or Disables the CSIF peripheral.
  * @param  NewState: new state of the CSIF peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  ************************************************************************************************************/
void CSIF_Cmd(ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    /* Enable CSIF peripheral */
    CSIF->ENR = ENR_CSIFEN_SET;
  }
  else
  {
    /* Disable CSIF peripheral */
    CSIF->ENR = ENR_CSIFEN_RESET;
  }
}

/*********************************************************************************************************//**
  * @brief  Enables or Disables the specified CSIF interrupt.
  * @param  CSIF_Int: specifies if the CSIF interrupt source to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  *     @arg CSIF_INT_SOFFLG         : CSIF start of frame interrupt
  *     @arg CSIF_INT_EOFFLG         : CSIF end of frame interrupt
  *     @arg CSIF_INT_CAPSTA         : CSIF cpature start interrupt
  *     @arg CSIF_INT_CAPSTS         : CSIF capture status interrupt
  *     @arg CSIF_INT_BADFRAME       : CSIF bad frame interrupt
  *     @arg CSIF_INT_FIFOOVR        : CSIF FIFO overrun interrupt
  *     @arg CSIF_INT_FIFOEMP        : CSIF FIFO empty interrupt
  *     @arg CSIF_INT_FIFOFUL        : CSIF FIFO full interrupt
  *     @arg CSIF_INT_ALL            : All CSIF interrupt
  * @param  NewState: new state of the CSIF interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  ************************************************************************************************************/
void CSIF_IntConfig(u32 CSIF_Int, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CSIF_INT(CSIF_Int));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    CSIF->IER |= CSIF_Int;
  }
   else
  {
    CSIF->IER &= (u32)~CSIF_Int;
  }
}

/*********************************************************************************************************//**
  * @brief  Check whether the specified CSIF flag has been set.
  * @param  CSIF_Flag: specifies the flag that is to be check.
  *   This parameter can be one of the following values:
  *     @arg CSIF_FLAG_SOFFLG          : CSIF start of frame flag
  *     @arg CSIF_FLAG_EOFFLG          : CSIF end of frame flag
  *     @arg CSIF_FLAG_CAPSTA          : CSIF cpature start flag
  *     @arg CSIF_FLAG_CAPSTS          : CSIF capture status flag
  *     @arg CSIF_FLAG_BADFRAME        : CSIF bad frame fla
  *     @arg CSIF_FLAG_FIFOOVR         : CSIF FIFO overrun flag
  *     @arg CSIF_FLAG_FIFOEMP         : CSIF FIFO empty flag
  *     @arg CSIF_FLAG_FIFOFUL         : CSIF FIFO full flag
  * @retval The new state of CSIF_Flag (SET or RESET).
  ************************************************************************************************************/
FlagStatus CSIF_GetFlagStatus(u32 CSIF_Flag)
{
  u32 statusreg = 0;
  FlagStatus bitstatus = RESET;

  /* Check the parameters */
  Assert_Param(IS_CSIF_FLAG(CSIF_Flag));

  statusreg = CSIF->SR;

  if ( (statusreg & CSIF_Flag) != (u32)RESET )
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }

  return bitstatus;
}

/*********************************************************************************************************//**
  * @brief  Clear the specified CSIF flag.
  * @param  CSIF_Flag: specifies the flag to be cleared.
  *   This parameter can be one of the following values:
  *     @arg CSIF_FLAG_SOFFLG         : CSIF start of frame flag
  *     @arg CSIF_FLAG_EOFFLG         : CSIF end of frame flag
  *     @arg CSIF_FLAGT_CAPSTA        : CSIF cpature start flag
  *     @arg CSIF_FLAG_CAPSTS         : CSIF capture status flag
  *     @arg CSIF_FLAG_BADFRAME       : CSIF bad frame flag
  * @retval None
  ************************************************************************************************************/
void CSIF_ClearFlag(u32 CSIF_Flag)
{
  /* Check the parameters */
  Assert_Param(IS_CSIF_CLEAR_FLAG(CSIF_Flag));

  CSIF->SR = CSIF_Flag;
}

/*********************************************************************************************************//**
  * @brief  Enables or Disables the CSIF Master Clock.
  * @param  NewState: new state of the CSIF Master Clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  ************************************************************************************************************/
void CSIF_MasterClockCmd(ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    CKCU->AHBCCR |= 0x00000200;
  }
  else
  {
    CKCU->AHBCCR &= 0xFFFFFDFF;
  }
}

/*********************************************************************************************************//**
  * @brief  Sets the CSIF Master Clock Prescaler.
  * @param  CSIF_Prescaler: specifies the CSIF Master Clock Prescaler value.
  *   This parameter must be even.
  * @retval None
  ************************************************************************************************************/
void CSIF_SetMasterClockPrescaler(u8 CSIF_Prescaler)
{
  /* Check the parameters */
  Assert_Param(IS_CSIF_PRESCALER(CSIF_Prescaler));

  CKCU->GCFGR |= (CSIF_Prescaler/2-1) << 24;
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

