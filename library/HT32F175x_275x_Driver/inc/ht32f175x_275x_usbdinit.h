/*********************************************************************************************************//**
 * @file    ht32f175x_275x_usbdinit.h
 * @version V1.0
 * @date    01/15/2013
 * @brief   The header file of the HT32F175x/275x USB Device Driver.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2013 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __HT32F175x_275x_USBDINIT_H
#define __HT32F175x_275x_USBDINIT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/

/** @addtogroup HT32F175x_275x_Peripheral_Driver
  * @{
  */

/** @addtogroup USBDevice
  * @{
  */

/* Exported types ------------------------------------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------*/
/* Endpoint 0 ~ 7 Configuration and checking                                                                */
/* !!! DO NOT MODIFY !!!                                                                                    */
/*----------------------------------------------------------------------------------------------------------*/

#define EP_TYPE_ISO         (1)
#define EP_TYPE_BULK        (2)
#define EP_TYPE_INT         (3)

/*----------------------------------------------------------------------------------------------------------*/
/* Endpoint0 Configuration and checking                                                                     */
/*----------------------------------------------------------------------------------------------------------*/
#define _EP0_CFG_EPEN       (1UL)
#define _EP0STADR           (USB_BASE + 0x400 + 0x8)
#define _EP0INTADR          (_EP0STADR)
#define _EP0OUTTADR         (_EP0STADR + _EP0LEN)
#define _EP0_CFG            ((_EP0_CFG_EPEN << 31) | \
                             (_EP0LEN       << 10) | \
                             (_EP0STADR & EPBUFA_MASK))
#define _EP0LEN_T           (_EP0LEN * 2)

#if (_EP0LEN != 8 && _EP0LEN != 16 && _EP0LEN != 32 && _EP0LEN != 64)
  #error "USB Buffer Length (EPLEN) of Control Endpoint0 must be 8, 16, 32, or 64 bytes."
#endif

/*----------------------------------------------------------------------------------------------------------*/
/* Endpoint1 Configuration and checking                                                                     */
/*----------------------------------------------------------------------------------------------------------*/
#define _EP1STADR           (_EP0STADR + (_EP0LEN * 2))

#if (_EP1_ENABLE == 1)
  #define _EP1LEN           (_EP1LEN_TMP)
#else
  #define _EP1LEN           (0)
#endif

#if (_EP1_CFG_EPEN_TMP == 1)
  #define _EP1_CFG_EPEN     (1UL)
#else
  #define _EP1_CFG_EPEN     (0UL)
#endif

#define _EP1_CFG            ((_EP1_CFG_EPEN  << 31) | \
                             (_EP1_CFG_EPDIR << 28) | \
                             (_EP1_CFG_EPADR << 24) | \
                             (_EP1LEN        << 10) | \
                             (_EP1STADR & EPBUFA_MASK))

#if (_EP1_ENABLE == 1)
  #if (_EP1_TYPR == EP_TYPE_BULK)
    #if (_EP1LEN != 8 && _EP1LEN != 16 && _EP1LEN != 32 && _EP1LEN != 64)
      #error "USB Buffer Length (EPLEN) of Endpoint1 must be 8, 16, 32, or 64 bytes under Bulk transfer."
    #endif
  #endif
  #if (_EP1LEN > 64)
    #error "USB Buffer Length (EPLEN) of Endpoint1 must be less than 64 bytes."
  #endif
  #if (_EP1LEN == 0)
    #error "USB Buffer Length (EPLEN) of Endpoint1 cannot be 0 byte."
  #endif
  #if ((_EP1LEN & 0x3) != 0x0)
    #error "USB Buffer Length (EPLEN) of Endpoint1 must be a multiple of 4 (word-aligned)."
  #endif
#endif

/*----------------------------------------------------------------------------------------------------------*/
/* Endpoint2 Configuration and checking                                                                     */
/*----------------------------------------------------------------------------------------------------------*/
#define _EP2STADR           (_EP1STADR + _EP1LEN)

#if (_EP2_ENABLE == 1)
  #define _EP2LEN           (_EP2LEN_TMP)
#else
  #define _EP2LEN           (0)
#endif

#if (_EP2_CFG_EPEN_TMP == 1)
  #define _EP2_CFG_EPEN     (1UL)
#else
  #define _EP2_CFG_EPEN     (0UL)
#endif

#define _EP2_CFG            ((_EP2_CFG_EPEN  << 31) | \
                             (_EP2_CFG_EPDIR << 28) | \
                             (_EP2_CFG_EPADR << 24) | \
                             (_EP2LEN        << 10) | \
                             (_EP2STADR & EPBUFA_MASK))

#if (_EP2_ENABLE == 1)
  #if (_EP2_TYPR == EP_TYPE_BULK)
    #if (_EP2LEN != 8 && _EP2LEN != 16 && _EP2LEN != 32 && _EP2LEN != 64)
      #error "USB Buffer Length (EPLEN) of Endpoint2 must be 8, 16, 32, or 64 bytes under Bulk transfer."
    #endif
  #endif
  #if (_EP2LEN > 64)
    #error "USB Buffer Length (EPLEN) of Endpoint2 must be less than 64 bytes."
  #endif
  #if (_EP2LEN == 0)
    #error "USB Buffer Length (EPLEN) of Endpoint2 cannot be 0 byte."
  #endif
  #if ((_EP2LEN & 0x3) != 0x0)
    #error "USB Buffer Length (EPLEN) of Endpoint2 must be a multiple of 4 (word-aligned)."
  #endif
#endif

/*----------------------------------------------------------------------------------------------------------*/
/* Endpoint3 Configuration and checking                                                                     */
/*----------------------------------------------------------------------------------------------------------*/
#define _EP3STADR           (_EP2STADR + _EP2LEN)

#if (_EP3_ENABLE == 1)
  #define _EP3LEN           (_EP3LEN_TMP)
#else
  #define _EP3LEN           (0)
#endif

#if (_EP3_CFG_EPEN_TMP == 1)
  #define _EP3_CFG_EPEN     (1UL)
#else
  #define _EP3_CFG_EPEN     (0UL)
#endif

#define _EP3_CFG            ((_EP3_CFG_EPEN  << 31) | \
                             (_EP3_CFG_EPDIR << 28) | \
                             (_EP3_CFG_EPADR << 24) | \
                             (_EP3LEN        << 10) | \
                             (_EP3STADR & EPBUFA_MASK))

#if (_EP3_ENABLE == 1)
  #if (_EP3_TYPR == EP_TYPE_BULK)
    #if (_EP3LEN != 8 && _EP3LEN != 16 && _EP3LEN != 32 && _EP3LEN != 64)
      #error "USB Buffer Length (EPLEN) of Endpoint3 must be 8, 16, 32, or 64 bytes under Bulk transfer."
    #endif
  #endif
  #if (_EP3LEN > 64)
    #error "USB Buffer Length (EPLEN) of Endpoint3 must be less than 64 bytes."
  #endif
  #if (_EP3LEN == 0)
    #error "USB Buffer Length (EPLEN) of Endpoint3 cannot be 0 byte."
  #endif
  #if ((_EP3LEN & 0x3) != 0x0)
    #error "USB Buffer Length (EPLEN) of Endpoint3 must be a multiple of 4 (word-aligned)."
  #endif
#endif

/*----------------------------------------------------------------------------------------------------------*/
/* Endpoint4 Configuration and checking                                                                     */
/*----------------------------------------------------------------------------------------------------------*/
#define _EP4STADR           (_EP3STADR + _EP3LEN)

#if (_EP4_ENABLE == 1)
  #define _EP4LEN           (_EP4LEN_TMP)
  #define _EP4LEN_T         (_EP4LEN_TMP * (_EP4_CFG_SDBS + 1))
#else
  #define _EP4LEN           (0)
  #define _EP4LEN_T         (0)
#endif
#if (_EP4_TYPR == EP_TYPE_ISO)
  #define _EP4_CFG_EPTYPE   (1)
#else
  #define _EP4_CFG_EPTYPE   (0)
#endif

#if (_EP4_CFG_EPEN_TMP == 1)
  #define _EP4_CFG_EPEN     (1UL)
#else
  #define _EP4_CFG_EPEN     (0UL)
#endif

#define _EP4_CFG            ((_EP4_CFG_EPEN   << 31) | \
                             (_EP4_CFG_EPTYPE << 29) | \
                             (_EP4_CFG_EPDIR  << 28) | \
                             (_EP4_CFG_EPADR  << 24) | \
                             (_EP4_CFG_SDBS   << 23) | \
                             (_EP4LEN         << 10) | \
                             (_EP4STADR & EPBUFA_MASK))

#if (_EP4_ENABLE == 1)
  #if (_EP4_TYPR == EP_TYPE_BULK)
    #if (_EP4LEN != 8 && _EP4LEN != 16 && _EP4LEN != 32 && _EP4LEN != 64)
      #error "USB Buffer Length (EPLEN) of Endpoint4 must be 8, 16, 32, or 64 bytes under Bulk transfer."
    #endif
  #endif
  #if (_EP4_TYPR == EP_TYPE_INT)
    #if (_EP4LEN > 64)
      #error "USB Buffer Length (EPLEN) of Endpoint4 must be less than 64 bytes under Interrupt transfer."
    #endif
  #endif
  #if (_EP4_TYPR == EP_TYPE_ISO)
    #if (_EP4LEN > 1023)
      #error "USB Buffer Length (EPLEN) of Endpoint4 must be less than 1023 bytes under Isochronous transfer."
    #endif
  #endif
  #if (_EP4LEN == 0)
    #error "USB Buffer Length (EPLEN) of Endpoint4 cannot be 0 byte."
  #endif
  #if ((_EP4LEN & 0x3) != 0x0)
    #error "USB Buffer Length (EPLEN) of Endpoint4 must be a multiple of 4 (word-aligned)."
  #endif
#endif

/*----------------------------------------------------------------------------------------------------------*/
/* Endpoint5 Configuration and checking                                                                     */
/*----------------------------------------------------------------------------------------------------------*/
#define _EP5STADR           (_EP4STADR + _EP4LEN_T)

#if (_EP5_ENABLE == 1)
  #define _EP5LEN           (_EP5LEN_TMP)
  #define _EP5LEN_T         (_EP5LEN_TMP * (_EP5_CFG_SDBS + 1))
#else
  #define _EP5LEN           (0)
  #define _EP5LEN_T         (0)
#endif
#if (_EP5_TYPR == EP_TYPE_ISO)
  #define _EP5_CFG_EPTYPE   (1)
#else
  #define _EP5_CFG_EPTYPE   (0)
#endif

#if (_EP5_CFG_EPEN_TMP == 1)
  #define _EP5_CFG_EPEN     (1UL)
#else
  #define _EP5_CFG_EPEN     (0UL)
#endif

#define _EP5_CFG            ((_EP5_CFG_EPEN   << 31) | \
                             (_EP5_CFG_EPTYPE << 29) | \
                             (_EP5_CFG_EPDIR  << 28) | \
                             (_EP5_CFG_EPADR  << 24) | \
                             (_EP5_CFG_SDBS   << 23) | \
                             (_EP5LEN         << 10) | \
                             (_EP5STADR & EPBUFA_MASK))

#if (_EP5_ENABLE == 1)
  #if (_EP5_TYPR == EP_TYPE_BULK)
    #if (_EP5LEN != 8 && _EP5LEN != 16 && _EP5LEN != 32 && _EP5LEN != 64)
      #error "USB Buffer Length (EPLEN) of Endpoint5 must be 8, 16, 32, or 64 bytes under Bulk transfer."
    #endif
  #endif
  #if (_EP5_TYPR == EP_TYPE_INT)
    #if (_EP5LEN > 64)
      #error "USB Buffer Length (EPLEN) of Endpoint5 must be less than 64 bytes under Interrupt transfer."
    #endif
  #endif
  #if (_EP5_TYPR == EP_TYPE_ISO)
    #if (_EP5LEN > 1023)
      #error "USB Buffer Length (EPLEN) of Endpoint5 must be less than 1023 bytes under Isochronous transfer."
    #endif
  #endif
  #if (_EP5LEN == 0)
    #error "USB Buffer Length (EPLEN) of Endpoint5 cannot be 0 byte."
  #endif
  #if ((_EP5LEN & 0x3) != 0x0)
    #error "USB Buffer Length (EPLEN) of Endpoint5 must be a multiple of 4 (word-aligned)."
  #endif
#endif

/*----------------------------------------------------------------------------------------------------------*/
/* Endpoint6 Configuration and checking                                                                     */
/*----------------------------------------------------------------------------------------------------------*/
#define _EP6STADR           (_EP5STADR + _EP5LEN_T)

#if (_EP6_ENABLE == 1)
  #define _EP6LEN           (_EP6LEN_TMP)
  #define _EP6LEN_T         (_EP6LEN_TMP * (_EP6_CFG_SDBS + 1))
#else
  #define _EP6LEN           (0)
  #define _EP6LEN_T         (0)
#endif
#if (_EP6_TYPR == EP_TYPE_ISO)
  #define _EP6_CFG_EPTYPE   (1)
#else
  #define _EP6_CFG_EPTYPE   (0)
#endif

#if (_EP6_CFG_EPEN_TMP == 1)
  #define _EP6_CFG_EPEN     (1UL)
#else
  #define _EP6_CFG_EPEN     (0UL)
#endif

#define _EP6_CFG            ((_EP6_CFG_EPEN   << 31) | \
                             (_EP6_CFG_EPTYPE << 29) | \
                             (_EP6_CFG_EPDIR  << 28) | \
                             (_EP6_CFG_EPADR  << 24) | \
                             (_EP6_CFG_SDBS   << 23) | \
                             (_EP6LEN         << 10) | \
                             (_EP6STADR & EPBUFA_MASK))

#if (_EP6_ENABLE == 1)
  #if (_EP6_TYPR == EP_TYPE_BULK)
    #if (_EP6LEN != 8 && _EP6LEN != 16 && _EP6LEN != 32 && _EP6LEN != 64)
      #error "USB Buffer Length (EPLEN) of Endpoint6 must be 8, 16, 32, or 64 bytes under Bulk transfer."
    #endif
  #endif
  #if (_EP6_TYPR == EP_TYPE_INT)
    #if (_EP6LEN > 64)
      #error "USB Buffer Length (EPLEN) of Endpoint6 must be less than 64 bytes under Interrupt transfer."
    #endif
  #endif
  #if (_EP6_TYPR == EP_TYPE_ISO)
    #if (_EP6LEN > 1023)
      #error "USB Buffer Length (EPLEN) of Endpoint6 must be less than 1023 bytes under Isochronous transfer."
    #endif
  #endif
  #if (_EP6LEN == 0)
    #error "USB Buffer Length (EPLEN) of Endpoint6 cannot be 0 byte."
  #endif
  #if ((_EP6LEN & 0x3) != 0x0)
    #error "USB Buffer Length (EPLEN) of Endpoint6 must be a multiple of 4 (word-aligned)."
  #endif
#endif

/*----------------------------------------------------------------------------------------------------------*/
/* Endpoint7 Configuration and checking                                                                     */
/*----------------------------------------------------------------------------------------------------------*/
#define _EP7STADR           (_EP6STADR + _EP6LEN_T)

#if (_EP7_ENABLE == 1)
  #define _EP7LEN           (_EP7LEN_TMP)
  #define _EP7LEN_T         (_EP7LEN_TMP * (_EP7_CFG_SDBS + 1))
#else
  #define _EP7LEN           (0)
#endif
#if (_EP7_TYPR == EP_TYPE_ISO)
  #define _EP7_CFG_EPTYPE   (1)
#else
  #define _EP7_CFG_EPTYPE   (0)
#endif

#if (_EP7_CFG_EPEN_TMP == 1)
  #define _EP7_CFG_EPEN     (1UL)
#else
  #define _EP7_CFG_EPEN     (0UL)
#endif

#define _EP7_CFG            ((_EP7_CFG_EPEN   << 31) | \
                             (_EP7_CFG_EPTYPE << 29) | \
                             (_EP7_CFG_EPDIR  << 28) | \
                             (_EP7_CFG_EPADR  << 24) | \
                             (_EP7_CFG_SDBS   << 23) | \
                             (_EP7LEN         << 10) | \
                             (_EP7STADR & EPBUFA_MASK))

#if (_EP7_ENABLE == 1)
  #if (_EP7_TYPR == EP_TYPE_BULK)
    #if (_EP7LEN != 8 && _EP7LEN != 16 && _EP7LEN != 32 && _EP7LEN != 64)
      #error "USB Buffer Length (EPLEN) of Endpoint7 must be 8, 16, 32, or 64 bytes under Bulk transfer."
    #endif
  #endif
  #if (_EP7_TYPR == EP_TYPE_INT)
    #if (_EP7LEN > 64)
      #error "USB Buffer Length (EPLEN) of Endpoint7 must be less than 64 bytes under Interrupt transfer."
    #endif
  #endif
  #if (_EP7_TYPR == EP_TYPE_ISO)
    #if (_EP7LEN > 1023)
      #error "USB Buffer Length (EPLEN) of Endpoint7 must be less than 1023 bytes under Isochronous transfer."
    #endif
  #endif
  #if (_EP7LEN == 0)
    #error "USB Buffer Length (EPLEN) of Endpoint7 cannot be 0 byte."
  #endif
  #if ((_EP7LEN & 0x3) != 0x0)
    #error "USB Buffer Length (EPLEN) of Endpoint7 must be a multiple of 4 (word-aligned)."
  #endif
#endif


/*----------------------------------------------------------------------------------------------------------*/
/* Check the endpoint address                                                                               */
/*----------------------------------------------------------------------------------------------------------*/
#if (_EP1_ENABLE == 1)
  #if (_EP1_CFG_EPADR == 0)
    #error "The address of Endpoint1 (EPADR) cannot be 0."
  #endif
  #if (_EP2_ENABLE == 1)
    #if (_EP1_CFG_EPADR == _EP2_CFG_EPADR)
      #error "The address of Endpoint1 (EPADR) conflicts with Endpoint2."
    #endif
  #endif
  #if (_EP3_ENABLE == 1)
    #if (_EP1_CFG_EPADR == _EP3_CFG_EPADR)
      #error "The address of Endpoint1 (EPADR) conflicts with Endpoint3."
    #endif
  #endif
  #if (_EP4_ENABLE == 1)
    #if (_EP1_CFG_EPADR == _EP4_CFG_EPADR)
      #error "The address of Endpoint1 (EPADR) conflicts with Endpoint4."
    #endif
  #endif
  #if (_EP5_ENABLE == 1)
    #if (_EP1_CFG_EPADR == _EP5_CFG_EPADR)
      #error "The address of Endpoint1 (EPADR) conflicts with Endpoint5."
    #endif
  #endif
  #if (_EP6_ENABLE == 1)
    #if (_EP1_CFG_EPADR == _EP6_CFG_EPADR)
      #error "The address of Endpoint1 (EPADR) conflicts with Endpoint6."
    #endif
  #endif
  #if (_EP7_ENABLE == 1)
    #if (_EP1_CFG_EPADR == _EP7_CFG_EPADR)
      #error "The address of Endpoint1 (EPADR) conflicts with Endpoint7."
    #endif
  #endif
#endif

#if (_EP2_ENABLE == 1)
  #if (_EP2_CFG_EPADR == 0)
    #error "The address of Endpoint2 (EPADR) cannot be 0."
  #endif
  #if (_EP1_ENABLE == 1)
    #if (_EP2_CFG_EPADR == _EP1_CFG_EPADR)
      #error "The address of Endpoint2 (EPADR) conflicts with Endpoint1."
    #endif
  #endif
  #if (_EP3_ENABLE == 1)
    #if (_EP2_CFG_EPADR == _EP3_CFG_EPADR)
      #error "The address of Endpoint2 (EPADR) conflicts with Endpoint3."
    #endif
  #endif
  #if (_EP4_ENABLE == 1)
    #if (_EP2_CFG_EPADR == _EP4_CFG_EPADR)
      #error "The address of Endpoint2 (EPADR) conflicts with Endpoint4."
    #endif
  #endif
  #if (_EP5_ENABLE == 1)
    #if (_EP2_CFG_EPADR == _EP5_CFG_EPADR)
      #error "The address of Endpoint2 (EPADR) conflicts with Endpoint5."
    #endif
  #endif
  #if (_EP6_ENABLE == 1)
    #if (_EP2_CFG_EPADR == _EP6_CFG_EPADR)
      #error "The address of Endpoint2 (EPADR) conflicts with Endpoint6."
    #endif
  #endif
  #if (_EP7_ENABLE == 1)
    #if (_EP2_CFG_EPADR == _EP7_CFG_EPADR)
      #error "The address of Endpoint2 (EPADR) conflicts with Endpoint7."
    #endif
  #endif
#endif

#if (_EP3_ENABLE == 1)
  #if (_EP3_CFG_EPADR == 0)
    #error "The address of Endpoint3 (EPADR) cannot be 0."
  #endif
  #if (_EP1_ENABLE == 1)
    #if (_EP3_CFG_EPADR == _EP1_CFG_EPADR)
      #error "The address of Endpoint3 (EPADR) conflicts with Endpoint1."
    #endif
  #endif
  #if (_EP2_ENABLE == 1)
    #if (_EP3_CFG_EPADR == _EP2_CFG_EPADR)
      #error "The address of Endpoint3 (EPADR) conflicts with Endpoint2."
    #endif
  #endif
  #if (_EP4_ENABLE == 1)
    #if (_EP3_CFG_EPADR == _EP4_CFG_EPADR)
      #error "The address of Endpoint3 (EPADR) conflicts with Endpoint4."
    #endif
  #endif
  #if (_EP5_ENABLE == 1)
    #if (_EP3_CFG_EPADR == _EP5_CFG_EPADR)
      #error "The address of Endpoint3 (EPADR) conflicts with Endpoint5."
    #endif
  #endif
  #if (_EP6_ENABLE == 1)
    #if (_EP3_CFG_EPADR == _EP6_CFG_EPADR)
      #error "The address of Endpoint3 (EPADR) conflicts with Endpoint6."
    #endif
  #endif
  #if (_EP7_ENABLE == 1)
    #if (_EP3_CFG_EPADR == _EP7_CFG_EPADR)
      #error "The address of Endpoint3 (EPADR) conflicts with Endpoint7."
    #endif
  #endif
#endif

#if (_EP4_ENABLE == 1)
  #if (_EP4_CFG_EPADR == 0)
    #error "The address of Endpoint4 (EPADR) cannot be 0."
  #endif
  #if (_EP1_ENABLE == 1)
    #if (_EP4_CFG_EPADR == _EP1_CFG_EPADR)
      #error "The address of Endpoint4 (EPADR) conflicts with Endpoint1."
    #endif
  #endif
  #if (_EP2_ENABLE == 1)
    #if (_EP4_CFG_EPADR == _EP2_CFG_EPADR)
      #error "The address of Endpoint4 (EPADR) conflicts with Endpoint2."
    #endif
  #endif
  #if (_EP3_ENABLE == 1)
    #if (_EP4_CFG_EPADR == _EP3_CFG_EPADR)
      #error "The address of Endpoint4 (EPADR) conflicts with Endpoint3."
    #endif
  #endif
  #if (_EP5_ENABLE == 1)
    #if (_EP4_CFG_EPADR == _EP5_CFG_EPADR)
      #error "The address of Endpoint4 (EPADR) conflicts with Endpoint5."
    #endif
  #endif
  #if (_EP6_ENABLE == 1)
    #if (_EP4_CFG_EPADR == _EP6_CFG_EPADR)
      #error "The address of Endpoint4 (EPADR) conflicts with Endpoint6."
    #endif
  #endif
  #if (_EP7_ENABLE == 1)
    #if (_EP4_CFG_EPADR == _EP7_CFG_EPADR)
      #error "The address of Endpoint4 (EPADR) conflicts with Endpoint7."
    #endif
  #endif
#endif

#if (_EP5_ENABLE == 1)
  #if (_EP5_CFG_EPADR == 0)
    #error "The address of Endpoint5 (EPADR) cannot be 0."
  #endif
  #if (_EP1_ENABLE == 1)
    #if (_EP5_CFG_EPADR == _EP1_CFG_EPADR)
      #error "The address of Endpoint5 (EPADR) conflicts with Endpoint1."
    #endif
  #endif
  #if (_EP2_ENABLE == 1)
    #if (_EP5_CFG_EPADR == _EP2_CFG_EPADR)
      #error "The address of Endpoint5 (EPADR) conflicts with Endpoint2."
    #endif
  #endif
  #if (_EP3_ENABLE == 1)
    #if (_EP5_CFG_EPADR == _EP3_CFG_EPADR)
      #error "The address of Endpoint5 (EPADR) conflicts with Endpoint3."
    #endif
  #endif
  #if (_EP4_ENABLE == 1)
    #if (_EP5_CFG_EPADR == _EP4_CFG_EPADR)
      #error "The address of Endpoint5 (EPADR) conflicts with Endpoint4."
    #endif
  #endif
  #if (_EP6_ENABLE == 1)
    #if (_EP5_CFG_EPADR == _EP6_CFG_EPADR)
      #error "The address of Endpoint5 (EPADR) conflicts with Endpoint6."
    #endif
  #endif
  #if (_EP7_ENABLE == 1)
    #if (_EP5_CFG_EPADR == _EP7_CFG_EPADR)
      #error "The address of Endpoint5 (EPADR) conflicts with Endpoint7."
    #endif
  #endif
#endif

#if (_EP6_ENABLE == 1)
  #if (_EP6_CFG_EPADR == 0)
    #error "The address of Endpoint6 (EPADR) cannot be 0."
  #endif
  #if (_EP1_ENABLE == 1)
    #if (_EP6_CFG_EPADR == _EP1_CFG_EPADR)
      #error "The address of Endpoint6 (EPADR) conflicts with Endpoint1."
    #endif
  #endif
  #if (_EP2_ENABLE == 1)
    #if (_EP6_CFG_EPADR == _EP2_CFG_EPADR)
      #error "The address of Endpoint6 (EPADR) conflicts with Endpoint2."
    #endif
  #endif
  #if (_EP3_ENABLE == 1)
    #if (_EP6_CFG_EPADR == _EP3_CFG_EPADR)
      #error "The address of Endpoint6 (EPADR) conflicts with Endpoint3."
    #endif
  #endif
  #if (_EP4_ENABLE == 1)
    #if (_EP6_CFG_EPADR == _EP4_CFG_EPADR)
      #error "The address of Endpoint6 (EPADR) conflicts with Endpoint4."
    #endif
  #endif
  #if (_EP5_ENABLE == 1)
    #if (_EP6_CFG_EPADR == _EP5_CFG_EPADR)
      #error "The address of Endpoint6 (EPADR) conflicts with Endpoint5."
    #endif
  #endif
  #if (_EP7_ENABLE == 1)
    #if (_EP6_CFG_EPADR == _EP7_CFG_EPADR)
      #error "The address of Endpoint6 (EPADR) conflicts with Endpoint7."
    #endif
  #endif
#endif

#if (_EP7_ENABLE == 1)
  #if (_EP7_CFG_EPADR == 0)
    #error "The address of Endpoint1 (EPADR) cannot be 0."
  #endif
  #if (_EP1_ENABLE == 1)
    #if (_EP7_CFG_EPADR == _EP1_CFG_EPADR)
      #error "The address of Endpoint7 (EPADR) conflicts with Endpoint1."
    #endif
  #endif
  #if (_EP2_ENABLE == 1)
    #if (_EP7_CFG_EPADR == _EP2_CFG_EPADR)
      #error "The address of Endpoint7 (EPADR) conflicts with Endpoint2."
    #endif
  #endif
  #if (_EP3_ENABLE == 1)
    #if (_EP7_CFG_EPADR == _EP3_CFG_EPADR)
      #error "The address of Endpoint7 (EPADR) conflicts with Endpoint3."
    #endif
  #endif
  #if (_EP4_ENABLE == 1)
    #if (_EP7_CFG_EPADR == _EP4_CFG_EPADR)
      #error "The address of Endpoint7 (EPADR) conflicts with Endpoint4."
    #endif
  #endif
  #if (_EP5_ENABLE == 1)
    #if (_EP7_CFG_EPADR == _EP5_CFG_EPADR)
      #error "The address of Endpoint7 (EPADR) conflicts with Endpoint5."
    #endif
  #endif
  #if (_EP6_ENABLE == 1)
    #if (_EP7_CFG_EPADR == _EP6_CFG_EPADR)
      #error "The address of Endpoint7 (EPADR) conflicts with Endpoint6."
    #endif
  #endif
#endif


/*----------------------------------------------------------------------------------------------------------*/
/* Check Buffer size                                                                                        */
/*----------------------------------------------------------------------------------------------------------*/
#if ((_EP0LEN_T + _EP1LEN + _EP2LEN + _EP3LEN + _EP4LEN_T + _EP5LEN_T + _EP6LEN_T + _EP7LEN_T) > 1024)
  #error "Total buffer size of Endpoint 0 ~ 7 must be less than 1024 bytes."
#endif



/* Exported functions --------------------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

/**
  * @}
  */
/* End of USBDevice group                                                                                   */

/**
  * @}
  */
/* End of HT32F175x_275x_Peripheral_Driver group                                                            */

#endif /* __HT32F175x_275x_USBDINIT_H ----------------------------------------------------------------------*/
