/*********************************************************************************************************//**
 * @file    ht32f175x_275x_usart.c
 * @version V1.0
 * @date    11/26/2010
 * @brief   This file provides all the USART firmware functions.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x_usart.h"
#include "ht32f175x_275x_ckcu.h"
#include "ht32f175x_275x_rstcu.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver HT32F175x/275x Peripheral Driver
  * @{
  */

/** @defgroup  USART USART
  * @brief USART driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup USART_Private_TypesDefinitions USART private types definitions
  * @{
  */

/**
  * @}
  */


/* Private define ------------------------------------------------------------------------------------------*/

/** @defgroup USART_Private_Define USART private defines
  * @{
  */
#define LCR_CLEAR_Mask            ((u32)0xFFFFFFE0)
#define MDR_CLEAR_Mask            ((u32)0xFFFFFFFC)
#define FCR_RFITL_CLEAR_Mask      ((u32)0xFFFFFF3F)
#define FCR_TFITL_CLEAR_Mask      ((u32)0xFFFFFFCF)
#define TRSM_CLEAR_Mask           ((u32)0xFFFFFFFB)
#define TPR_TG_Mask               ((u32)0xFFFF00FF)
#define RCR_ILPDVSR_Mask          ((u32)0xFFFF00FF)
#define TPR_RTOIC_Mask            ((u32)0xFFFFFF80)
#define DLR_BR_Mask               ((u32)0xFFFF0000)
#define RS485CR_ADDM_Mask         ((u32)0xFFFF00FF)

#define USART_IRDA_ON             ((u32)0x00000001)
#define USART_IRDA_OFF            ((u32)0xFFFFFFFE)

#define USART_BREAK_ON            ((u32)0x00000040)
#define USART_BREAK_OFF           ((u32)0xFFFFFFBF)

#define USART_TIMEOUT_ON          ((u32)0x00000080)
#define USART_TIMEOUT_OFF         ((u32)0xFFFFFF7F)

#define USART_SPE_ON              ((u32)0x00000020)
#define USART_SPE_OFF             ((u32)0xFFFFFFDF)

#define USART_TXEN_ON             ((u32)0x00000100)
#define USART_TXEN_OFF            ((u32)0xFFFFFEFF)

#define USART_RXEN_ON             ((u32)0x00000200)
#define USART_RXEN_OFF            ((u32)0xFFFFFDFF)

#define USART_TXINV_ON            ((u32)0x00000010)
#define USART_TXINV_OFF           ((u32)0xFFFFFFEF)

#define USART_RXINV_ON            ((u32)0x00000020)
#define USART_RXINV_OFF           ((u32)0xFFFFFFDF)

#define USART_HFCEN_ON            ((u32)0x00000004)
#define USART_HFCEN_OFF           ((u32)0xFFFFFFFB)

#define USART_TxPDMA_ON           ((u32)0x00000010)
#define USART_TxPDMA_OFF          ((u32)0xFFFFFFEF)

#define USART_RxPDMA_ON           ((u32)0x00000020)
#define USART_RxPDMA_OFF          ((u32)0xFFFFFFDF)

#define USART_RS485NMM_ON           ((u32)0x00000002)
#define USART_RS485NMM_OFF          ((u32)0xFFFFFFFD)

#define USART_RS485AAD_ON           ((u32)0x00000004)
#define USART_RS485AAD_OFF          ((u32)0xFFFFFFFB)
/**
  * @}
  */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup USART_Private_Macro USART private macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------------------------------------*/

/** @defgroup USART_Private_Variable USART private variables
  * @{
  */

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup USART_Private_Function_Prototype USART private function prototypes
  * @{
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup USART_Private_Function USART private functions
  * @{
  */

/*********************************************************************************************************//**
 * @brief Deinitialize registers of the USART peripheral by resetting USART.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @retval None
 ************************************************************************************************************/
void USART_DeInit(USART_TypeDef* USARTx)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));

  if(USARTx == USART0)
  {
    RSTCU_APBPerip0Reset(RSTCU_APBRST0_USART0, ENABLE);
  }
  else
  {
    RSTCU_APBPerip0Reset(RSTCU_APBRST0_USART1, ENABLE);
  }
}

/*********************************************************************************************************//**
 * @brief Initialize the USARTx peripheral according to the specified parameters in the USART_InitStruct.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_InitStructure: pointer to a USART_InitTypeDef structure that contains the configuration information
 *        for the specified USART peripheral.
 * @retval None
 ************************************************************************************************************/
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStructure)
{
  u32 tmpreg = 0x00;
  CKCU_ClocksTypeDef Clocks;

  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_BAUDRATE(USART_InitStructure->USART_BaudRate));
  Assert_Param(IS_USART_WORD_LENGTH(USART_InitStructure->USART_WordLength));
  Assert_Param(IS_USART_STOPBITS(USART_InitStructure->USART_StopBits));
  Assert_Param(IS_USART_PARITY(USART_InitStructure->USART_Parity));
  Assert_Param(IS_USART_MODE(USART_InitStructure->USART_Mode));

  /*---------------------------- USART LCR Configuration ---------------------------------------------------*/
  tmpreg = USARTx->LCR & LCR_CLEAR_Mask;

  tmpreg |= USART_InitStructure->USART_StopBits | USART_InitStructure->USART_WordLength  |
            USART_InitStructure->USART_Parity;

  USARTx->LCR = tmpreg;

  /*---------------------------- USART MDR Configuration ---------------------------------------------------*/
  tmpreg = USARTx->MDR & MDR_CLEAR_Mask;

  tmpreg |= USART_InitStructure->USART_Mode;

  USARTx->MDR = tmpreg;

  /*---------------------------- USART BaudRate Configuration ----------------------------------------------*/
  CKCU_GetClocksFrequency(&Clocks);
  tmpreg = (Clocks.USART_Freq/(u32)USART_InitStructure->USART_BaudRate);
  USARTx->DLR = tmpreg;
}

/*********************************************************************************************************//**
 * @brief Fill each USART_InitStruct member with its default value.
 * @param USART_InitStructure: pointer to a USART_InitTypeDef structure which will be initialized.
 * @retval None
 ************************************************************************************************************/
void USART_StructInit(USART_InitTypeDef* USART_InitStructure)
{
  /* USART_InitStruct members default value */
  USART_InitStructure->USART_BaudRate = 9600 ;
  USART_InitStructure->USART_WordLength = USART_WORDLENGTH_8B ;
  USART_InitStructure->USART_StopBits = USART_STOPBITS_1;
  USART_InitStructure->USART_Parity = USART_PARITY_NO;
  USART_InitStructure->USART_Mode = USART_MODE_NORMAL;
}

/*********************************************************************************************************//**
 * @brief Initialize Clock of the USARTx peripheral according to the specified parameters
 *   in the USART_ClockInitStruct.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_SynClock_InitStruct: pointer to a USART_SynClock_InitTypeDef structure that contains
 *   the configuration information for the specified USART peripheral.
 * @retval None
 ************************************************************************************************************/
void USART_SynClockInit(USART_TypeDef* USARTx, USART_SynClock_InitTypeDef* USART_SynClock_InitStruct)
{
  u32 tmpreg = 0x00;

  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_SYNCHRONOUS_CLOCK(USART_SynClock_InitStruct->USART_ClockEnable));
  Assert_Param(IS_USART_SYNCHRONOUS_PHASE(USART_SynClock_InitStruct->USART_ClockPhase));
  Assert_Param(IS_USART_SYNCHRONOUS_POLARITY(USART_SynClock_InitStruct->USART_ClockPolarity));
  Assert_Param(IS_USART_TRANSFER_MODE(USART_SynClock_InitStruct->USART_TransferSelectMode));

  /*---------------------------- USART SCR Configuration -----------------------*/
  /* Configure the USART CLKEN, LBCP, CPS and CPO ------------*/
  /* Set CLKEN bit according to USART_ClockEnable value */
  /* Set CPS bit according to USART_ClockPhase value */
  /* Set CPO bit according to USART_ClockPolarity value */
  USARTx->SCR = USART_SynClock_InitStruct->USART_ClockEnable | USART_SynClock_InitStruct->USART_ClockPhase |
                USART_SynClock_InitStruct->USART_ClockPolarity;

  /* Set TRSM bit according to USART_TransferSelectMode value */
  tmpreg = USARTx->MDR & TRSM_CLEAR_Mask;
  tmpreg |= USART_SynClock_InitStruct->USART_TransferSelectMode;
  USARTx->MDR = tmpreg;
}

/*********************************************************************************************************//**
 * @brief Fill each USART_SynClockInitStruct member with its default value.
 * @param USART_SynClock_InitStruct: pointer to a USART_SynClock_InitTypeDef structure which will be initialized.
 * @retval None
 ************************************************************************************************************/
void USART_SynClockStructInit(USART_SynClock_InitTypeDef* USART_SynClock_InitStruct)
{
  /* USART_ClockInitStruct members default value */
  USART_SynClock_InitStruct->USART_ClockEnable =  USART_SYN_CLOCK_DISABLE;
  USART_SynClock_InitStruct->USART_ClockPhase = USART_SYN_CLOCK_PHASE_FIRST;
  USART_SynClock_InitStruct->USART_ClockPolarity = USART_SYN_CLOCK_POLARITY_LOW;
  USART_SynClock_InitStruct->USART_TransferSelectMode = USART_LSB_FRIST;
}

/*********************************************************************************************************//**
 * @brief USART SendData from Tx.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param Data: the data to be transmitted.
 * @retval None
 ************************************************************************************************************/
void USART_SendData(USART_TypeDef* USARTx, u16 Data)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_DATA(Data));

  USARTx->RBR = Data;
}

/*********************************************************************************************************//**
 * @brief USART ReceiveData from Rx.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @return The received data.
 ************************************************************************************************************/
u16 USART_ReceiveData(USART_TypeDef* USARTx)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));

  return (u16)USARTx->RBR;
}

/*********************************************************************************************************//**
 * @brief Set the specified USART guard time.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_GuardTime: Specify the guard time.
 * @retval None
 ************************************************************************************************************/
void USART_SetGuardTime(USART_TypeDef* USARTx, u32 USART_GuardTime)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_GUARD_TIME(USART_GuardTime));

  /* Set the USART guard time */
  USARTx->TPR = (USARTx->TPR & TPR_TG_Mask) | (USART_GuardTime << 0x08);
}


/*********************************************************************************************************//**
 * @brief Get LINE Status flags.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_FLAG: Specify the flag to check.
 *   This parameter can be one of the following values:
 *         @arg USART_LSR_RFDR
 *         @arg USART_LSR_OEI
 *         @arg USART_LSR_PEI
 *         @arg USART_LSR_FEI
 *         @arg USART_LSR_BII
 *         @arg USART_LSR_THRE
 *         @arg USART_LSR_TE
 *         @arg USART_LSR_ERR
 *         @arg USART_LSR_RSADDEF
 * @return  The new state of USART_FLAG (SET or RESET).
 ************************************************************************************************************/
FlagStatus USART_GetLineStatus(USART_TypeDef* USARTx, u32 USART_FLAG)
{
  FlagStatus bitstatus = RESET;

  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_LSR_FLAG(USART_FLAG));

  if ((USARTx->LSR & USART_FLAG) != (u32)RESET)
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
  * @brief  Return the status of specified USART FIFO.
  * @param  USARTx: where USARTx is the selected USART from the USART peripherals, x can be 0 or 1.
  * @param  USART_FIFODirection: specify the FIFO that is to be check.
  *   This parameter can be one of the following values:
  *     @arg USART_FIFO_TX           : USART Tx FIFO
  *     @arg USART_FIFO_RX           : USART Rx FIFO
  * @retval The number of data in Tx FIFO or Rx FIFO.
  ************************************************************************************************************/
u8 USART_GetFIFOStatus(USART_TypeDef* USARTx, u32 USART_FIFODirection)
{
  u32 tmpreg;

  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_FIFO_DIRECTION(USART_FIFODirection));

  if (USART_FIFODirection == USART_FIFO_TX)
  {
    tmpreg = USARTx->FSR & 0x1f;
  }
  else
  {
    tmpreg = (USARTx->FSR & 0x1f00) >> 8;
  }

  return (u8)tmpreg;
}

/*********************************************************************************************************//**
 * @brief Get Modem status.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @return The current status of Modem Status Register.
 ************************************************************************************************************/
u8 USART_GetModemStatus(USART_TypeDef* USARTx)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));

  return (u8)USARTx->MSR;
}

/*********************************************************************************************************//**
 * @brief Force pin DTR/RTS to low or high state.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_ModemPin: Specify the USART modem pin to be forced.
 *   This parameter can be one of the following values:
 *         @arg USART_MODEM_DTR
 *         @arg USART_MODEM_RTS
 * @param USART_ModemState: the USART modem pin state.
 *   This parameter can be one of the following values:
 *         @arg USART_MODEMSTATE_HIGH
 *         @arg USART_MODEMSTATE_LOW
 * @return None
 ************************************************************************************************************/
void USART_ForceModemPinState(USART_TypeDef* USARTx, u32 USART_ModemPin, u32 USART_ModemState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_MODEM_PIN(USART_ModemPin));
  Assert_Param(IS_USART_MODEM_STATE(USART_ModemState));

  if (USART_ModemState != USART_MODEMSTATE_HIGH)
  {
    USARTx->MCR |= USART_MODEMSTATE_LOW << USART_ModemPin;
  }
  else
  {
    USARTx->MCR &= ~(USART_MODEMSTATE_HIGH << USART_ModemPin);
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the USART IrDA interface.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the USART IrDA mode.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_IrDACmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the IrDA mode by setting the IrDAEN bit in the ICR register */
    USARTx->ICR |= USART_IRDA_ON;
  }
  else
  {
    /* Disable the IrDA mode by clearing the IrDAEN bit in the ICR register */
    USARTx->ICR &= USART_IRDA_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Configure the USART IrDA interface.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_IrDAMode: Specify the USART IrDA mode.
 *   This parameter can be one of the following values:
 *         @arg USART_IRDA_LOWPOWER
 *         @arg USART_IRDA_NORMAL
 * @retval None
 ************************************************************************************************************/
void USART_IrDAConfig(USART_TypeDef* USARTx, u32 USART_IrDAMode)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_IRDA_MODE(USART_IrDAMode));

  if (USART_IrDAMode != USART_IRDA_NORMAL)
  {
    USARTx->ICR |= USART_IRDA_LOWPOWER;
  }
  else
  {
    USARTx->ICR &= USART_IRDA_NORMAL;
  }
}

/*********************************************************************************************************//**
 * @brief Set the specified USART IrDA prescaler.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_IrDAPrescaler: Specify the USART IrDA prescaler.
 * @retval None
 ************************************************************************************************************/
void USART_SetIrDAPrescaler(USART_TypeDef* USARTx, u32 USART_IrDAPrescaler)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_IRDA_PRESCALER(USART_IrDAPrescaler));

  /* Set the USART IrDA prescaler */
  USARTx->ICR = (USARTx->ICR & RCR_ILPDVSR_Mask) | (USART_IrDAPrescaler << 0x08);
}

/*********************************************************************************************************//**
 * @brief Enable the IrDA transmitter or receiver.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_IrDADirection: Specify the USART IrDA direction select.
 *   This parameter can be one of the following values:
 *         @arg USART_IRDA_TX
 *         @arg USART_IRDA_RX
 * @retval None
 ************************************************************************************************************/
void USART_IrDADirectionConfig(USART_TypeDef* USARTx, u32 USART_IrDADirection)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_IRDA_DIRECTION(USART_IrDADirection));

  if (USART_IrDADirection != USART_IRDA_RX)
  {
    USARTx->ICR |= USART_IRDA_TX;
  }
  else
  {
    USARTx->ICR &= USART_IRDA_RX;
  }
}

/*********************************************************************************************************//**
 * @brief Configure the polarity of RS485 transmitter enable signal.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_RS485Polarity: Specify the polarity of USART RS485 Tx enable signal.
 *   This parameter can be one of the following values:
 *         @arg USART_RS485POL_LOW
 *         @arg USART_RS485POL_HIGH
 * @retval None
 ************************************************************************************************************/
void USART_RS485TxEnablePolarityConfig(USART_TypeDef* USARTx, u32 USART_RS485Polarity)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_RS485_POLARITY(USART_RS485Polarity));

  if (USART_RS485Polarity != USART_RS485POLARITY_HIGH)
  {
    USARTx->RCR |= USART_RS485POLARITY_LOW;
  }
  else
  {
    USARTx->RCR &= USART_RS485POLARITY_HIGH;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable forcing Tx pin to logic 0.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the USART break.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_ForceBreakCmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    USARTx->LCR |= USART_BREAK_ON;
  }
  else
  {
    USARTx->LCR &= USART_BREAK_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the USART interrupts.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_IER: Specify if the USART interrupt source to be enabled or disabled.
 *   This parameter can be one of the following values:
 *         @arg USART_IER_MSIE
 *         @arg USART_IER_RLSIE
 *         @arg USART_IER_THREIE
 *         @arg USART_IER_RDAIE
 *         @arg USART_IER_ENON
 * @param NewState: new state of the USART interrupts.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_IntConfig(USART_TypeDef* USARTx, u32 USART_IER, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    USARTx->IER |= USART_IER;
  }
  else
  {
    USARTx->IER &= ~USART_IER;
  }
}

/*********************************************************************************************************//**
 * @brief Get Interrupt ID value.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @retval The interrupt ID of USART.
 *          @arg USART_IID_RLS
 *          @arg USART_IID_RDA
 *          @arg USART_IID_CTI
 *          @arg USART_IID_THRE
 *          @arg USART_IID_MS
 *          @arg USART_IID_NON
 ************************************************************************************************************/
u8 USART_GetIntID(USART_TypeDef* USARTx)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));

  return (u8)USARTx->IIR;
}

/*********************************************************************************************************//**
 * @brief Configure the Rx FIFO Interrupt Trigger Level.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_RFITL: Specify the USART Rx FIFO interrupt trigger level.
 *   This parameter can be one of the following values:
 *          @arg USART_RFITL_01
 *          @arg USART_RFITL_04
 *          @arg USART_RFITL_08
 *          @arg USART_RFITL_14
 * @retval None
 ************************************************************************************************************/
void USART_RFITLConfig(USART_TypeDef* USARTx, u32 USART_RFITL)
{
  u32 tmpreg = 0x00;

  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_RFITL(USART_RFITL));

  tmpreg = USARTx->FCR & FCR_RFITL_CLEAR_Mask;
  /* Set the USART RFITL */
  USARTx->FCR = tmpreg | USART_RFITL;
}

/*********************************************************************************************************//**
 * @brief Configure the Tx FIFO Interrupt Trigger Level.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_TFITL: Specify the USART Tx FIFO interrupt trigger level.
 *   This parameter can be one of the following values:
 *         @arg USART_TFITL_00
 *         @arg USART_TFITL_02
 *         @arg USART_TFITL_04
 *         @arg USART_TFITL_08
 * @retval None
 ************************************************************************************************************/
void USART_TFITLConfig(USART_TypeDef* USARTx, u32 USART_TFITL)
{
  u32 tmpreg = 0x00;

  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_TFITL(USART_TFITL));

  tmpreg = USARTx->FCR & FCR_TFITL_CLEAR_Mask;
  /* Set the USART TFITL */
  USARTx->FCR = tmpreg | USART_TFITL;
}

/*********************************************************************************************************//**
 * @brief Enable or Disable time out interrupt of the USART.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the time out interrupt.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_TimeOutIntConfig(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    USARTx->TPR |= USART_TIMEOUT_ON;
  }
  else
  {
    USARTx->TPR &= USART_TIMEOUT_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Set the value of USART FIFO Time Out.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_TimeOut: Specify the value of Time Out.
 * @retval None
 ************************************************************************************************************/
void USART_SetTimeOutValue(USART_TypeDef* USARTx, u32 USART_TimeOut)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_TIMEOUT(USART_TimeOut));

  /* Set the USART time out */
  USARTx->TPR = (USARTx->TPR & TPR_RTOIC_Mask) | USART_TimeOut;
}

/*********************************************************************************************************//**
 * @brief  Clear both the write and read point in Tx FIFO or Rx FIFO.
 * @param  USARTx: where USARTx is the selected USART from the USART peripheral, x can be 0 or 1.
 * @param  USART_FIFODirection: Determine TX FIFO or Rx FIFO that is to be reset.
 *   This parameter can be any combination of the following values:
 *     @arg USART_FIFO_TX   : Tx FIFO is to be reset
 *     @arg USART_FIFO_RX   : Rx FIFO is to be reset
 * @retval None
 ************************************************************************************************************/
void USART_FIFOReset(USART_TypeDef* USARTx, u32 USART_FIFODirection)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_FIFO_DIRECTION(USART_FIFODirection));

  USARTx->FCR |= USART_FIFODirection;
}

/*********************************************************************************************************//**
 * @brief  Enable or Disable the USART stick parity function.
 * @param  USARTx: where USARTx is the selected USART from the USART peripheral, x can be 0 or 1.
 * @param  NewState: new state of the stick parity.
 *   This parameter can be: ENABLE or DISABLE
 * @retval None
 ************************************************************************************************************/
void USART_StickParityCmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    USARTx->LCR |= USART_SPE_ON;
  }
  else
  {
    USARTx->LCR &= USART_SPE_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief  Configure stick parity value of the USART.
 * @param  USARTx: where USARTx is the selected USART from the USART peripheral, x can be 0 or 1.
 * @param  USART_StickParity: Specify stick parity of the USART.
 *   This parameter can be one of the following values
 *         @arg USART_STICK_LOW
 *         @arg USART_STICK_HIGH
 * @retval None
 ************************************************************************************************************/
void USART_StickParityConfig(USART_TypeDef * USARTx, u32 USART_StickParity)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_STICK_PARITY(USART_StickParity));

  if (USART_StickParity != USART_STICK_HIGH)
  {
    USARTx->LCR |= USART_STICK_LOW;
  }
  else
  {
    USARTx->LCR &= USART_STICK_HIGH;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the USART Tx.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the USART Tx.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_TxCmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the Tx by setting the TXEN bit in the FCR register */
    USARTx->FCR |= USART_TXEN_ON;
  }
  else
  {
    /* Disable the Tx by clearing the TXEN bit in the FCR register */
    USARTx->FCR &= USART_TXEN_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the USART Rx.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the USART Rx.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_RxCmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the Rx by setting the RXEN bit in the FCR register */
    USARTx->FCR |= USART_RXEN_ON;
  }
  else
  {
    /* Disable the Rx by clearing the RXEN bit in the FCR register */
    USARTx->FCR &= USART_RXEN_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable inverting serial output function of IrDA on the specified USART.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the inverting serial output.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_IrDAInvtOutputCmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    USARTx->ICR |= USART_TXINV_ON;
  }
  else
  {
    USARTx->ICR &= USART_TXINV_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable inverting serial input function of IrDA on the specified USART.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the inverting serial input.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_IrDAInvtInputCmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    USARTx->ICR |= USART_RXINV_ON;
  }
  else
  {
    USARTx->ICR &= USART_RXINV_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the USART hardware flow control.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the USART Hardware Flow Control.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_HardwareFlowControlCmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the hardware flow control by setting the HFCEN bit in the FCR register */
    USARTx->MCR |= USART_HFCEN_ON;
  }
  else
  {
    /* Disable the hardware flow control by clearing the TXEN bit in the HFCEN register */
    USARTx->MCR &= USART_HFCEN_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the USART Tx PDMA.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the USART Tx PDMA request.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_TxPDMACmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the hardware flow control by setting the HFCEN bit in the FCR register */
    USARTx->MDR |= USART_TxPDMA_ON;
  }
  else
  {
    /* Disable the hardware flow control by clearing the TXEN bit in the HFCEN register */
    USARTx->MDR &= USART_TxPDMA_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the USART Rx PDMA.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the USART Rx PDMA request.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_RxPDMACmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the hardware flow control by setting the HFCEN bit in the FCR register */
    USARTx->MDR |= USART_RxPDMA_ON;
  }
  else
  {
    /* Disable the hardware flow control by clearing the TXEN bit in the HFCEN register */
    USARTx->MDR &= USART_RxPDMA_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the USART RS485 normal multi-drop operation mode.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the RS485 NMM.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_RS485NMMCmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the hardware flow control by setting the HFCEN bit in the FCR register */
    USARTx->RCR |= USART_RS485NMM_ON;
  }
  else
  {
    /* Disable the hardware flow control by clearing the TXEN bit in the HFCEN register */
    USARTx->RCR &= USART_RS485NMM_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Enable or Disable the USART RS485 normal multi-drop operation mode.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param NewState: new state of the USART RS485 AAD.
 *   This parameter can be: ENABLE or DISABLE.
 * @retval None
 ************************************************************************************************************/
void USART_RS485AADCmd(USART_TypeDef* USARTx, ControlStatus NewState)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_CONTROL_STATUS(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the hardware flow control by setting the HFCEN bit in the FCR register */
    USARTx->RCR |= USART_RS485AAD_ON;
  }
  else
  {
    /* Disable the hardware flow control by clearing the TXEN bit in the HFCEN register */
    USARTx->RCR &= USART_RS485AAD_OFF;
  }
}

/*********************************************************************************************************//**
 * @brief Set the specified USART RS485 address match value.
 * @param USARTx: where USARTx is USART to select the USART peripheral, x can be 0 or 1.
 * @param USART_AddressMatchValue: specify the RS485 address match value.
 * @retval None
 ************************************************************************************************************/
void USART_SetAddressMatchValue(USART_TypeDef* USARTx, u32 USART_AddressMatchValue)
{
  /* Check the parameters */
  Assert_Param(IS_USART(USARTx));
  Assert_Param(IS_USART_ADDRESS_MATCH_VALUE(USART_AddressMatchValue));

  /* Set the USART guard time */
  USARTx->RCR = (USARTx->RCR & RS485CR_ADDM_Mask) | (u32)(USART_AddressMatchValue<<0x08);

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
