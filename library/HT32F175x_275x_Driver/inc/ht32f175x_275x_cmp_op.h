/*********************************************************************************************************//**
 * @file    ht32f175x_275x_cmp_op.h
 * @version V1.0
 * @date    11/16/2010
 * @brief   The header file of the CMP_OP library.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __ht32f175x_275x_CMP_OP_H
#define __ht32f175x_275x_CMP_OP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver
  * @{
  */

/** @addtogroup CMP_OP
  * @{
  */

/* Exported types ------------------------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Exported_Types CMP_OP exported types
  * @{
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Exported_Constants CMP_OP exported constants
  * @{
  */


/* CMP_OP Control */
/** @defgroup CMP_OP_Mode Definitions of CMP_OP modes
  * @{
  */
#define OP_MODE                       (0x00000000ul)
#define CMP_MODE                      (0x00000002ul)

#define IS_CMP_OP_MODE(MODE) ((MODE == OP_MODE) || (MODE == CMP_MODE))

/**
  * @}
  */

/** @defgroup CMP_OP_CancelationRef Definitions the cancelation reference input of CMP_OP
  * @{
  */
#define CMP_OP_NEGATIVE_INPUT         (0x00000000ul)
#define CMP_OP_POSITIVE_INPUT         (0x00000008ul)

#define IS_CMP_OP_REF(REF) ((REF == CMP_OP_NEGATIVE_INPUT ) || (REF == CMP_OP_POSITIVE_INPUT))

/**
  * @}
  */

/* CMP_OP Input Offset Voltage Cancellation */
/** @defgroup CMP_OP_Input_Offset Definitions of CMP_OP input offset
  * @{
  */
#define CMP_OP_IOVC_MIN               (0x00000000ul)
#define CMP_OP_IOVC_CENTER            (0x00000020ul)
#define CMP_OP_IOVC_MAX               (0x0000003Ful)

#define IS_CMP_OP_IOVC(IOVC)          (IOVC <= 63 )

/**
  * @}
  */

/* CMP_OP Interrupt */
/** @defgroup CMP_OP_Interrupt Definitions of CMP_OP interrupts
  * @{
  */
#define CMP_OP_INT_FALLING            (0x00000001ul)
#define CMP_OP_INT_RISING             (0x00000002ul)

#define IS_CMP_OP_INT(CMP_OP_INT) (((CMP_OP_INT & 0xFFFFFFFC) == 0x0) && \
                                   (CMP_OP_INT != 0x0))
/**
  * @}
  */

/* CMP_OP Interrupt Flag */
/** @defgroup CMP_OP_Interrupt_Flag Definitions of CMP_OP interrupt flags
  * @{
  */
#define CMP_OP_FLAG_FALLING           (0x00000001ul)
#define CMP_OP_FLAG_RISING            (0x00000002ul)

#define IS_CMP_OP_FLAG(FLAG)          (((FLAG & 0xFFFFFFFC) == 0x0) && \
                                       (FLAG != 0x0))
/**
  * @}
  */

/* CMP_OP BASE */
/**
 * @brief Used to check parameter of the CMP_OPx.
 */
#define IS_CMP_OP_ALL_PERIPH(PERIPH) ((PERIPH == CMP_OP0) || (PERIPH == CMP_OP1))

/**
  * @}
  *//* End of CMP_OP_Exported_Constants group */

/* Exported macro ------------------------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Exported_Macro CMP_OP exported macro
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/

/** @defgroup CMP_OP_Exported_Functions CMP_OP exported functions
  * @{
  */

void CMP_OP_DeInit(CMP_OP_TypeDef* CMP_OPx);
void CMP_OP_Config(CMP_OP_TypeDef* CMP_OPx, u32 mode, u32 cancellation);
void CMP_OP_Cmd(CMP_OP_TypeDef* CMP_OPx, ControlStatus NewState);
void CMP_OP_CancellationModeConfig(CMP_OP_TypeDef* CMP_OPx, u16 CMP_OP_REF_INPUT);
void CMP_OP_SetCancellationVaule(CMP_OP_TypeDef* CMP_OPx, u32 cancellation);
u32 CMP_OP_GetCancellationVaule(CMP_OP_TypeDef* CMP_OPx);
void CMP_OP_IntConfig(CMP_OP_TypeDef* CMP_OPx, u32 CMP_OP_INT, ControlStatus NewState);
FlagStatus CMP_OP_GetIntStatus(CMP_OP_TypeDef* CMP_OPx, u32 CMP_OP_INT);
FlagStatus CMP_OP_GetFlagStatus(CMP_OP_TypeDef* CMP_OPx, u32 CMP_OP_FLAG);
void CMP_OP_ClearIntPendingBit(CMP_OP_TypeDef* CMP_OPx, u32 CMP_OP_INT);
FlagStatus CMP_OP_GetOutputStatus(CMP_OP_TypeDef* CMP_OPx);

#ifdef __cplusplus
}
#endif

#endif /* __HT32F175x_275x_CMP_OP_H -------------------------------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
