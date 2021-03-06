/*********************************************************************************************************//**
 * @file    GPIO/InputOutput/ht32f175x_275x_it.c
 * @version V1.0
 * @date    05/11/2011
 * @brief   This file provides all interrupt service routine.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x_it.h"

/** @addtogroup HT32F175x_275x_Peripheral_Examples HT32F175x/275x Peripheral Examples
  * @{
  */

/** @addtogroup GPIO_Examples GPIO
  * @{
  */

/** @addtogroup InputOutput
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/
/* Private define ------------------------------------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------------------------------------*/
extern void SPI_LCD_TimingDelay(void);
/*********************************************************************************************************//**
 * @brief   This function handles NMI exception.
 * @retval  None
 ************************************************************************************************************/
void NMI_Handler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Hard Fault exception.
 * @retval  None
 ************************************************************************************************************/
void HardFault_Handler(void)
{
  while (1);
}

/*********************************************************************************************************//**
 * @brief   This function handles Memory Manage exception.
 * @retval  None
 ************************************************************************************************************/
void MemManage_Handler(void)
{
  while (1);
}

/*********************************************************************************************************//**
 * @brief   This function handles Bus Fault exception.
 * @retval  None
 ************************************************************************************************************/
void BusFault_Handler(void)
{
  while (1);
}

/*********************************************************************************************************//**
 * @brief   This function handles Usage Fault exception.
 * @retval  None
 ************************************************************************************************************/
void UsageFault_Handler(void)
{
  while (1);
}

/*********************************************************************************************************//**
 * @brief   This function handles SVCall exception.
 * @retval  None
 ************************************************************************************************************/
void SVC_Handler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Debug Monitor exception.
 * @retval  None
 ************************************************************************************************************/
void DebugMon_Handler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PendSVC exception.
 * @retval  None
 ************************************************************************************************************/
void PendSV_Handler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles SysTick Handler.
 * @retval  None
 ************************************************************************************************************/
void SysTick_Handler(void)
{
	SPI_LCD_TimingDelay();
}

/*********************************************************************************************************//**
 * @brief   This function handles Clock Ready interrupt.
 * @retval  None
 ************************************************************************************************************/
void CKRDY_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Low Voltage Detection interrupt.
 * @retval  None
 ************************************************************************************************************/
void LVD_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Brown Out Detection interrupt.
 * @retval  None
 ************************************************************************************************************/
void BOD_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles WDT interrupt.
 * @retval  None
 ************************************************************************************************************/
void WDT_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles RTC interrupt.
 * @retval  None
 ************************************************************************************************************/
void RTC_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Flash interrupt.
 * @retval  None
 ************************************************************************************************************/
void FLASH_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Event Wake Up interrupt.
 * @retval  None
 ************************************************************************************************************/
void EVWUP_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles WAKEUP pin interrupt.
 * @retval  None
 ************************************************************************************************************/
void LPWUP_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI0 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI0_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI1 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI1_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI2 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI2_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI3 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI3_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI4 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI4_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI5 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI5_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI6 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI6_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI7 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI7_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI8 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI8_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI9 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI9_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI10 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI10_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI11 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI11_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI12 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI12_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI13 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI13_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI14 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI14_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI15 interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI15_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Comparator interrupt.
 * @retval  None
 ************************************************************************************************************/
void COMP_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles ADC interrupt.
 * @retval  None
 ************************************************************************************************************/
void ADC_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles MCTM BRK interrupt.
 * @retval  None
 ************************************************************************************************************/
void MCTMBRK_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles MCTM UP interrupt.
 * @retval  None
 ************************************************************************************************************/
void MCTMUP_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles MCTM TR interrupt.
 * @retval  None
 ************************************************************************************************************/
void MCTMTR_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles MCTM CC interrupt.
 * @retval  None
 ************************************************************************************************************/
void MCTMCC_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles General Purpose Timer 0 interrupt.
 * @retval  None
 ************************************************************************************************************/
void GPTM0_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles General Purpose Timer 1 interrupt.
 * @retval  None
 ************************************************************************************************************/
void GPTM1_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Basic Function Timer 0 interrupt.
 * @retval  None
 ************************************************************************************************************/
void BFTM0_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Basic Function Timer 1 interrupt.
 * @retval  None
 ************************************************************************************************************/
void BFTM1_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles I2C0 interrupt.
 * @retval  None
 ************************************************************************************************************/
void I2C0_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles I2C1 interrupt.
 * @retval  None
 ************************************************************************************************************/
void I2C1_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles SPI0 interrupt.
 * @retval  None
 ************************************************************************************************************/
void SPI0_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles SPI1 interrupt.
 * @retval  None
 ************************************************************************************************************/
void SPI1_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles USART0 interrupt.
 * @retval  None
 ************************************************************************************************************/
void USART0_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles USART1 interrupt.
 * @retval  None
 ************************************************************************************************************/
void USART1_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Smart Card interrupt.
 * @retval  None
 ************************************************************************************************************/
void SCI_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles USB interrupt.
 * @retval  None
 ************************************************************************************************************/
void USB_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH0 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH0_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH1 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH1_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH2 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH2_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH3 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH3_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH4 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH4_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH5 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH5_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH6 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH6_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH7 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH7_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH8 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH8_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH9 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH9_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH10 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH10_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PDMA_CH11 interrupt.
 * @retval  None
 ************************************************************************************************************/
void PDMA_CH11_IRQHandler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles CMOS Sensor interrupt.
 * @retval  None
 ************************************************************************************************************/
void CSIF_IRQHandler(void)
{
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
