/*********************************************************************************************************//**
 * @file    ht32f1755_2755_dvb.c
 * @version V1.0
 * @date    09/08/2011
 * @brief   This file provides firmware functions to manage LEDs, push-buttons
 *          and COM ports and is available on HT32F1755/2755 Development Board.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f1755_2755_dvb.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup HT32F1755_2755_Development_Board
  * @{
  */

/** @defgroup HT32F1755_2755_DVB HT32F1755_2755_DVB
  * @brief Provides firmware functions to manage LEDs, push-buttons
  *        and COM ports and is available on HT32F1755/2755 Development Board.
  * @{
  */

/** @defgroup HT32F1755_2755_DVB_Private_TypesDefinitions HT32F1755/2755 DVB private types definitions
  * @{
  */

/**
 * @brief This structure is used to store the EXTI configuration.
 */
typedef struct
{
  const EXTI_Channel_TypeDef EXTI_Channel;
  const AFIO_ESS_Enum AFIO_ESS;
  const AFIO_EXTI_CH_Enum AFIO_EXTI_CH;
  const IRQn_Type EXTI_IRQn;
} DVB_EXTI_CFG_TypeDef;
/**
  * @}
  */


/** @defgroup HT32F1755_2755_DVB_Private_Defines HT32F1755/2755 DVB private definitions
  * @{
  */
/**
  * @}
  */


/** @defgroup HT32F1755_2755_DVB_Private_Macros HT32F1755/2755 DVB private macros
  * @{
  */
/**
  * @}
  */


/** @defgroup HT32F1755_2755_DVB_Private_Variables HT32F1755/2755 DVB private variables
  * @{
  */

#ifdef USE_HT32F1755_2755_DVB
  const u32 DVB_GpioClock[DVB_GPIO_NBR] = {CKCU_APBEN0_PA, CKCU_APBEN0_PB, CKCU_APBEN0_PC, CKCU_APBEN0_PD, CKCU_APBEN0_PE};

  const u8 LED_GPIO_ID[LEDn] = {LED1_GPIO_ID, LED2_GPIO_ID, LED3_GPIO_ID};
  GPIO_TypeDef* LED_GPIO_PORT[LEDn] = {LED1_GPIO_PORT, LED2_GPIO_PORT, LED3_GPIO_PORT};
  const u16 LED_GPIO_PIN[LEDn] = {LED1_GPIO_PIN, LED2_GPIO_PIN, LED3_GPIO_PIN};
  const u32 LED_AFIO_MODE[LEDn] = {LED1_AFIO_MODE, LED2_AFIO_MODE, LED3_AFIO_MODE};
  const u32 LED_AFIO_PIN[LEDn] = {LED1_AFIO_PIN, LED2_AFIO_PIN, LED3_AFIO_PIN};

  const u8 BUTTON_GPIO_ID[BUTTONn]
    = {WAKEUP_BUTTON_GPIO_ID, KEY1_BUTTON_GPIO_ID, KEY2_BUTTON_GPIO_ID};
  GPIO_TypeDef* BUTTON_GPIO_PORT[BUTTONn]
    = {WAKEUP_BUTTON_GPIO_PORT, KEY1_BUTTON_GPIO_PORT, KEY2_BUTTON_GPIO_PORT};
  const u16 BUTTON_GPIO_PIN[BUTTONn]
    = {WAKEUP_BUTTON_GPIO_PIN, KEY1_BUTTON_GPIO_PIN, KEY2_BUTTON_GPIO_PIN};
  const u32 BUTTON_AFIO_MODE[BUTTONn]
    = {WAKEUP_BUTTON_AFIO_MODE, KEY1_BUTTON_AFIO_MODE, KEY2_BUTTON_AFIO_MODE};
  const u32 BUTTON_AFIO_PIN[BUTTONn]
    = {WAKEUP_BUTTON_AFIO_PIN, KEY1_BUTTON_AFIO_PIN, KEY2_BUTTON_AFIO_PIN};

  DVB_EXTI_CFG_TypeDef BUTTON_ExtiConfig[BUTTONn] =
    { { WAKEUP_BUTTON_EXTI_CHANNEL, WAKEUP_BUTTON_AFIO_ESS, WAKEUP_BUTTON_AFIO_EXTI_CH, WAKEUP_BUTTON_IRQn },
      { KEY1_BUTTON_EXTI_CHANNEL, KEY1_BUTTON_AFIO_ESS, KEY1_BUTTON_AFIO_EXTI_CH, KEY1_BUTTON_IRQn },
      { KEY2_BUTTON_EXTI_CHANNEL, KEY2_BUTTON_AFIO_ESS, KEY2_BUTTON_AFIO_EXTI_CH, KEY2_BUTTON_IRQn }
    };

  USART_TypeDef* COM_USART[COMn] = {DVB_COM1_USART, DVB_COM2_USART};
  const u32 COM_USART_CLK[COMn] = {DVB_COM1_CLK, DVB_COM2_CLK};

  const u8 COM_TX_GPIO_ID[COMn] = {DVB_COM1_TX_GPIO_ID, DVB_COM2_TX_GPIO_ID};
  const u32 COM_TX_AFIO_MODE[COMn] = {DVB_COM1_TX_AFIO_MODE, DVB_COM2_TX_AFIO_MODE};
  const u32 COM_TX_AFIO_PIN[COMn] = {DVB_COM1_TX_AFIO_PIN, DVB_COM2_TX_AFIO_PIN};

  const u8 COM_RX_GPIO_ID[COMn] = {DVB_COM1_RX_GPIO_ID, DVB_COM2_RX_GPIO_ID};
  const u32 COM_RX_AFIO_MODE[COMn] = {DVB_COM1_RX_AFIO_MODE, DVB_COM2_RX_AFIO_MODE};
  const u32 COM_RX_AFIO_PIN[COMn] = {DVB_COM1_RX_AFIO_PIN, DVB_COM2_RX_AFIO_PIN};

  const u8 COM_CTS_GPIO_ID[COMn] = {0, DVB_COM2_CTS_GPIO_ID};
  const u32 COM_CTS_AFIO_MODE[COMn] = {0, DVB_COM2_CTS_AFIO_MODE};
  const u32 COM_CTS_AFIO_PIN[COMn] = {0, DVB_COM2_CTS_AFIO_PIN};

  const u8 COM_RTS_GPIO_ID[COMn] = {0, DVB_COM2_RTS_GPIO_ID};
  const u32 COM_RTS_AFIO_MODE[COMn] = {0, DVB_COM2_RTS_AFIO_MODE};
  const u32 COM_RTS_AFIO_PIN[COMn] = {0, DVB_COM2_RTS_AFIO_PIN};

#endif

/**
  * @}
  */


/** @defgroup HT32F1755_2755_DVB_Private_FunctionPrototypes HT32F1755/2755 DVB private function prototypes
  * @{
  */
/**
  * @}
  */


/** @defgroup HT32F1755_2755_DVB_Private_Functions HT32F1755/2755 DVB private functions
  * @{
  */

/*********************************************************************************************************//**
 * @brief Configures LED GPIO.
 * @param Led: Specifies the LED to be configured. This parameter can be one of the following values:
 *    @arg LED1
 *    @arg LED2
 *    @arg LED3
 * @retval None
 ************************************************************************************************************/
void HT32F_DVB_LEDInit(LED_TypeDef Led)
{
  u8 bGpioId = LED_GPIO_ID[Led];

  /* Enable the AFIO and GPIO_LED Clock */
  CKCU_APBPerip0ClockConfig(DVB_GpioClock[bGpioId] | CKCU_APBEN0_AFIO, ENABLE);

  /* Configure the AFIO mode */
  HT32F_DVB_GPxConfig(bGpioId, LED_AFIO_PIN[Led], LED_AFIO_MODE[Led]);

  /* LED is off by default*/
  HT32F_DVB_LEDOff(Led);

  /* Configure the GPIO pin */
  GPIO_PullResistorConfig(LED_GPIO_PORT[Led], LED_GPIO_PIN[Led], GPIO_PR_DISABLE);
  GPIO_DriveConfig(LED_GPIO_PORT[Led], LED_GPIO_PIN[Led], GPIO_DV_8MA);
  GPIO_DirectionConfig(LED_GPIO_PORT[Led], LED_GPIO_PIN[Led], GPIO_DIR_OUT);
}

/*********************************************************************************************************//**
 * @brief Turns selected LED On.
 * @param Led: Specifies the LED to be configured. This parameter can be one of the following values:
 *    @arg LED1
 *    @arg LED2
 *    @arg LED3
 * @retval None
 ************************************************************************************************************/
void HT32F_DVB_LEDOn(LED_TypeDef Led)
{
  LED_GPIO_PORT[Led]->RR = LED_GPIO_PIN[Led];
}

/*********************************************************************************************************//**
 * @brief Turns selected LED Off.
 * @param Led: Specifies the LED to be configured. This parameter can be one of the following values:
 *    @arg LED1
 *    @arg LED2
 *    @arg LED3
 * @retval None
 ************************************************************************************************************/
void HT32F_DVB_LEDOff(LED_TypeDef Led)
{
  LED_GPIO_PORT[Led]->SRR = LED_GPIO_PIN[Led];
}

/*********************************************************************************************************//**
 * @brief Toggles the selected LED.
 * @param Led: Specifies the LED to be configured. This parameter can be one of the following values:
 *    @arg LED1
 *    @arg LED2
 *    @arg LED3
 * @retval None
 ************************************************************************************************************/
void HT32F_DVB_LEDToggle(LED_TypeDef Led)
{
  LED_GPIO_PORT[Led]->DOUTR ^= LED_GPIO_PIN[Led];
}

/*********************************************************************************************************//**
 * @brief Configures Button GPIO and EXTI.
 * @param  Button: Specifies the Button to be configured.
 *   This parameter can be one of following parameters:
 *     @arg BUTTON_WAKEUP: Wakeup Push Button
 *     @arg BUTTON_KEY1: Key1 Push Button
 *     @arg BUTTON_KEY2: Key2 Push Button
 * @param  Button_Mode: Specifies Button mode.
 *   This parameter can be one of following parameters:
 *     @arg BUTTON_MODE_GPIO: Button will be used as simple IO
 *     @arg BUTTON_MODE_EXTI: Button will be connected to EXTI channel with interrupt generation capability
 * @retval None
 ************************************************************************************************************/
void HT32F_DVB_PBInit(BUTTON_TypeDef Button, BUTTON_MODE_TypeDef Button_Mode)
{
  DVB_EXTI_CFG_TypeDef ExtiConfig = BUTTON_ExtiConfig[Button];
  u8 bGpioId = BUTTON_GPIO_ID[Button];

  /* Enable the AFIO and button GPIO Clock */
  CKCU_APBPerip0ClockConfig(DVB_GpioClock[bGpioId] | CKCU_APBEN0_AFIO, ENABLE);

  /* Configure Button pin as input floating */
  HT32F_DVB_GPxConfig(bGpioId, BUTTON_AFIO_PIN[Button], BUTTON_AFIO_MODE[Button]);
  GPIO_PullResistorConfig(BUTTON_GPIO_PORT[Button], BUTTON_GPIO_PIN[Button], GPIO_PR_DISABLE);
  GPIO_DirectionConfig(BUTTON_GPIO_PORT[Button], BUTTON_GPIO_PIN[Button], GPIO_DIR_IN);
  GPIO_InputConfig(BUTTON_GPIO_PORT[Button], BUTTON_GPIO_PIN[Button], ENABLE);

  if (Button_Mode == BUTTON_MODE_EXTI)
  {
    EXTI_InitTypeDef EXTI_InitStruct;

    /* Enable the EXTI Clock */
    CKCU_APBPerip0ClockConfig(CKCU_APBEN0_EXTI, ENABLE);

    /* Configure button EXTI Line on falling edge */
    EXTI_InitStruct.EXTI_Channel = ExtiConfig.EXTI_Channel;
    EXTI_InitStruct.EXTI_Debounce = EXTI_DEBOUNCE_DISABLE;
    EXTI_InitStruct.EXTI_DebounceCnt = 0;  /* 28bits counter, 0x0 ~ 0x0FFF_FFFF */
    if(Button != BUTTON_WAKEUP)
    {
      EXTI_InitStruct.EXTI_IntType = EXTI_NEGATIVE_EDGE;
    }
    else
    {
      EXTI_InitStruct.EXTI_IntType = EXTI_POSITIVE_EDGE;
    }
    EXTI_Init(&EXTI_InitStruct);

    /* Connect Button EXTI Channel to Button GPIO Pin */
    AFIO_EXTISourceConfig(ExtiConfig.AFIO_EXTI_CH, ExtiConfig.AFIO_ESS);

    /* Enable Button EXTI Interrupt */
    EXTI_IntConfig(ExtiConfig.EXTI_Channel, ENABLE);
    NVIC_EnableIRQ(ExtiConfig.EXTI_IRQn);
  }
}

/*********************************************************************************************************//**
 * @brief Returns the selected Button state.
 * @param  Button: Specifies the Button to be configured.
 *   This parameter can be one of following parameters:
 *     @arg BUTTON_WAKEUP: Wakeup Push Button
 *     @arg BUTTON_KEY1: Key1 Push Button
 *     @arg BUTTON_KEY2: Key2 Push Button
 * @return The Button GPIO pin value.
 ************************************************************************************************************/
u32 HT32F_DVB_PBGetState(BUTTON_TypeDef Button)
{
  return GPIO_ReadInBit(BUTTON_GPIO_PORT[Button], BUTTON_GPIO_PIN[Button]);
}


/*********************************************************************************************************//**
 * @brief Configures COM port.
 * @param  COM: Specifies the COM port to be configured.
 *   This parameter can be one of following parameters:
 *     @arg COMx where x can be 1
 * @param USART_InitStructure pointer to a USART_InitTypeDef structure that contains the configuration
 *        information for the specified USART peripheral.
 * @return None
 ************************************************************************************************************/
void HT32F_DVB_COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStructure)
{
  u8 bTxGpioId = COM_TX_GPIO_ID[COM];
  u8 bRxGpioId = COM_RX_GPIO_ID[COM];
  u8 bCTSGpioId = COM_CTS_GPIO_ID[COM];
  u8 bRTSGpioId = COM_RTS_GPIO_ID[COM];

  /* Enable GPIO and AFIO clock */
  CKCU_APBPerip0ClockConfig(DVB_GpioClock[bTxGpioId] | DVB_GpioClock[bRxGpioId] | CKCU_APBEN0_AFIO, ENABLE);

  /* Enable USART clock */
  CKCU_APBPerip0ClockConfig(COM_USART_CLK[COM], ENABLE);

  /* Configure USART Tx/Rx as alternate function */
  HT32F_DVB_GPxConfig(bTxGpioId, COM_TX_AFIO_PIN[COM], COM_TX_AFIO_MODE[COM]);
  HT32F_DVB_GPxConfig(bRxGpioId, COM_RX_AFIO_PIN[COM], COM_RX_AFIO_MODE[COM]);

  if(COM == COM2)
  {
    /* Configure USART CTS/RTS as alternate function */
    HT32F_DVB_GPxConfig(bCTSGpioId, COM_CTS_AFIO_PIN[COM], COM_CTS_AFIO_MODE[COM]);
    HT32F_DVB_GPxConfig(bRTSGpioId, COM_RTS_AFIO_PIN[COM], COM_RTS_AFIO_MODE[COM]);
  }

  /* USART configuration */
  USART_Init(COM_USART[COM], USART_InitStructure);

  /* USART Tx enable */
  USART_TxCmd(COM_USART[COM], ENABLE);
  /* USART Rx enable */
  USART_RxCmd(COM_USART[COM], ENABLE);
}

/*********************************************************************************************************//**
 * @brief Init BUZZER.
 * @param  hFreq: the PWM frequency of buzzer to be configured.
 *   This parameter can be 1 ~ 6000 (Unit: Hz).
 * @param  bDuty: the PWM duty of buzzer to be configured.
 *   This parameter can be 0 ~ 100 (Unit: %).
 * @return None
 ************************************************************************************************************/
void HT32F_DVB_BuzzerInit(u16 hFreq, u8 bDuty)
{
  GPTM_TimeBaseInitTypeDef TimeBaseInit;
  GPTM_OutputInitTypeDef OutInit;
  uint32_t wCRR=0, wPSCR=0, wCHCCR=0;

  /* Reset buzzer GPTM */
  GPTM_DeInit(BUZZER_GPTM);

  /* Configure the BUZZER_GPIO_PIN as GPTM channel output AFIO function */
  CKCU_APBPerip0ClockConfig(CKCU_APBEN0_AFIO | DVB_GpioClock[BUZZER_GPIO_ID], ENABLE);
  HT32F_DVB_GPxConfig(BUZZER_GPIO_ID, BUZZER_AFIO_PIN, BUZZER_AFIO_MODE);
  GPIO_DriveConfig(BUZZER_GPIO_PORT, BUZZER_GPIO_PIN, GPIO_DV_8MA);

  /* Enable PCLK of BUZZER GPTM */
  CKCU_APBPerip1ClockConfig(BUZZER_BUZZER_CLK, ENABLE);

  /* Compute CRR and PSCR value */
  wCRR = (SystemCoreClock / hFreq) - 1;
  while((wCRR / (wPSCR + 1)) > 0xFFFF)
  {
    wPSCR++;
  }
  wCRR = wCRR / (wPSCR + 1);
  wCHCCR = ((wCRR + 1) * (100 - bDuty)) / 100;

  /* Init BUZZER GPTM time-base */
  GPTM_TimeBaseStructInit(&TimeBaseInit);
  TimeBaseInit.CounterMode = GPTM_CNT_MODE_UP;
  TimeBaseInit.CounterReload = wCRR;
  TimeBaseInit.Prescaler = wPSCR;
  TimeBaseInit.PSCReloadTime = GPTM_PSC_RLD_IMMEDIATE;
  GPTM_TimeBaseInit(BUZZER_GPTM, &TimeBaseInit);

  /* Clear Update Event Interrupt flag */
  GPTM_ClearFlag(BUZZER_GPTM, GPTM_FLAG_UEV);

  /* Init BUZZER GPTM Channel x to output PWM waveform with 33% duty */
  GPTM_OutputStructInit(&OutInit);
  OutInit.Channel = BUZZER_GPTM_CHANNEL;
  OutInit.OutputMode = GPTM_OM_PWM2;
  OutInit.Control = GPTM_CHCTL_DISABLE;
  OutInit.Polarity = GPTM_CHP_NONINVERTED;
  OutInit.Compare = wCHCCR ;
  GPTM_OutputInit(BUZZER_GPTM, &OutInit);

  /* Enable CHCCR and CRR preload function */
  GPTM_CHCCRPreloadConfig(BUZZER_GPTM, BUZZER_GPTM_CHANNEL, ENABLE);
  GPTM_CRRPreloadCmd(BUZZER_GPTM, ENABLE);

  /* Enable BUZZER GPTM */
  GPTM_Cmd(BUZZER_GPTM, ENABLE);
}

/*********************************************************************************************************//**
 * @brief Configure BUZZER PWM Frequency and Duty.
 * @param  hFreq: the PWM frequency of buzzer to be configured.
 *   This parameter can be 1 ~ 6000 (Unit: Hz).
 * @param  bDuty: the PWM duty of buzzer to be configured.
 *   This parameter can be 0 ~ 100 (Unit: %).
 * @return None
 ************************************************************************************************************/
void HT32F_DVB_BuzzerConfig(u16 hFreq, u8 bDuty)
{
  u32 wCRR=0, wCHCCR=0, wPSCR=0;
  vu32 *pCHxCCR = ((vu32*)&BUZZER_GPTM->CH0CCR) + BUZZER_GPTM_CHANNEL;

  /* Compute CRR and PSCR value */
  wCRR = (SystemCoreClock / hFreq) - 1;
  while((wCRR / (wPSCR + 1)) > 0xFFFF)
  {
    wPSCR++;
  }
  wCRR = wCRR / (wPSCR + 1);
  wCHCCR = ((wCRR + 1) * (100 - bDuty)) / 100;

  GPTM_UpdateCmd(BUZZER_GPTM, DISABLE);
  BUZZER_GPTM->CRR = wCRR;
  BUZZER_GPTM->PSCR = wPSCR;
  *pCHxCCR = wCHCCR;
  GPTM_UpdateCmd(BUZZER_GPTM, ENABLE);
}

/*********************************************************************************************************//**
 * @brief Configure BUZZER PWM Frequency and Duty.
 * @param Control: This parameter can be GPTM_CHCTL_ENABLE or GPTM_CHCTL_DISABLE.
 * @return None
 ************************************************************************************************************/
void HT32F_DVB_BuzzerOutputCmd(GPTM_CHCTL_Enum Control)
{
  GPTM_ChannelConfig(BUZZER_GPTM, BUZZER_GPTM_CHANNEL, Control);
}

/*********************************************************************************************************//**
 * @brief Configures AFIO Mode.
 * @param  GPIO_ID: Specifies the GPIO port to be configured.
 *   This parameter can be DVB_GPIOx_ID where x can be A ~ B
 * @param AFIO_PIN: This parameter can be any combination of AFIO_PIN_x where x can be 0 ~ 15.
 * @param AFIO_MODE: This parameter can be one of the following values:
 *        @arg AFIO_MODE_DEFAULT : The default I/O function
 *        @arg AFIO_MODE_1       : Alternated mode 1
 *        @arg AFIO_MODE_2       : Alternated mode 2
 *        @arg AFIO_MODE_3       : Alternated mode 3
 * @return None
 ************************************************************************************************************/
void HT32F_DVB_GPxConfig(u8 GPIO_ID, u32 AFIO_PIN, u32 AFIO_MODE)
{
  vu32* pGPxCFGR = ((vu32*)&AFIO->GPACFGR) + GPIO_ID;

  *pGPxCFGR = (*pGPxCFGR & ~AFIO_PIN) | (AFIO_MODE & AFIO_PIN);
}

/*********************************************************************************************************//**
  * @brief  Connect USB by set GPIO.
  * @return None
  ***********************************************************************************************************/
void HT32F_DVB_USBConnect(void)
{

  CKCU_APBPerip0ClockConfig(CKCU_APBEN0_AFIO | DVB_GpioClock[USB_GPIO_ID], ENABLE);
  HT32F_DVB_GPxConfig(USB_GPIO_ID, USB_AFIO_PIN, USB_AFIO_MODE);

  GPIO_DirectionConfig(USB_GPIO_PORT, USB_GPIO_PIN, GPIO_DIR_OUT);
  GPIO_SetOutBits(USB_GPIO_PORT, USB_GPIO_PIN);

  return;
}

/*********************************************************************************************************//**
  * @brief  Disconnect USB by clear GPIO.
  * @return None
  ***********************************************************************************************************/
void HT32F_DVB_USBDisConnect(void)
{

  GPIO_DirectionConfig(USB_GPIO_PORT, USB_GPIO_PIN, GPIO_DIR_IN);
  GPIO_ClearOutBits(USB_GPIO_PORT, USB_GPIO_PIN);

  return;
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

/**
  * @}
  */
