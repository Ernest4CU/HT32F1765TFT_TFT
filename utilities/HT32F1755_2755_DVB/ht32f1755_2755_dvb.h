/*********************************************************************************************************//**
 * @file    ht32f1755_2755_dvb.h
 * @version V1.0
 * @date    09/08/2011
 * @brief   Header file for ht32f1755_2755_dvb.c module.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/
#ifndef __HT32F1755_2755_DVB_H
#define __HT32F1755_2755_DVB_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x.h"
#include "i2c_eeprom.h"
#include "spi_flash.h"
#include "spi_lcd.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup HT32F1755_2755_Development_Board
  * @{
  */

/** @addtogroup HT32F1755_2755_DVB
  * @{
  */

/** @defgroup HT32F1755_2755_DVB_Exported_Types HT32F1755/2755 DVB exported types
  * @{
  */
/**
  * @}
  */

/** @defgroup HT32F1755_2755_DVB_Exported_Constants HT32F1755/2755 DVB exported constants
  * @{
  */

#define DVB_GPIO_NBR                      5
#define DVB_GPIOA_ID                      0
#define DVB_GPIOB_ID                      1
#define DVB_GPIOC_ID                      2
#define DVB_GPIOD_ID                      3
#define DVB_GPIOE_ID                      4

/** @addtogroup HT32F1755_2755_DVB_LED
  * @{
  */
#define LEDn                        3

#define LED1_GPIO_ID                DVB_GPIOA_ID
#define LED1_GPIO_PORT              ((GPIO_TypeDef*)GPIOA_BASE)
#define LED1_GPIO_PIN               GPIO_PIN_15
#define LED1_AFIO_MODE              AFIO_MODE_DEFAULT
#define LED1_AFIO_PIN               AFIO_PIN_15

#define LED2_GPIO_ID                DVB_GPIOB_ID
#define LED2_GPIO_PORT              ((GPIO_TypeDef*)GPIOB_BASE)
#define LED2_GPIO_PIN               GPIO_PIN_0
#define LED2_AFIO_MODE              AFIO_MODE_DEFAULT
#define LED2_AFIO_PIN               AFIO_PIN_0

#define LED3_GPIO_ID                DVB_GPIOB_ID
#define LED3_GPIO_PORT              ((GPIO_TypeDef*)GPIOB_BASE)
#define LED3_GPIO_PIN               GPIO_PIN_1
#define LED3_AFIO_MODE              AFIO_MODE_DEFAULT
#define LED3_AFIO_PIN               AFIO_PIN_1
/**
  * @}
  */

/** @addtogroup HT32F1755_2755_DVB_BUTTON
  * @{
  */
#define BUTTONn                     3

/**
 * @brief Wakeup push-button
 */
#define WAKEUP_BUTTON_GPIO_ID       DVB_GPIOB_ID
#define WAKEUP_BUTTON_GPIO_PORT     ((GPIO_TypeDef*)GPIOB_BASE)
#define WAKEUP_BUTTON_GPIO_PIN      GPIO_PIN_6
#define WAKEUP_BUTTON_AFIO_MODE     AFIO_MODE_1
#define WAKEUP_BUTTON_AFIO_PIN      AFIO_PIN_6

#define WAKEUP_BUTTON_EXTI_CHANNEL  EXTI_CHANNEL_6
#define WAKEUP_BUTTON_AFIO_ESS      AFIO_ESS_PB
#define WAKEUP_BUTTON_AFIO_EXTI_CH  AFIO_EXTI_CH_6
#define WAKEUP_BUTTON_IRQn          EXTI6_IRQn
/**
 * @brief Key1 push-button
 */
#define KEY1_BUTTON_GPIO_ID         DVB_GPIOE_ID
#define KEY1_BUTTON_GPIO_PORT       ((GPIO_TypeDef*)GPIOE_BASE)
#define KEY1_BUTTON_GPIO_PIN        GPIO_PIN_10
#define KEY1_BUTTON_AFIO_MODE       AFIO_MODE_DEFAULT
#define KEY1_BUTTON_AFIO_PIN        AFIO_PIN_10

#define KEY1_BUTTON_EXTI_CHANNEL    EXTI_CHANNEL_10
#define KEY1_BUTTON_AFIO_ESS        AFIO_ESS_PE
#define KEY1_BUTTON_AFIO_EXTI_CH    AFIO_EXTI_CH_10
#define KEY1_BUTTON_IRQn            EXTI10_IRQn

/**
 * @brief Key2 push-button
 */
#define KEY2_BUTTON_GPIO_ID         DVB_GPIOE_ID
#define KEY2_BUTTON_GPIO_PORT       ((GPIO_TypeDef*)GPIOE_BASE)
#define KEY2_BUTTON_GPIO_PIN        GPIO_PIN_9
#define KEY2_BUTTON_AFIO_MODE       AFIO_MODE_DEFAULT
#define KEY2_BUTTON_AFIO_PIN        AFIO_PIN_9

#define KEY2_BUTTON_EXTI_CHANNEL    EXTI_CHANNEL_9
#define KEY2_BUTTON_AFIO_ESS        AFIO_ESS_PE
#define KEY2_BUTTON_AFIO_EXTI_CH    AFIO_EXTI_CH_9
#define KEY2_BUTTON_IRQn            EXTI9_IRQn
/**
  * @}
  */

/** @addtogroup HT32F1755_2755_DVB_BUZZER
  * @{
  */
#define BUZZER_GPIO_ID         DVB_GPIOA_ID
#define BUZZER_GPIO_PORT       ((GPIO_TypeDef*)GPIOA_BASE)
#define BUZZER_GPIO_PIN        GPIO_PIN_14
#define BUZZER_AFIO_MODE       AFIO_MODE_1
#define BUZZER_AFIO_PIN        AFIO_PIN_14

#define BUZZER_GPTM            ((GPTM_TypeDef*)GPTM1_BASE)
#define BUZZER_BUZZER_CLK      CKCU_APBEN1_GPTM1
#define BUZZER_GPTM_CHANNEL    GPTM_CH_2
#define BUZZER_IRQn            GPTM1_IRQn
/**
  * @}
  */

/** @addtogroup HT32F1755_2755_DVB_COM
  * @{
  */
#define COMn                             2

/**
 * @brief Definition for COM port1, connected to USART0
 */
#define DVB_COM1_USART              ((USART_TypeDef*)USART0_BASE)
#define DVB_COM1_CLK                CKCU_APBEN0_USART0

#define DVB_COM1_TX_GPIO_ID         DVB_GPIOC_ID
#define DVB_COM1_TX_AFIO_MODE       AFIO_MODE_3
#define DVB_COM1_TX_AFIO_PIN        AFIO_PIN_8

#define DVB_COM1_RX_GPIO_ID         DVB_GPIOC_ID
#define DVB_COM1_RX_AFIO_MODE       AFIO_MODE_3
#define DVB_COM1_RX_AFIO_PIN        AFIO_PIN_10

#define DVB_COM1_IRQn               USART0_IRQn
/**
 * @brief Definition for COM port2, connected to USART1
 */
#define DVB_COM2_USART              ((USART_TypeDef*)USART1_BASE)
#define DVB_COM2_CLK                CKCU_APBEN0_USART1

#define DVB_COM2_TX_GPIO_ID         DVB_GPIOC_ID
#define DVB_COM2_TX_AFIO_MODE       AFIO_MODE_1
#define DVB_COM2_TX_AFIO_PIN        AFIO_PIN_4

#define DVB_COM2_RX_GPIO_ID         DVB_GPIOC_ID
#define DVB_COM2_RX_AFIO_MODE       AFIO_MODE_1
#define DVB_COM2_RX_AFIO_PIN        AFIO_PIN_5

#define DVB_COM2_CTS_GPIO_ID        DVB_GPIOB_ID
#define DVB_COM2_CTS_AFIO_MODE      AFIO_MODE_1
#define DVB_COM2_CTS_AFIO_PIN       AFIO_PIN_14

#define DVB_COM2_RTS_GPIO_ID        DVB_GPIOB_ID
#define DVB_COM2_RTS_AFIO_MODE      AFIO_MODE_1
#define DVB_COM2_RTS_AFIO_PIN       AFIO_PIN_15

#define DVB_COM2_IRQn               USART1_IRQn
/**
  * @}
  */
  
/**
 * @brief Definition for IDA, connected to USART1
 */
#define DVB_IRDA_USART              ((USART_TypeDef*)USART1_BASE)
#define DVB_IRDA_CLK                CKCU_APBEN0_USART1

#define DVB_IRDA_TX_GPIO_ID         DVB_GPIOE_ID
#define DVB_IRDA_TX_AFIO_MODE       AFIO_MODE_3
#define DVB_IRDA_TX_AFIO_PIN        AFIO_PIN_14

#define DVB_IRDA_RX_GPIO_ID         DVB_GPIOC_ID
#define DVB_IRDA_RX_AFIO_MODE       AFIO_MODE_1
#define DVB_IRDA_RX_AFIO_PIN        AFIO_PIN_5

#define IRDA_EN_GPIO_ID             DVB_GPIOC_ID
#define IRDA_EN_GPIO_PORT           ((GPIO_TypeDef*)GPIOC_BASE)
#define IRDA_EN_GPIO_PIN            GPIO_PIN_9
#define IRDA_EN_AFIO_MODE           AFIO_MODE_DEFAULT
#define IRDA_EN_AFIO_PIN            AFIO_PIN_9

/**
  * @}
  */  

/** @addtogroup HT32F1755_2755_DVB_SPI_FLASH
  * @{
  */

/**
 * @brief SPI Flash interface pins
 */
#define FLASH_SPI                       ((SPI_TypeDef*)SPI1_BASE)

#define FLASH_SPI_CLK                   CKCU_APBEN0_SPI1

#define FLASH_SPI_SEL_GPIO_ID           DVB_GPIOC_ID
#define FLASH_SPI_SEL_GPIO_PORT         ((GPIO_TypeDef*)GPIOC_BASE)
#define FLASH_SPI_SEL_GPIO_PIN          GPIO_PIN_0
#define FLASH_SPI_SEL_AFIO_MODE         AFIO_MODE_DEFAULT
#define FLASH_SPI_SEL_AFIO_PIN          AFIO_PIN_0

#define FLASH_SPI_SCK_GPIO_ID           DVB_GPIOC_ID
#define FLASH_SPI_SCK_AFIO_MODE         AFIO_MODE_1
#define FLASH_SPI_SCK_AFIO_PIN          AFIO_PIN_1

#define FLASH_SPI_MOSI_GPIO_ID          DVB_GPIOC_ID
#define FLASH_SPI_MOSI_AFIO_MODE        AFIO_MODE_1
#define FLASH_SPI_MOSI_AFIO_PIN         AFIO_PIN_2

#define FLASH_SPI_MISO_GPIO_ID          DVB_GPIOC_ID
#define FLASH_SPI_MISO_AFIO_MODE        AFIO_MODE_1
#define FLASH_SPI_MISO_AFIO_PIN         AFIO_PIN_3
/**
  * @}
  */

/** @addtogroup HT32F1755_2755_DVB_SPI_LCD
  * @{
  */

/**
 * @brief SPI LCD interface pins
 */
#define LCD_SPI                       ((SPI_TypeDef*)SPI0_BASE)

#define LCD_SPI_CLK                   CKCU_APBEN0_SPI0

#define LCD_SPI_SEL_GPIO_ID           DVB_GPIOD_ID
#define LCD_SPI_SEL_GPIO_PORT         ((GPIO_TypeDef*)GPIOD_BASE)
#define LCD_SPI_SEL_GPIO_PIN          GPIO_PIN_0
#define LCD_SPI_SEL_AFIO_MODE         AFIO_MODE_2
#define LCD_SPI_SEL_AFIO_PIN          AFIO_PIN_0

#define LCD_SPI_SCK_GPIO_ID           DVB_GPIOD_ID
#define LCD_SPI_SCK_AFIO_MODE         AFIO_MODE_2
#define LCD_SPI_SCK_AFIO_PIN          AFIO_PIN_1

#define LCD_SPI_MOSI_GPIO_ID          DVB_GPIOD_ID
#define LCD_SPI_MOSI_AFIO_MODE        AFIO_MODE_2
#define LCD_SPI_MOSI_AFIO_PIN         AFIO_PIN_2

#define LCD_SPI_MISO_GPIO_ID          DVB_GPIOD_ID
#define LCD_SPI_MISO_AFIO_MODE        AFIO_MODE_2
#define LCD_SPI_MISO_AFIO_PIN         AFIO_PIN_3

#define LCD_SPI_BL_GPIO_ID            DVB_GPIOA_ID
#define LCD_SPI_BL_GPIO_PORT          ((GPIO_TypeDef*)GPIOA_BASE)
#define LCD_SPI_BL_GPIO_PIN           GPIO_PIN_13
#define LCD_SPI_BL_AFIO_MODE          AFIO_MODE_DEFAULT
#define LCD_SPI_BL_AFIO_PIN           AFIO_PIN_13

#define LCD_SPI_RESET_GPIO_ID         DVB_GPIOD_ID
#define LCD_SPI_RESET_GPIO_PORT       ((GPIO_TypeDef*)GPIOD_BASE)
#define LCD_SPI_RESET_GPIO_PIN        GPIO_PIN_6
#define LCD_SPI_RESET_AFIO_MODE       AFIO_MODE_DEFAULT
#define LCD_SPI_RESET_AFIO_PIN        AFIO_PIN_6
/**
  * @}
  */

/** @addtogroup HT32F1755_2755_DVB_I2C_EEPROM
  * @{
  */

/**
 * @brief I2C EEPROM interface pins
 */
#define EEPROM_I2C                      ((I2C_TypeDef*)I2C1_BASE)

#define EEPROM_I2C_CLK                  CKCU_APBEN0_I2C1

#define EEPROM_I2C_SCL_GPIO_ID          DVB_GPIOC_ID
#define EEPROM_I2C_SCL_AFIO_MODE        AFIO_MODE_1
#define EEPROM_I2C_SCL_AFIO_PIN         AFIO_PIN_6

#define EEPROM_I2C_SDA_GPIO_ID          DVB_GPIOC_ID
#define EEPROM_I2C_SDA_AFIO_MODE        AFIO_MODE_1
#define EEPROM_I2C_SDA_AFIO_PIN         AFIO_PIN_7
/**
  * @}
  */

/** @addtogroup HT32F1755_2755_DVB_SCI_SMARTCARD
  * @{
  */

/**
 * @brief SCI SmarCard interface pins
 */
#define SMARTCARD_SCI                   ((SCI_TypeDef*)SCI_BASE)

#define SMARTCARD_SCI_CLK               CKCU_APBEN0_SCI

#define SMARTCARD_SCI_CLK_GPIO_ID       DVB_GPIOC_ID
#define SMARTCARD_SCI_CLK_AFIO_MODE     AFIO_MODE_1
#define SMARTCARD_SCI_CLK_AFIO_PIN      AFIO_PIN_13

#define SMARTCARD_SCI_DIO_GPIO_ID       DVB_GPIOC_ID
#define SMARTCARD_SCI_DIO_AFIO_MODE     AFIO_MODE_1
#define SMARTCARD_SCI_DIO_AFIO_PIN      AFIO_PIN_14

#define SMARTCARD_SCI_DET_GPIO_ID       DVB_GPIOC_ID
#define SMARTCARD_SCI_DET_AFIO_MODE     AFIO_MODE_1
#define SMARTCARD_SCI_DET_AFIO_PIN      AFIO_PIN_15

#define SMARTCARD_SCI_CMDVCC_GPIO_ID    DVB_GPIOE_ID
#define SMARTCARD_SCI_CMDVCC_GPIO_PORT  ((GPIO_TypeDef*)GPIOE_BASE)
#define SMARTCARD_SCI_CMDVCC_GPIO_PIN   GPIO_PIN_1
#define SMARTCARD_SCI_CMDVCC_AFIO_MODE  AFIO_MODE_DEFAULT
#define SMARTCARD_SCI_CMDVCC_AFIO_PIN   AFIO_PIN_1

#define SMARTCARD_SCI_RSTIN_GPIO_ID     DVB_GPIOE_ID
#define SMARTCARD_SCI_RSTIN_GPIO_PORT   ((GPIO_TypeDef*)GPIOE_BASE)
#define SMARTCARD_SCI_RSTIN_GPIO_PIN    GPIO_PIN_0
#define SMARTCARD_SCI_RSTIN_AFIO_MODE   AFIO_MODE_DEFAULT
#define SMARTCARD_SCI_RSTIN_AFIO_PIN    AFIO_PIN_0

#define SMARTCARD_SCI_1_8V_GPIO_ID      DVB_GPIOE_ID
#define SMARTCARD_SCI_1_8V_GPIO_PORT    ((GPIO_TypeDef*)GPIOE_BASE)
#define SMARTCARD_SCI_1_8V_GPIO_PIN     GPIO_PIN_2
#define SMARTCARD_SCI_1_8V_AFIO_MODE    AFIO_MODE_DEFAULT
#define SMARTCARD_SCI_1_8V_AFIO_PIN     AFIO_PIN_2

#define SMARTCARD_SCI_3V_5V_GPIO_ID     DVB_GPIOE_ID
#define SMARTCARD_SCI_3V_5V_GPIO_PORT   ((GPIO_TypeDef*)GPIOE_BASE)
#define SMARTCARD_SCI_3V_5V_GPIO_PIN    GPIO_PIN_3
#define SMARTCARD_SCI_3V_5V_AFIO_MODE   AFIO_MODE_DEFAULT
#define SMARTCARD_SCI_3V_5V_AFIO_PIN    AFIO_PIN_3
/**
  * @}
  */

/** @addtogroup HT32F1755_2755_DVB_CSIF_CMOSSENSOR
  * @{
  */

/**
 * @brief CSIF CMOS sensor interface pins
 */
#define CMOSSENSOR_CSIF                 ((CSIF_TypeDef*)CSIF_BASE)

#define CMOSSENSOR_CSIF_CLK             CKCU_AHBEN_CSIF

#define CMOSSENSOR_CSIF_MCLK_GPIO_PIN   DVB_GPIOC_ID
#define CMOSSENSOR_CSIF_MCLK_AFIO_MODE  AFIO_MODE_3
#define CMOSSENSOR_CSIF_MCLK_AFIO_PIN   AFIO_PIN_12

#define CMOSSENSOR_CSIF_PCLK_GPIO_PIN   DVB_GPIOC_ID
#define CMOSSENSOR_CSIF_PCLK_AFIO_MODE  AFIO_MODE_3
#define CMOSSENSOR_CSIF_PCLK_AFIO_PIN   AFIO_PIN_11

#define CMOSSENSOR_CSIF_VSYNC_GPIO_PIN  DVB_GPIOE_ID
#define CMOSSENSOR_CSIF_VSYNC_AFIO_MODE AFIO_MODE_3
#define CMOSSENSOR_CSIF_VSYNC_AFIO_PIN  AFIO_PIN_15

#define CMOSSENSOR_CSIF_HSYNC_GPIO_PIN  DVB_GPIOE_ID
#define CMOSSENSOR_CSIF_HSYNC_AFIO_MODE AFIO_MODE_3
#define CMOSSENSOR_CSIF_HSYNC_AFIO_PIN  AFIO_PIN_15

#define CMOSSENSOR_CSIF_D0_GPIO_PIN     DVB_GPIOD_ID
#define CMOSSENSOR_CSIF_D0_AFIO_MODE    AFIO_MODE_3
#define CMOSSENSOR_CSIF_D0_AFIO_PIN     AFIO_PIN_8

#define CMOSSENSOR_CSIF_D1_GPIO_PIN     DVB_GPIOD_ID
#define CMOSSENSOR_CSIF_D1_AFIO_MODE    AFIO_MODE_3
#define CMOSSENSOR_CSIF_D1_AFIO_PIN     AFIO_PIN_9

#define CMOSSENSOR_CSIF_D2_GPIO_PIN     DVB_GPIOD_ID
#define CMOSSENSOR_CSIF_D2_AFIO_MODE    AFIO_MODE_3
#define CMOSSENSOR_CSIF_D2_AFIO_PIN     AFIO_PIN_10

#define CMOSSENSOR_CSIF_D3_GPIO_PIN     DVB_GPIOD_ID
#define CMOSSENSOR_CSIF_D3_AFIO_MODE    AFIO_MODE_3
#define CMOSSENSOR_CSIF_D3_AFIO_PIN     AFIO_PIN_11

#define CMOSSENSOR_CSIF_D4_GPIO_PIN     DVB_GPIOE_ID
#define CMOSSENSOR_CSIF_D4_AFIO_MODE    AFIO_MODE_3
#define CMOSSENSOR_CSIF_D4_AFIO_PIN     AFIO_PIN_5

#define CMOSSENSOR_CSIF_D5_GPIO_PIN     DVB_GPIOE_ID
#define CMOSSENSOR_CSIF_D5_AFIO_MODE    AFIO_MODE_3
#define CMOSSENSOR_CSIF_D5_AFIO_PIN     AFIO_PIN_6

#define CMOSSENSOR_CSIF_D6_GPIO_PIN     DVB_GPIOE_ID
#define CMOSSENSOR_CSIF_D6_AFIO_MODE    AFIO_MODE_3
#define CMOSSENSOR_CSIF_D6_AFIO_PIN     AFIO_PIN_7

#define CMOSSENSOR_CSIF_D7_GPIO_PIN     DVB_GPIOE_ID
#define CMOSSENSOR_CSIF_D7_AFIO_MODE    AFIO_MODE_3
#define CMOSSENSOR_CSIF_D7_AFIO_PIN     AFIO_PIN_8

#define CMOSSENSOR_CSIF_PD_GPIO_PIN     DVB_GPIOD_ID
#define CMOSSENSOR_CSIF_PD_AFIO_MODE    AFIO_MODE_DEFAULT
#define CMOSSENSOR_CSIF_PD_AFIO_PIN     AFIO_PIN_14

#define CMOSSENSOR_CSIF_RESB_GPIO_PIN   DVB_GPIOD_ID
#define CMOSSENSOR_CSIF_RESB_AFIO_MODE  AFIO_MODE_DEFAULT
#define CMOSSENSOR_CSIF_RESB_AFIO_PIN   AFIO_PIN_13

#define CMOSSENSOR_CSIF_LED_GPIO_PIN    DVB_GPIOD_ID
#define CMOSSENSOR_CSIF_LDE_AFIO_MODE   AFIO_MODE_DEFAULT
#define CMOSSENSOR_CSIF_LDE_AFIO_PIN    AFIO_PIN_12
/**
  * @}
  */

/** @addtogroup HT32F1755_2755_DVB_USB
  * @{
  */
#define USB_GPIO_ID           DVB_GPIOA_ID
#define USB_GPIO_PORT         ((GPIO_TypeDef*)GPIOA_BASE)
#define USB_GPIO_PIN          GPIO_PIN_4
#define USB_AFIO_MODE         AFIO_MODE_DEFAULT
#define USB_AFIO_PIN          AFIO_PIN_4
/**
  * @}
  */

typedef enum
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2
} LED_TypeDef;

typedef enum
{
  BUTTON_WAKEUP = 0,
  BUTTON_KEY1 = 1,
  BUTTON_KEY2 = 2
} BUTTON_TypeDef;

typedef enum
{
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} BUTTON_MODE_TypeDef;

typedef enum
{
  COM1 = 0,
  COM2 = 1
} COM_TypeDef;

/**
  * @}
  */

/** @defgroup HT32F1755_2755_DVB_Exported_Macros HT32F1755_2755 DVB exported macros
  * @{
  */
/**
  * @}
  */

/** @defgroup HT32F1755_2755_DVB_Exported_Functions HT32F1755_2755 DVB exported functions
  * @{
  */
void HT32F_DVB_GPxConfig(u8 GPIO_ID, u32 AFIO_PIN, u32 AFIO_MODE);
void HT32F_DVB_LEDInit(LED_TypeDef Led);
void HT32F_DVB_LEDOn(LED_TypeDef Led);
void HT32F_DVB_LEDOff(LED_TypeDef Led);
void HT32F_DVB_LEDToggle(LED_TypeDef Led);
void HT32F_DVB_PBInit(BUTTON_TypeDef Button, BUTTON_MODE_TypeDef Button_Mode);
u32 HT32F_DVB_PBGetState(BUTTON_TypeDef Button);
void HT32F_DVB_COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStruct);

void HT32F_DVB_BuzzerInit(u16 hFreq, u8 bDuty);
void HT32F_DVB_BuzzerConfig(u16 hFreq, u8 bDuty);
void HT32F_DVB_BuzzerOutputCmd(GPTM_CHCTL_Enum Control);

void HT32F_DVB_USBConnect(void);
void HT32F_DVB_USBDisConnect(void);

#ifdef __cplusplus
}
#endif


#endif /* __HT32F1755_2755_DVB_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

