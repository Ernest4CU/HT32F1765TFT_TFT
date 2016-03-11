/*********************************************************************************************************//**
 * @file    syscalls.c
 * @version V1.0
 * @date    09/08/2011
 * @brief   Implementation of newlib syscall.
 *************************************************************************************************************
 *
 * <h2><center > Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>

#undef errno
extern int errno;
extern int  _end;


caddr_t _sbrk ( int incr )
{
  static unsigned char *heap;
  unsigned char *prev_heap;

  heap = (unsigned char *)&_end;
  prev_heap = heap;

  heap += incr;

  return (caddr_t) prev_heap;
}

int link(char *old, char *new) {
return -1;
}

int _close(int fd)
{
  return -1;
}

int _fstat(int fd, struct stat *st)
{
  st->st_mode = S_IFCHR;
  return 0;
}

int _isatty(int fd)
{
  return 1;
}

int _lseek(int fd, int ptr, int dir)
{
  return 0;
}

int _read(int fd, char *ptr, int len)
{
  return 0;
}

int _write(int fd, char *ptr, int len)
{
  return len;
}

void abort(void)
{
  /* Abort called */
  while(1);
}

/* --------------------------------- End Of File ------------------------------ */
