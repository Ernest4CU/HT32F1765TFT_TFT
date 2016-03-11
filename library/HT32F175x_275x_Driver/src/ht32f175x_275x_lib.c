/*********************************************************************************************************//**
 * @file    ht32f175x_275x_lib.c
 * @version V1.0
 * @date    09/08/2011
 * @brief   Initialization of the library pointers for debug mode.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

#define EXT

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x.h"

/* Private functions ---------------------------------------------------------------------------------------*/

#if (HT32_LIB_DEBUG == 1)
#warning "Library debug mode has been enabled."
#warning "Remember to disable after the debug operation has been finished."
/*********************************************************************************************************//**
 * @brief  Initialization of the library pointers for debug mode.
 * @retval None
 ************************************************************************************************************/
void debug(void)
{
#if _USART0
  USART0 = (USART_TypeDef *) USART0_BASE;
#endif

#if _USART1
  USART1 = (USART_TypeDef *) USART1_BASE;
#endif

#if _SPI0
  SPI0 = (SPI_TypeDef *) SPI0_BASE;
#endif

#if _SPI1
  SPI1 = (SPI_TypeDef *) SPI1_BASE;
#endif

#if _ADC
  ADC = (ADC_TypeDef *) ADC_BASE;
#endif

#if _CMP_OP0
  CMP_OP0 = (CMP_OP_TypeDef *) CMP_OP0_BASE;
#endif

#if _CMP_OP1
  CMP_OP1 = (CMP_OP_TypeDef *) CMP_OP1_BASE;
#endif

#if _AFIO
  AFIO = (AFIO_TypeDef *) AFIO_BASE;
#endif

#if _GPIOA
  GPIOA = (GPIO_TypeDef *) GPIOA_BASE;
#endif

#if _GPIOB
  GPIOB = (GPIO_TypeDef *) GPIOB_BASE;
#endif

#if _GPIOC
  GPIOC = (GPIO_TypeDef *) GPIOC_BASE;
#endif

#if _GPIOD
  GPIOD = (GPIO_TypeDef *) GPIOD_BASE;
#endif

#if _GPIOE
  GPIOE = (GPIO_TypeDef *) GPIOE_BASE;
#endif

#if _EXTI
  EXTI = (EXTI_TypeDef *) EXTI_BASE;
#endif

#if _MCTM
  MCTM = (MCTM_TypeDef *) MCTM_BASE;
#endif

#if _SCI
  SCI = (SCI_TypeDef *) SCI_BASE;
#endif

#if _I2C0
  I2C0 = (I2C_TypeDef *) I2C0_BASE;
#endif
#if _I2C1
  I2C1 = (I2C_TypeDef *) I2C1_BASE;
#endif

#if _USB
  USB = (USB_TypeDef *) USB_BASE;
  USBEP0 = (USBEP_TypeDef *) USB_EP0_BASE;
  USBEP1 = (USBEP_TypeDef *) USB_EP1_BASE;
  USBEP2 = (USBEP_TypeDef *) USB_EP2_BASE;
  USBEP3 = (USBEP_TypeDef *) USB_EP3_BASE;
  USBEP4 = (USBEP_TypeDef *) USB_EP4_BASE;
  USBEP5 = (USBEP_TypeDef *) USB_EP5_BASE;
  USBEP6 = (USBEP_TypeDef *) USB_EP6_BASE;
  USBEP7 = (USBEP_TypeDef *) USB_EP7_BASE;
#endif

#if _WDT
  WDT = (WDT_TypeDef *) WDT_BASE;
#endif

#if _RTC
  RTC = (RTC_TypeDef *) RTC_BASE;
#endif

#if _PWRCU
  PWRCU = (PWRCU_TypeDef *) PWRCU_BASE;
#endif

#if _GPTM0
  GPTM0 = (GPTM_TypeDef *) GPTM0_BASE;
#endif

#if _GPTM1
  GPTM1 = (GPTM_TypeDef *) GPTM1_BASE;
#endif

#if _BFTM0
  BFTM0 = (BFTM_TypeDef *) BFTM0_BASE;
#endif
#if _BFTM1
  BFTM1 = (BFTM_TypeDef *) BFTM1_BASE;
#endif

#if _FLASH
  FLASH = (FLASH_TypeDef *) FLASH_BASE;
#endif

#if _CKCU
  CKCU = (CKCU_TypeDef *) CKCU_BASE;
#endif

#if _RSTCU
  RSTCU = (RSTCU_TypeDef *) RSTCU_BASE;
#endif

#if _PDMA
  PDMA = (PDMA_TypeDef *) PDMA_BASE;
#endif

#if _CSIF
  CSIF = (CSIF_TypeDef *) CSIF_BASE;
#endif

}

#endif /* HT32_LIB_DEBUG -----------------------------------------------------------------------------------*/
