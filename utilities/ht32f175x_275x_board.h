/*********************************************************************************************************//**
 * @file    ht32f175x_275x_board.h
 * @version V1.0
 * @date    09/08/2011
 * @brief   HT32F175x/275x target board definition file.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/
#ifndef __HT32F175x_275x_BOARD_H
#define __HT32F175x_275x_BOARD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup HT32F175x_275x_Board_Abstraction_Layer
  * @{
  */

/** @defgroup HT32F175x_275x_Board_Exported_Types HT32F175x/275x Board exported types
  * @{
  */
/**
  * @}
  */

/** @defgroup HT32F175x_275x_Board_Exported_Constants HT32F125x/275x Board exported constants
  * @{
  */

/**
  * @brief  Uncomment the line corresponding to the HT32F175x/275x development
  *   board used in your application.
  *
  *  Tip: To avoid modifying this file each time you need to switch between these
  *       boards, you can define the board in your toolchain compiler preprocessor.
  */
#if !defined (USE_HT32F1755_2755_DVB)
 /* #define USE_HT32F1755_2755_DVB */
#endif

#ifdef USE_HT32F1755_2755_DVB
  #include "HT32F1755_2755_DVB\ht32f1755_2755_dvb.h"
#else
 #error "Please select first the USE_HT32F1755_2755_DVB board to be used (in ht32f1755_2755_board.h)"
#endif
/**
  * @}
  */

/** @defgroup HT32F175x_275x_Board_Exported_Macros HT32F125x/275x Board exported macros
  * @{
  */
/**
  * @}
  */

/** @defgroup HT32F175x_275x_Board_Exported_Functions HT32F125x/275x Board exported functions
  * @{
  */


#ifdef __cplusplus
}
#endif


#endif /* __HT32F175x_275x_BOARD_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

