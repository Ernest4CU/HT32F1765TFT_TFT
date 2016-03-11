/*********************************************************************************************************//**
 * @file    ht32f175x_275x_rstcu.c
 * @version V1.0
 * @date    11/16/2010
 * @brief   This library provides all the Reset Control Unit functions.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x_rstcu.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver HT32F175x/275x Peripheral Driver
  * @{
  */

/** @defgroup RSTCU RSTCU
  * @brief RSTCU driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup RSTCU_Private_TypesDefinitions RSTCU private types definitions
  * @{
  */

/**
  * @}
  */  /* End of RSTCU_Private_TypesDefinitions group */

/* Private define ------------------------------------------------------------------------------------------*/

/** @defgroup RSTCU_Private_Define RSTCU private defines
  * @{
  */

/**
  * @}
  */  /* End of RSTCU_Private_Define group */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup RSTCU_Private_Macro RSTCU private macros
  * @{
  */

/**
  * @}
  */  /* End of RSTCU_Private_Macro group */

/* Private variables ---------------------------------------------------------------------------------------*/

/** @defgroup RSTCU_Private_Variable RSTCU private variables
  * @{
  */

/**
  * @}
  */  /* End of RSTCU_Private_Variable group */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup RSTCU_Private_Function_Prototype RSTCU private function prototypes
  * @{
  */

/**
  * @}
  */  /* End of RSTCU_Private_Function_Prototype group */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup RSTCU_Private_Function RSTCU private functions
  * @{
  */

/*********************************************************************************************************//**
 * @brief Check whether the specific global reset flag is set or not.
 * @param RSTCU_RSTF: specify the reset flag.
 *        This parameter can be:
 *        @arg RSTCU_FLAG_SYSRST: Get system reset flag
 *        @arg RSTCU_FLAG_EXTRST: Get external pin reset flag
 *        @arg RSTCU_FLAG_WDTRST: Get WDT reset flag
 *        @arg RSTCU_FLAG_PORST : Get power on reset flag
 * @retval The status of RSTCU_RSTF, SET or RESET.
 ************************************************************************************************************/
FlagStatus RSTCU_GetResetFlagStatus(RSTCU_RSTF_TypeDef RSTCU_RSTF)
{
  u32 tmp;

  /* Check the parameters */
  Assert_Param(IS_RSTCU_FLAG(RSTCU_RSTF));

  tmp = (RSTCU->GRSR & ((u32)0x1<<RSTCU_RSTF));
  if (tmp != RESET)
  {
    return SET;
  }
  else
  {
    return RESET;
  }
}

/*********************************************************************************************************//**
 * @brief Clear the specific global reset flag.
 * @param RSTCU_RSTF: specify the reset flag.
 *        This parameter can be:
 *        @arg RSTCU_FLAG_SYSRST: Clear system reset flag
 *        @arg RSTCU_FLAG_EXTRST: Clear external pin reset flag
 *        @arg RSTCU_FLAG_WDTRST: Clear WDT reset flag
 *        @arg RSTCU_FLAG_PORST : Clear power on reset flag
 * @retval None
 ************************************************************************************************************/
void RSTCU_ClearResetFlag(RSTCU_RSTF_TypeDef RSTCU_RSTF)
{
  /* Check the parameters */
  Assert_Param(IS_RSTCU_FLAG(RSTCU_RSTF));

  RSTCU->GRSR = (u32)0x1 << RSTCU_RSTF;  /* Write 1 to clear */
}

/*********************************************************************************************************//**
 * @brief Clear all of the global reset flag.
 * @retval None
 ************************************************************************************************************/
void RSTCU_ClearAllResetFlag(void)
{
  RSTCU->GRSR = (vu32)0xF ;  /* Write 1 to clear */
}

/*********************************************************************************************************//**
 * @brief Enable APB peripheral 0 reset function.
 * @param RSTCU_APBP: specifies the APB peripheral 0.
 *        This parameter can be:
 *        @arg RSTCU_APBRST0_I2C0, RSTCU_APBRST0_I2C1,  RSTCU_APBRST0_SPI0, RSTCU_APBRST0_SPI1,
 *             RSTCU_APBRST0_USART0, RSTCU_APBRST0_USART1, RSTCU_APBRST0_AFIO, RSTCU_APBRST0_EXTI,
 *             RSTCU_APBRST0_PA, RSTCU_APBRST0_PB, RSTCU_APBRST0_PC, RSTCU_APBRST0_PD, RSTCU_APBRST0_PE,
 *              RSTCU_APBRST0_SCI
 * @param Cmd: new status of the peripheral reset.
 *        This parameter can be:
 *        @arg ENABLE
 *        @arg DISABLE
 * @retval None
 ************************************************************************************************************/
void RSTCU_APBPerip0Reset(u32 RSTCU_APBP, ControlStatus Cmd)
{
  /* Check the parameters */
  Assert_Param(IS_RSTCU_APBRST0(RSTCU_APBP));
  Assert_Param(IS_CONTROL_STATUS(Cmd));

  if (Cmd == ENABLE)
  {
    RSTCU->APBPRST0 |= RSTCU_APBP;
  }
  else
  {
    RSTCU->APBPRST0 &= ~RSTCU_APBP;
  }
}

/*********************************************************************************************************//**
 * @brief Enable APB peripheral 1 reset function.
 * @param RSTCU_APBP: specifies the APB peripheral 1.
 *        This parameter can be:
 *        @arg RSTCU_APBRST1_MCTM, RSTCU_APBRST1_WDT,  RSTCU_APBRST1_GPTM0, RSTCU_APBRST1_GPTM1,
 *             RSTCU_APBRST1_USB, RSTCU_APBRST1_BFTM0, RSTCU_APBRST1_BFTM1, RSTCU_APBRST1_OPA0,
 *             RSTCU_APBRST1_OPA1, RSTCU_APBRST1_ADC
 * @param Cmd: new status of the peripheral reset.
 *        This parameter can be:
 *        @arg ENABLE
 *        @arg DISABLE
 * @retval None
 ************************************************************************************************************/
void RSTCU_APBPerip1Reset(u32 RSTCU_APBP, ControlStatus Cmd)
{
  /* Check the parameters */
  Assert_Param(IS_RSTCU_APBRST1(RSTCU_APBP));
  Assert_Param(IS_CONTROL_STATUS(Cmd));

  if (Cmd == ENABLE)
  {
    RSTCU->APBPRST1 |= RSTCU_APBP;
  }
  else
  {
    RSTCU->APBPRST1 &= ~RSTCU_APBP;
  }
}

/*********************************************************************************************************//**
 * @brief Enable AHB peripheral reset function.
 * @param RSTCU_AHBP: specifies the AHB peripheral.
 *        This parameter can be:
 *        @arg RSTCU_AHBRST_PDMA, RSTCU_AHBRST_CSIF
 * @param Cmd: new status of the peripheral reset.
 *        This parameter can be:
 *        @arg ENABLE
 *        @arg DISABLE
 * @retval None
 ************************************************************************************************************/
void RSTCU_AHBPeripReset(u32 RSTCU_AHBP, ControlStatus Cmd)
{
  /* Check the parameters */
  Assert_Param(IS_RSTCU_AHBRST(RSTCU_AHBP));
  Assert_Param(IS_CONTROL_STATUS(Cmd));

  if (Cmd == ENABLE)
  {
    RSTCU->AHBPRST |= RSTCU_AHBP;
  }
  else
  {
    RSTCU->AHBPRST &= ~RSTCU_AHBP;
  }
}


/*********************************************************************************************************//**
 * @brief This function is used to check APB peripheral 0 reset state.
 * @param RSTCU_APBP: specify the APB peripheral 0.
 *        This parameter can be:
 *        @arg RSTCU_APBRST0_I2C0, RSTCU_APBRST0_I2C1,  RSTCU_APBRST0_SPI0, RSTCU_APBRST0_SPI1,
 *             RSTCU_APBRST0_USART0, RSTCU_APBRST0_USART1, RSTCU_APBRST0_AFIO, RSTCU_APBRST0_EXTI,
 *             RSTCU_APBRST0_PA, RSTCU_APBRST0_PB, RSTCU_APBRST0_PC, RSTCU_APBRST0_PD, RSTCU_APBRST0_PE,
 *             RSTCU_APBRST0_SCI
 * @retval The status of RSTCU_APBP, TRUE or FALSE.
 ************************************************************************************************************/
bool RSTCU_IS_APBPerip0ResetEnd(u32 RSTCU_APBP)
{
  bool tmp = FALSE;

  /* Check the parameters */
  Assert_Param(IS_RSTCU_APBRST0(RSTCU_APBP));

  if ((RSTCU->APBPRST0 & RSTCU_APBP) == 0)  /* Hardware clear automatically */
    tmp = TRUE;

  return tmp;
}

/*********************************************************************************************************//**
 * @brief This function is used to check APB peripheral 1 reset state.
 * @param RSTCU_APBP: specify the APB peripheral 1.
 *        This parameter can be:
 *        @arg RSTCU_APBRST1_MCTM, RSTCU_APBRST1_WDT,  RSTCU_APBRST1_GPTM0, RSTCU_APBRST1_GPTM1,
 *             RSTCU_APBRST1_USB, RSTCU_APBRST1_BFTM0, RSTCU_APBRST1_BFTM1, RSTCU_APBRST1_OPA0,
 *             RSTCU_APBRST1_OPA1, RSTCU_APBRST1_ADC
 * @retval The status of RSTCU_APBP, TRUE or FALSE.
 ************************************************************************************************************/
bool RSTCU_IS_APBPerip1ResetEnd(u32 RSTCU_APBP)
{
  bool tmp = FALSE;

  /* Check the parameters */
  Assert_Param(IS_RSTCU_APBRST1(RSTCU_APBP));

  if ((RSTCU->APBPRST1 & RSTCU_APBP) == 0)  /* Hardware clear automatically */
    tmp = TRUE;

  return tmp;
}

/*********************************************************************************************************//**
 * @brief This function is used to check AHB peripheral reset state.
 * @param RSTCU_AHBP: specify the AHB peripheral.
 *        This parameter can be:
 *        @arg  RSTCU_AHBRST_DMA, RSTCU_AHBRST_CSIF
 * @retval The status of RSTCU_AHBP, TRUE or FALSE.
 ************************************************************************************************************/
bool RSTCU_IS_AHBPeripResetEnd(u32 RSTCU_AHBP)
{
  bool tmp = FALSE;

  /* Check the parameters */
  Assert_Param(IS_RSTCU_AHBRST(RSTCU_AHBP));

  if ((RSTCU->AHBPRST & RSTCU_AHBP) == 0)  /* Hardware clear automatically */
    tmp = TRUE;

  return tmp;
}


/**
  * @}
  */  /* End of RSTCU_Private_Function group */

/**
  * @}
  */  /* End of RSTCU peripheral group */

/**
  * @}
  */  /* End of HT32F175x_275x_Peripheral_Driver group */
