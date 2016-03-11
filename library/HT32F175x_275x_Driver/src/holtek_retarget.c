/*********************************************************************************************************//**
 * @file    holtek_retarget.c
 * @version V1.0
 * @date    09/08/2011
 * @brief   Retarget layer for target-dependent low level functions.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f175x_275x.h"

#if (_RETARGET == 1)

#include <stdio.h>

#if defined   ( __CC_ARM   )
  #include <rt_misc.h>
#endif

/* Private typedef -----------------------------------------------------------------------------------------*/
/* Private define ------------------------------------------------------------------------------------------*/
#if defined   ( __CC_ARM   )
  #pragma import(__use_no_semihosting_swi)
#endif

/* Private macro -------------------------------------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------------------------------------*/

#if (RETARGET_PORT == RETARGET_ITM)
#define ITM_PORT8(n)    (*((vu8 *)(0xE0000000 + 4 * n)))
#define ITM_PORT16(n)   (*((vu16 *)(0xE0000000 + 4 * n)))
#define ITM_PORT32(n)   (*((vu32 *)(0xE0000000 + 4 * n)))

#define DEMCR           (*((vu32 *)(0xE000EDFC)))
#define TRCENA          (0x01000000)
#endif

/* Private function prototypes -----------------------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------------------------------------*/

#if defined (__CC_ARM)
struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;
#endif

int __backspace(FILE *stream)
{
  return 0;
}

int fputc (int ch, FILE *f)
{
  #if (RETARGET_PORT == RETARGET_ITM)
  if (DEMCR & TRCENA)
  {
    while (ITM_PORT32(0) == 0);
    ITM_PORT8(0) = ch;
  }
  return (ch);
  #else
  return (SERIAL_PutChar(ch));
  #endif
}

int fgetc (FILE *f)
{
  #if (RETARGET_PORT == RETARGET_ITM)
  return 0;
  #else
  return (SERIAL_GetChar());
  #endif
}

void _ttywrch(int ch)
{
  #if (RETARGET_PORT == RETARGET_ITM)
  if (DEMCR & TRCENA)
  {
    while (ITM_PORT32(0) == 0);
    ITM_PORT8(0) = ch;
  }
  #else
  SERIAL_PutChar(ch);
  #endif
}

void _sys_exit(int return_code)
{
label:  goto label;  /* endless loop                                                                        */
}

#endif
