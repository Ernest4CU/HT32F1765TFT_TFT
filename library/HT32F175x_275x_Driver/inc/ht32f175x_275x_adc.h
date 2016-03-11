/*********************************************************************************************************//**
 * @file    ht32f175x_275x_adc.h
 * @version V1.0
 * @date    11/16/2010
 * @brief   The header file of the ADC library.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __ht32f175x_275x_ADC_H
#define __ht32f175x_275x_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x.h"

/** @addtogroup HT32F175x_275x_Peripheral_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/* Exported types ------------------------------------------------------------------------------------------*/

/** @defgroup ADC_Exported_Types ADC exported types
  * @{
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/

/** @defgroup ADC_Exported_Constants ADC exported constants
  * @{
  */

#define IS_ADC(x)                               (x == ADC)

#define ONE_SHOT_MODE                           (0x00000000)
#define CONTINUOUS_MODE                         (0x00000002)
#define DISCONTINUOUS_MODE                      (0x00000003)

#define IS_ADC_CONVERSION_MODE(ADC_MODE)        (((ADC_MODE) == ONE_SHOT_MODE) || \
                                                 ((ADC_MODE) == CONTINUOUS_MODE) || \
                                                 ((ADC_MODE) == DISCONTINUOUS_MODE))


#define ADC_CH_0                                (0)
#define ADC_CH_1                                (1)
#define ADC_CH_2                                (2)
#define ADC_CH_3                                (3)
#define ADC_CH_4                                (4)
#define ADC_CH_5                                (5)
#define ADC_CH_6                                (6)
#define ADC_CH_7                                (7)
#define ADC_CH_GNDREF                           (16)
#define ADC_CH_VREF                             (17)

#define IS_ADC_CHANNEL(CHANNEL)                 (((CHANNEL) == ADC_CH_0) || ((CHANNEL) == ADC_CH_1) || \
                                                 ((CHANNEL) == ADC_CH_2) || ((CHANNEL) == ADC_CH_3) || \
                                                 ((CHANNEL) == ADC_CH_4) || ((CHANNEL) == ADC_CH_5) || \
                                                 ((CHANNEL) == ADC_CH_6) || ((CHANNEL) == ADC_CH_7) || \
                                                 ((CHANNEL) == ADC_CH_GNDREF) || ((CHANNEL) == ADC_CH_VREF))

#define IS_ADC_INPUT_CHANNEL(CHANNEL)           (((CHANNEL) == ADC_CH_0) || ((CHANNEL) == ADC_CH_1) || \
                                                 ((CHANNEL) == ADC_CH_2) || ((CHANNEL) == ADC_CH_3) || \
                                                 ((CHANNEL) == ADC_CH_4) || ((CHANNEL) == ADC_CH_5) || \
                                                 ((CHANNEL) == ADC_CH_6) || ((CHANNEL) == ADC_CH_7) )


#define ADC_TRIG_SOFTWARE                       (0x10000000)

#define ADC_TRIG_BFTM0                          (0x80000000)
#define ADC_TRIG_BFTM1                          (0x80080000)

#define ADC_TRIG_MCTM_MTO                       (0x40000000)
#define ADC_TRIG_MCTM_CH0O                      (0x41000000)
#define ADC_TRIG_MCTM_CH1O                      (0x42000000)
#define ADC_TRIG_MCTM_CH2O                      (0x43000000)
#define ADC_TRIG_MCTM_CH3O                      (0x44000000)

#define ADC_TRIG_GPTM0_MTO                      (0x40020000)
#define ADC_TRIG_GPTM0_CH0O                     (0x41020000)
#define ADC_TRIG_GPTM0_CH1O                     (0x42020000)
#define ADC_TRIG_GPTM0_CH2O                     (0x43020000)
#define ADC_TRIG_GPTM0_CH3O                     (0x44020000)

#define ADC_TRIG_GPTM1_MTO                      (0x40030000)
#define ADC_TRIG_GPTM1_CH0O                     (0x41030000)
#define ADC_TRIG_GPTM1_CH1O                     (0x42030000)
#define ADC_TRIG_GPTM1_CH2O                     (0x43030000)
#define ADC_TRIG_GPTM1_CH3O                     (0x44030000)

#define ADC_TRIG_EXTI_0                         (0x20000000)
#define ADC_TRIG_EXTI_1                         (0x20000100)
#define ADC_TRIG_EXTI_2                         (0x20000200)
#define ADC_TRIG_EXTI_3                         (0x20000300)
#define ADC_TRIG_EXTI_4                         (0x20000400)
#define ADC_TRIG_EXTI_5                         (0x20000500)
#define ADC_TRIG_EXTI_6                         (0x20000600)
#define ADC_TRIG_EXTI_7                         (0x20000700)
#define ADC_TRIG_EXTI_8                         (0x20000800)
#define ADC_TRIG_EXTI_9                         (0x20000900)
#define ADC_TRIG_EXTI_10                        (0x20000A00)
#define ADC_TRIG_EXTI_11                        (0x20000B00)
#define ADC_TRIG_EXTI_12                        (0x20000C00)
#define ADC_TRIG_EXTI_13                        (0x20000D00)
#define ADC_TRIG_EXTI_14                        (0x20000E00)
#define ADC_TRIG_EXTI_15                        (0x20000F00)

#define IS_ADC_TRIG(REGTRIG)                    (((REGTRIG) == ADC_TRIG_GPTM0_MTO) || \
                                                 ((REGTRIG) == ADC_TRIG_GPTM0_CH0O) || \
                                                 ((REGTRIG) == ADC_TRIG_GPTM0_CH1O) || \
                                                 ((REGTRIG) == ADC_TRIG_GPTM0_CH2O) || \
                                                 ((REGTRIG) == ADC_TRIG_GPTM0_CH3O) || \
                                                 ((REGTRIG) == ADC_TRIG_GPTM1_MTO) || \
                                                 ((REGTRIG) == ADC_TRIG_GPTM1_CH0O) || \
                                                 ((REGTRIG) == ADC_TRIG_GPTM1_CH1O) || \
                                                 ((REGTRIG) == ADC_TRIG_GPTM1_CH2O) || \
                                                 ((REGTRIG) == ADC_TRIG_GPTM1_CH3O) || \
                                                 ((REGTRIG) == ADC_TRIG_MCTM_MTO) || \
                                                 ((REGTRIG) == ADC_TRIG_MCTM_CH0O) || \
                                                 ((REGTRIG) == ADC_TRIG_MCTM_CH1O) || \
                                                 ((REGTRIG) == ADC_TRIG_MCTM_CH2O) || \
                                                 ((REGTRIG) == ADC_TRIG_MCTM_CH3O) || \
                                                 ((REGTRIG) == ADC_TRIG_BFTM0) || \
                                                 ((REGTRIG) == ADC_TRIG_BFTM1) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_0) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_1) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_2) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_3) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_4) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_5) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_6) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_7) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_8) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_9) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_10) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_11) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_12) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_13) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_14) || \
                                                 ((REGTRIG) == ADC_TRIG_EXTI_15) || \
                                                 ((REGTRIG) == ADC_TRIG_SOFTWARE))


#define ADC_INT_SINGLE_EOC                      (0x00000001)
#define ADC_INT_SUB_GROUP_EOC                   (0x00000002)
#define ADC_INT_CYCLE_EOC                       (0x00000004)
#define ADC_INT_AWD_LOWER                       (0x00010000)
#define ADC_INT_AWD_UPPER                       (0x00020000)
#define ADC_INT_DATA_OVERWRITE                  (0x01000000)

#define IS_ADC_INT(INT)                         ((((INT) & 0xFEFCFFF8) == 0) && ((INT) != 0))


#define ADC_FLAG_SINGLE_EOC                     (0x00000001)
#define ADC_FLAG_SUB_GROUP_EOC                  (0x00000002)
#define ADC_FLAG_CYCLE_EOC                      (0x00000004)
#define ADC_FLAG_AWD_LOWER                      (0x00010000)
#define ADC_FLAG_AWD_UPPER                      (0x00020000)
#define ADC_FLAG_DATA_OVERWRITE                 (0x01000000)

#define IS_ADC_FLAG(FLAG)                       ((((FLAG) & 0xFEFCFFF8) == 0) && ((FLAG) != 0))


#define ADC_REGULAR_DATA0                       (0)
#define ADC_REGULAR_DATA1                       (1)
#define ADC_REGULAR_DATA2                       (2)
#define ADC_REGULAR_DATA3                       (3)
#define ADC_REGULAR_DATA4                       (4)
#define ADC_REGULAR_DATA5                       (5)
#define ADC_REGULAR_DATA6                       (6)
#define ADC_REGULAR_DATA7                       (7)

#define IS_ADC_REGULAR_DATA(DATA)               ((DATA) < 8)


#define ADC_AWD_DISABLE                         (u8)0x00
#define ADC_AWD_ALL_LOWER                       (u8)0x05
#define ADC_AWD_ALL_UPPER                       (u8)0x06
#define ADC_AWD_ALL_LOWER_UPPER                 (u8)0x07
#define ADC_AWD_SINGLE_LOWER                    (u8)0x01
#define ADC_AWD_SINGLE_UPPER                    (u8)0x02
#define ADC_AWD_SINGLE_LOWER_UPPER              (u8)0x03

#define IS_ADC_AWD(AWD)                         (((AWD) == ADC_AWD_DISABLE) || \
                                                 ((AWD) == ADC_AWD_ALL_LOWER) || \
                                                 ((AWD) == ADC_AWD_ALL_UPPER) || \
                                                 ((AWD) == ADC_AWD_ALL_LOWER_UPPER) || \
                                                 ((AWD) == ADC_AWD_SINGLE_LOWER) || \
                                                 ((AWD) == ADC_AWD_SINGLE_UPPER) || \
                                                 ((AWD) == ADC_AWD_SINGLE_LOWER_UPPER))

#define IS_ADC_THRESHOLD(THRESHOLD)             ((THRESHOLD) < 4096)


#define ADC_PDMA_REGULAR_SINGLE                 (0x00000001)
#define ADC_PDMA_REGULAR_SUBGROUP               (0x00000002)
#define ADC_PDMA_REGULAR_CYCLE                  (0x00000004)

#define IS_ADC_PDMA(PDMA)                       (((PDMA) == ADC_PDMA_REGULAR_SINGLE) || \
                                                 ((PDMA) == ADC_PDMA_REGULAR_SUBGROUP) || \
                                                 ((PDMA) == ADC_PDMA_REGULAR_CYCLE))


#define IS_ADC_REGULAR_RANK(RANK)               ((RANK) < 8)

#define IS_ADC_INPUT_SAMPLING_TIME(TIME)        ((TIME) < 256)

#define IS_ADC_REGULAR_LENGTH(LENGTH)           (((LENGTH) >= 1) && ((LENGTH) <= 8))

#define IS_ADC_REGULAR_SUB_LENGTH(SUB_LENGTH)   (((SUB_LENGTH) >= 1) && ((SUB_LENGTH) <= 8))

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------------------------------------*/

/** @defgroup ADC_Exported_Macro ADC exported macro
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/

/** @defgroup ADC_Exported_Functions ADC exported functions
  * @{
  */

void ADC_DeInit(ADC_TypeDef* ADCx);
void ADC_Reset(ADC_TypeDef* ADCx);

void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, u8 ADC_Channel, u8 Rank, u8 SampleClock);
void ADC_RegularGroupConfig(ADC_TypeDef* ADCx, u8 ADC_MODE, u8 Length, u8 SubLength);
void ADC_RegularTrigConfig(ADC_TypeDef* ADCx, u32 ADC_RegularTrigCtrl);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, ControlStatus NewState);
u16 ADC_GetConversionData(ADC_TypeDef* ADCx, u8 ADC_REGULAR_CH);

void ADC_IntConfig(ADC_TypeDef* ADCx, u32 ADC_INT, ControlStatus NewState);
FlagStatus ADC_GetIntStatus(ADC_TypeDef* ADCx, u32 ADC_INT);
void ADC_ClearIntPendingBit(ADC_TypeDef* ADCx, u32 ADC_INT);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, u32 ADC_FLAG);

void ADC_AWDConfig(ADC_TypeDef* ADCx, u32 ADC_AWD);
void ADC_AWDSingleChannelConfig(ADC_TypeDef* ADCx, u8 ADC_CH);
void ADC_AWDThresholdsConfig(ADC_TypeDef* ADCx, u16 UPPER, u16 LOWER);

void ADC_PDMAConfig(ADC_TypeDef* ADCx, u32 ADC_PDMA, ControlStatus NewState);

#ifdef __cplusplus
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* __HT32F175x_275x_ADC_H ---------------------------------------------------------------------------*/

