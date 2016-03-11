/*********************************************************************************************************//**
 * @file    ht32f175x_275x_lib.h
 * @version V1.0
 * @date    09/08/2011
 * @brief   The header file includes all the header files of the libraries.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __HT32F175x_275x_LIB_H
#define __HT32F175x_275x_LIB_H

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x_conf.h"
#include <stdio.h>

/* Peripheral declaration                                                                                   */

#if (HT32_LIB_DEBUG == 0)

/* Non Debug Mode                                                                                           */
/* Periperals defined in ht32f175x_275x.h                                                                   */

#else

/* Debug Mode                                                                                               */
#undef USART0
#undef USART1
#undef SPI0
#undef SPI1
#undef ADC
#undef CMP_OP0
#undef CMP_OP1
#undef AFIO
#undef GPIOA
#undef GPIOB
#undef GPIOC
#undef GPIOD
#undef GPIOE
#undef EXTI
#undef MCTM
#undef SCI
#undef I2C0
#undef I2C1
#undef USB
#undef USBEP0
#undef USBEP1
#undef USBEP2
#undef USBEP3
#undef USBEP4
#undef USBEP5
#undef USBEP6
#undef USBEP7
#undef WDT
#undef RTC
#undef PWRCU
#undef GPTM0
#undef GPTM1
#undef BFTM0
#undef BFTM1
#undef FLASH
#undef CKCU
#undef RSTCU
#undef PDMA
#undef CSIF

#if _USART0
  EXT USART_TypeDef            *USART0;
#endif

#if _USART1
  EXT USART_TypeDef            *USART1;
#endif

#if _SPI0
  EXT SPI_TypeDef              *SPI0;
#endif

#if _SPI1
  EXT SPI_TypeDef              *SPI1;
#endif

#if _ADC
  EXT ADC_TypeDef              *ADC;
#endif

#if _CMP_OP0
  EXT CMP_OP_TypeDef           *CMP_OP0;
#endif

#if _CMP_OP1
  EXT CMP_OP_TypeDef           *CMP_OP1;
#endif

#if _AFIO
  EXT AFIO_TypeDef             *AFIO;
#endif

#if _GPIOA
  EXT GPIO_TypeDef             *GPIOA;
#endif

#if _GPIOB
  EXT GPIO_TypeDef             *GPIOB;
#endif

#if _GPIOC
  EXT GPIO_TypeDef             *GPIOC;
#endif

#if _GPIOD
  EXT GPIO_TypeDef             *GPIOD;
#endif

#if _GPIOE
  EXT GPIO_TypeDef             *GPIOE;
#endif

#if _EXTI
  EXT EXTI_TypeDef             *EXTI;
#endif

#if _MCTM
  EXT MCTM_TypeDef             *MCTM;
#endif

#if _SCI
  EXT SCI_TypeDef              *SCI;
#endif

#if _I2C0
  EXT I2C_TypeDef              *I2C0;
#endif

#if _I2C1
  EXT I2C_TypeDef              *I2C1;
#endif

#if _USB
  EXT USB_TypeDef              *USB;
#endif

#if _USBEP0
  EXT USBEP_TypeDef            *USBEP0;
#endif

#if _USBEP1
  EXT USBEP_TypeDef            *USBEP1;
#endif

#if _USBEP2
  EXT USBEP_TypeDef            *USBEP2;
#endif

#if _USBEP3
  EXT USBEP_TypeDef            *USBEP3;
#endif

#if _USBEP4
  EXT USBEP_TypeDef            *USBEP4;
#endif

#if _USBEP5
  EXT USBEP_TypeDef            *USBEP5;
#endif

#if _USBEP6
  EXT USBEP_TypeDef            *USBEP6;
#endif

#if _USBEP7
  EXT USBEP_TypeDef            *USBEP7;
#endif

#if _WDT
  EXT WDT_TypeDef              *WDT;
#endif

#if _RTC
  EXT RTC_TypeDef              *RTC;
#endif

#if _PWRCU
  EXT PWRCU_TypeDef            *PWRCU;
#endif

#if _GPTM0
  EXT GPTM_TypeDef             *GPTM0;
#endif

#if _GPTM1
  EXT GPTM_TypeDef             *GPTM1;
#endif

#if _BFTM0
  EXT BFTM_TypeDef             *BFTM0;
#endif

#if _BFTM1
  EXT BFTM_TypeDef             *BFTM1;
#endif

#if _FLASH
  EXT FLASH_TypeDef            *FLASH;
#endif

#if _CKCU
  EXT CKCU_TypeDef             *CKCU;
#endif

#if _RSTCU
  EXT RSTCU_TypeDef            *RSTCU;
#endif

#if _PDMA
  EXT PDMA_TypeDef             *PDMA;
#endif

#if _CSIF
  EXT CSIF_TypeDef             *CSIF;
#endif

#endif /* DEBUG --------------------------------------------------------------------------------------------*/

#if (HT32_LIB_DEBUG == 1)
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *   which reports the name of the source file and the source
  *   line number of the call that failed.
  *   If expr is true, it returns no value.
  * @retval None
  */
#define Assert_Param(expr) ((expr) ? (void)0 : assert_error((u8 *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- ------------------------------*/
void assert_error(u8* file, u32 line);

#else

#define Assert_Param(expr) ((void)0)

#endif /* DEBUG --------------------------------------------------------------------------------------------*/


/* APB Peripherals                                                                                          */
#if _USART
  #include "ht32f175x_275x_usart.h"
#endif

#if _SPI
  #include "ht32f175x_275x_spi.h"
#endif

#if _ADC
  #include "ht32f175x_275x_adc.h"
#endif

#if _CMP_OP
  #include "ht32f175x_275x_cmp_op.h"
#endif

#if _GPIO
  #include "ht32f175x_275x_gpio.h"
#endif

#if _EXTI
  #include "ht32f175x_275x_exti.h"
#endif

#if _MCTM
  #include "ht32f175x_275x_mctm.h"
#endif

#if _SCI
  #include "ht32f175x_275x_sci.h"
#endif

#if _I2C
  #include "ht32f175x_275x_i2c.h"
#endif

#if _USB
  #include "ht32f175x_275x_usbd.h"
#endif

#if _WDT
  #include "ht32f175x_275x_wdt.h"
#endif

#if _RTC
  #include "ht32f175x_275x_rtc.h"
#endif

#if _PWRCU
  #include "ht32f175x_275x_pwrcu.h"
#endif

#if _GPTM
  #include "ht32f175x_275x_gptm.h"
#endif

#if _BFTM
  #include "ht32f175x_275x_bftm.h"
#endif

/* AHB Peripherals                                                                                          */
#if _FLASH
  #include "ht32f175x_275x_flash.h"
#endif

#if _CKCU
  #include "ht32f175x_275x_ckcu.h"
#endif

#if _RSTCU
  #include "ht32f175x_275x_rstcu.h"
#endif

#if _PDMA
  #include "ht32f175x_275x_pdma.h"
#endif

#if _CSIF
  #include "ht32f275x_csif.h"
#endif

/* Cortex-M3                                                                                                */
#if _MISC
  #include "ht32f175x_275x_misc.h"
#endif

#if (_RETARGET)
  #if defined ( __GNUC__ )
    #undef getchar
    #define getchar SERIAL_GetChar
  #endif
  #include "ht32f175x_275x_serial.h"
#endif

/* Exported types ------------------------------------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------------------------------------*/
#if (HT32_LIB_DEBUG == 1)
void debug(void);
#endif

#endif /* __HT32F175x_275x_LIB_H ---------------------------------------------------------------------------*/
