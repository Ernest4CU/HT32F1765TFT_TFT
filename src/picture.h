﻿/*********************************************************************************************************//**
 * @file    SPI/LCD/picture.h
 * @version V1.0
 * @date    11/15/2011
 * @brief   The header file of lcd font & picture module.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/
/*********************************************************************************************************//**
 * @file    SPI/LCD/picture.h
 * @version V1.0
 * @date    2016年3月11日16:41:33
 * @modified   Ernest
 * @Commit 如需显示自定义图片，需用TFT图片提取软件提取图片（推荐使用Image2Lcd）
 *				格式：
 *					横屏显示
 *		    			16位真彩色
 *			    		C语言数组
 *				    	水平扫描
 *						自底至顶
 *						高位在前（MSB First）
 *						5-6-5格式
 *					竖屏显示
 *		    			16位真彩色
 *			    		C语言数组
 *				    	垂直扫描
 *						高位在前（MSB First）
 *						5-6-5格式
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/
unsigned char HT32_Table[] =
{
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,
0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,
0X80,0X10,0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0XFF,0XE0,
0XFF,0XE0,0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,
0X80,0X10,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,
0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,
0X80,0X10,0X80,0X10,0X80,0X10,0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,0X80,0X10,
0X80,0X10,0X80,0X10,0X80,0X10,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0XFF,0XE0,0X80,0X10,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,
0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0XFF,0XE0,0X80,0X10,0XFF,0XE0,0XFF,0XE0,
};