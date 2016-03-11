 /*********************************************************************************************************//**
 * @file    spi_flash.c
 * @version V1.0
 * @date    09/08/2011
 * @brief   This file provides a set of functions needed to manage the
 *          communication between SPI peripheral and SPI SST25VF016B FLASH.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "spi_flash.h"
/** @addtogroup Utilities
  * @{
  */

/** @addtogroup HT32F1755_2755_Development_Board
  * @{
  */

/** @addtogroup SPI_FLASH SPI_FLASH
  * @{
  */

/* Private typedef -----------------------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Private_TypesDefinitions SPI FLASH private types definitions
  * @{
  */

/**
  * @}
  */

/* Private define ------------------------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Private_Define SPI FLASH private definitions
  * @{
  */

/**
  * @}
  */

/* Private macro -------------------------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Private_Macro SPI FLASH private macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Private_Values SPI FLASH private variables
  * @{
  */
extern const u32 DVB_GpioClock[DVB_GPIO_NBR];
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Private_Function_Prototypes SPI FLASH private function prototypes
  * @{
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------------------------------------*/

/** @defgroup SPI_FLASH_Private_Functions SPI FLASH private functions
  * @{
  */

/*********************************************************************************************************//**
  * @brief  Initializes peripherals used by the SPI flash driver.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_Init(void)
{
  SPI_InitTypeDef  SPI_InitStructure;

  /*  Enable AFIO & SPI SEL pin port & SPI clock  */
  CKCU_APBPerip0ClockConfig(CKCU_APBEN0_AFIO | DVB_GpioClock[FLASH_SPI_SEL_GPIO_ID] | FLASH_SPI_CLK, ENABLE);

  /*  Configure SPI SEL pin  */
  GPIO_SetOutBits(FLASH_SPI_SEL_GPIO_PORT, FLASH_SPI_SEL_GPIO_PIN);
  GPIO_DirectionConfig(FLASH_SPI_SEL_GPIO_PORT, FLASH_SPI_SEL_GPIO_PIN, GPIO_DIR_OUT);

  /*  Configure SPI SCK pin, SPI MISO pin, SPI MOSI pin  */
  HT32F_DVB_GPxConfig(FLASH_SPI_SCK_GPIO_ID, FLASH_SPI_SCK_AFIO_PIN, FLASH_SPI_SCK_AFIO_MODE);
  HT32F_DVB_GPxConfig(FLASH_SPI_MISO_GPIO_ID, FLASH_SPI_MISO_AFIO_PIN, FLASH_SPI_MISO_AFIO_MODE);
  HT32F_DVB_GPxConfig(FLASH_SPI_MOSI_GPIO_ID, FLASH_SPI_MOSI_AFIO_PIN, FLASH_SPI_MOSI_AFIO_MODE);

  /*  SPI Configuration */
  SPI_InitStructure.SPI_Mode = SPI_MASTER;
  SPI_InitStructure.SPI_FIFO = SPI_FIFO_DISABLE;
  SPI_InitStructure.SPI_DataLength = SPI_DATALENGTH_8;
  SPI_InitStructure.SPI_SELMode = SPI_SEL_SOFTWARE;
  SPI_InitStructure.SPI_SELPolarity = SPI_SELPOLARITY_LOW;
  SPI_InitStructure.SPI_FirstBit = SPI_FIRSTBIT_MSB;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_HIGH;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_SECOND;
  SPI_InitStructure.SPI_RxFIFOTriggerLevel = 0;
  SPI_InitStructure.SPI_TxFIFOTriggerLevel = 0;
  SPI_InitStructure.SPI_ClockPrescaler = 4;
  SPI_Init(FLASH_SPI, &SPI_InitStructure);

  SPI_SELOutputCmd(FLASH_SPI, ENABLE);

  SPI_Cmd(FLASH_SPI, ENABLE);
}

/*********************************************************************************************************//**
  * @brief  Erases the specified FLASH sector.
  * @param  SectorAddr: address of the sector to erase.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_SectorErase(u32 SectorAddr)
{
  /* Send write enable instruction */
  SPI_FLASH_WriteEnable();

  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();
  /* Send "Sector Erase" instruction */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_SE);
  /* Send high byte address of SectorAddr */
  SPI_FLASH_SendByte((SectorAddr & 0xFF0000) >> 16);
  /* Send medium byte address of SectorAddr */
  SPI_FLASH_SendByte((SectorAddr & 0xFF00) >> 8);
  /* Send low byte address of SectorAddr */
  SPI_FLASH_SendByte(SectorAddr & 0xFF);
  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();

  /* Wait the write opertaion has completed */
  SPI_FLASH_WaitForWriteEnd();
}

/*********************************************************************************************************//**
  * @brief  Erases the entire FLASH.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_ChipErase(void)
{
  /* Send write enable instruction */
  SPI_FLASH_WriteEnable();

  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();
  /* Send "Chip Erase" instruction  */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_CE);
  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();

  /* Wait the write opertaion has completed */
  SPI_FLASH_WaitForWriteEnd();
}

/*********************************************************************************************************//**
  * @brief  Writes one byte to the FLASH.
  * @param  DataByte : the data byte to be written to the FLASH.
  * @param  WriteAddr : FLASH's internal address to write to.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_ByteWrite(u8 DataByte, u32 WriteAddr)
{
  /* Enable the write access to the FLASH */
  SPI_FLASH_WriteEnable();

  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();
  /* Send "Program one data byte " instruction */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_BP);
  /* Send high byte address of WriteAddr */
  SPI_FLASH_SendByte((WriteAddr & 0xFF0000) >> 16);
  /* Send medium byte address of WriteAddo */
  SPI_FLASH_SendByte((WriteAddr & 0xFF00) >> 8);
  /* Send low byte address of WriteAddr */
  SPI_FLASH_SendByte(WriteAddr & 0xFF);

  /* Send a byte to the FLASH */
  SPI_FLASH_SendByte(DataByte);

  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();

  /* Wait the write opertaion has completed */
  SPI_FLASH_WaitForWriteEnd();
}

/*********************************************************************************************************//**
  * @brief  Writes block of data to the FLASH using Automatic Address Increment Programming.
  * @param  WriteBuffer : pointer to the buffer  containing the data to be written to the FLASH.
  * @param  WriteAddr : FLASH's internal address to write to.
  * @param  NumOfWriteByte : number of bytes to write to the FLASH.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_AAIWrite(u8* WriteBuffer, u32 WriteAddr, u16 NumOfWriteByte)
{
  u16 temp, NumOfWrite = NumOfWriteByte/2;

  /* Enable the write access to the FLASH */
  SPI_FLASH_WriteEnable();

  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();
  /* Send "Automatic Address Increment Programming" instruction */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_AAI);
  /* Send high byte address of WriteAddr */
  SPI_FLASH_SendByte((WriteAddr & 0xFF0000) >> 16);
  /* Send medium byte address of WriteAddr */
  SPI_FLASH_SendByte((WriteAddr & 0xFF00) >> 8);
  /* Send low byte address of WriteAddr */
  SPI_FLASH_SendByte(WriteAddr & 0xFF);

  for(temp = 0; temp < 2; temp++)
  {
    /* Send the current byte */
    SPI_FLASH_SendByte(*WriteBuffer);
    /* Point on the next byte to be written */
    WriteBuffer++;
  }

  NumOfWrite--;

  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();

  /* Wait the write opertaion has completed */
  SPI_FLASH_WaitForWriteEnd();

  if(NumOfWrite)
  {
    while(NumOfWrite--)
    {
      /* Select the SPI FLASH */
      SPI_FLASH_SEL_ACTIVE();
      /* Send "Automatic Address Increment Programming" instruction */
      SPI_FLASH_SendByte(SPI_FLASH_CMD_AAI);

      for(temp = 0; temp < 2; temp++)
      {
        /* Send the current byte */
        SPI_FLASH_SendByte(*WriteBuffer);
        /* Point on the next byte to be written */
        WriteBuffer++;
      }

      /* Deselect the SPI FLASH */
      SPI_FLASH_SEL_INACTIVE();

      /* Wait the end of Flash writing */
      SPI_FLASH_WaitForWriteEnd();

    }
  }

  /* Disable the write access to the FLASH */
  SPI_FLASH_WriteDisable();
}

/*********************************************************************************************************//**
  * @brief  Writes block of data to the FLASH.
  * @param  WriteBuffer : pointer to the buffer  containing the data to be written to the FLASH.
  * @param  WriteAddr : FLASH's internal address to write to.
  * @param  NumOfWriteByte : number of bytes to write to the FLASH.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_BufferWrite(u8* WriteBuffer, u32 WriteAddr, u16 NumOfWriteByte)
{
  u8 NumOfSingle = 0, Addr = 0;
  u16 NumOfPage = 0;

  Addr = WriteAddr % 2;
  NumOfPage =  NumOfWriteByte / 2;
  NumOfSingle = NumOfWriteByte % 2;

  if(Addr == 0)
  {
    if(NumOfPage == 0) /* Only one byte to be written to */
    {
      SPI_FLASH_ByteWrite(*WriteBuffer, WriteAddr);
    }
    else
    {
      SPI_FLASH_AAIWrite(WriteBuffer, WriteAddr, NumOfWriteByte);
      WriteAddr +=  NumOfWriteByte;
      WriteBuffer += NumOfWriteByte;
    }

    if(NumOfSingle)
    {
      SPI_FLASH_ByteWrite(*WriteBuffer, WriteAddr);
    }
  }
  else
  {
    if(NumOfPage== 0) /* Only one byte to be written to */
    {
      SPI_FLASH_ByteWrite(*WriteBuffer, WriteAddr);
    }
    else
    {
      SPI_FLASH_ByteWrite(*WriteBuffer, WriteAddr);
      WriteAddr +=  1;
      WriteBuffer += 1;

      SPI_FLASH_AAIWrite(WriteBuffer, WriteAddr, NumOfWriteByte);
      WriteAddr +=  NumOfWriteByte;
      WriteBuffer += NumOfWriteByte;

      if(NumOfSingle)
      {
        SPI_FLASH_ByteWrite(*WriteBuffer, WriteAddr);
      }
     }
   }
}

/*********************************************************************************************************//**
  * @brief  Reads a block of data from the FLASH.
  * @param  ReadBuffer : pointer to the buffer that receives the data read from the FLASH.
  * @param  ReadAddr : FLASH's internal address to read from.
  * @param  NumOfReadByte : number of bytes to read from the FLASH.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_BufferRead(u8* ReadBuffer, u32 ReadAddr, u16 NumOfReadByte)
{
  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();

  /* Send "Read from Memory " instruction */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_READ);

  /* Send high byte address of ReadAddr */
  SPI_FLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
  /* Send medium byte address of ReadAddr */
  SPI_FLASH_SendByte((ReadAddr& 0xFF00) >> 8);
  /* Send low byte address of ReadAddr */
  SPI_FLASH_SendByte(ReadAddr & 0xFF);


  while(NumOfReadByte--)
  {
    /* Read a byte from the FLASH */
    *ReadBuffer = SPI_FLASH_SendByte(SPI_FLASH_DUMMY_BYTE);
    /* Point to the next location where the byte read will be saved */
    ReadBuffer++;
  }

  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();
}

/*********************************************************************************************************//**
  * @brief  Reads JEDEC ID.
  * @retval JEDEC ID value.
  ***********************************************************************************************************/
u32 SPI_FLASH_ReadJEDECID(void)
{
  u32 Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;

  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();

  /* Send "JEDEC Read-ID" instruction */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_JEDECID);

  /* Read a byte from the FLASH */
  Temp0 = SPI_FLASH_SendByte(SPI_FLASH_DUMMY_BYTE);

  /* Read a byte from the FLASH */
  Temp1 = SPI_FLASH_SendByte(SPI_FLASH_DUMMY_BYTE);

  /* Read a byte from the FLASH */
  Temp2 = SPI_FLASH_SendByte(SPI_FLASH_DUMMY_BYTE);

  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();

  Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;

  return Temp;

}

/*********************************************************************************************************//**
  * @brief  Writes the new value to the Status Register.
  * @param  Value : the new value to be written to the Status Register.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_WriteStatus(u8 Value)
{
  SPI_FLASH_WriteEnable();

  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();

  /* Send "Write Status Register" instruction */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_WRSR);
  /* Writes to the Status Register */
  SPI_FLASH_SendByte(Value);

  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();
}

/*********************************************************************************************************//**
  * @brief  Sends a byte through the SPI interface and return the byte received from the SPI bus.
  * @param  byte : byte to send.
  * @retval The value of the received byte.
  ***********************************************************************************************************/
u8 SPI_FLASH_SendByte(u8 byte)
{
  /* Loop while Tx buffer register is empty */
  while(!SPI_GetFlagStatus(FLASH_SPI, SPI_FLAG_TXBE));

  /* Send byte through the SPIx peripheral */
  SPI_SendData(FLASH_SPI, byte);

  /* Loop while Rx is not empty */
  while(!SPI_GetFlagStatus(FLASH_SPI, SPI_FLAG_RXBNE));

  /* Return the byte read from the SPI */
  return SPI_ReceiveData(FLASH_SPI);
}

/*********************************************************************************************************//**
  * @brief  Enables the write access to the FLASH.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_WriteEnable(void)
{
  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();

  /* Send "Write Enable" instruction */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_WREN);

  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();
}

/*********************************************************************************************************//**
  * @brief  Disables the write access to the FLASH.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_WriteDisable(void)
{
  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();

  /* Send "Write Disable" instruction */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_WRDI);

  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();
}

/*********************************************************************************************************//**
  * @brief  Polls the status of the BUSY flag in the FLASH's status register and waits for the end of Flash
            writing.
  * @retval None
  ***********************************************************************************************************/
void SPI_FLASH_WaitForWriteEnd(void)
{
  u8 FLASH_Status = 0;

  /* Select the SPI FLASH */
  SPI_FLASH_SEL_ACTIVE();

  /* Send "Read Status Register" instruction */
  SPI_FLASH_SendByte(SPI_FLASH_CMD_RDSR);

  /* Loop as long as the busy flag is set */
  do
  {
    /* Send a dummy byte to generate the clock to read the value of the status register */
    FLASH_Status = SPI_FLASH_SendByte(SPI_FLASH_DUMMY_BYTE);

  } while((FLASH_Status & SPI_FLASH_BUSY_FLAG) == SET);

  /* Deselect the SPI FLASH */
  SPI_FLASH_SEL_INACTIVE();
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
