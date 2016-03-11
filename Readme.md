#HT32F1765  ESK32-210 – HT32F1755/1765的开发板
2016年3月11日16:54:32

合泰固件库中提供了对应的TFT3P4263的工具：
主要公开工具：
void SPI_LCD_Init(void);	//LCD初始化
void SPI_LCD_Config(void);	//LCD配置
void SPI_LCD_BackColorSet(u16 Color);	//TFT背景色设置
void SPI_LCD_TextColorSet(u16 Color);	//TFT字体颜色设置
void SPI_LCD_CharDisplay(u8 Line_Num, u16 Column, u8 Ascii); 	//字符显示
void SPI_LCD_StringLineDisplay(u8 Line_Number, char *Sptr);	 	//字符串显示
void SPI_LCD_LineDraw(u8 X_Location, u16 Y_Location, u16 Length, u8 Direction);	//横竖两个方向画直线 Direction:Horizontal or Vertical
void SPI_LCD_RectDraw(u8 X_Location, u16 Y_Location, u8 Height, u16 Width);			//绘制矩形
void SPI_LCD_DisplayOff(void);	//关闭显示
void SPI_LCD_DisplayOn(void);		//开启显示
void SPI_LCD_delay(u32 nTime);	//毫秒级延时
void SPI_LCD_CircleDraw(u8 X_Location, u16 Y_Location, u16 Radius);	//画圆（圆的颜色由SPI_LCD_TextColorSet决定）
void SPI_LCD_Clear(u16 Clocr);	//清屏
void SPI_LCD_PicDraw(u8 X_Location, u16 Y_Location, u8 Height, u16 Width, uc8 *Cptr);	//绘制图片	
	//绘图（图片比较小，资源在picture.h中，TFT点阵提取工具使用的是Img2Lcd）
	//横屏显示下（C语言数组，水平扫描，选择16色真彩，不含图像头数据，高位在前，自底至顶扫描）
	//竖屏显示下（C语言数组，垂直扫描，选择16色真彩，不含图像头数据，高位在前，自底至顶扫描不选）
自有函数：
void SPI_LCD_SysTick_Config(void);
void SPI_LCD_TimingDelay(void);    
void SPI_LCD_WriteRegIndex(u8 LCD_Reg_Index);
void SPI_LCD_WriteReg(u8 LCD_Reg_Index, u16 LCD_Reg_Value);
u16  SPI_LCD_ReadReg(u8 LCD_Reg_Index);
void SPI_LCD_StarterSet(u16 X_Location, u16 Y_Location);
void SPI_LCD_WriteRAMPrior(void);
void SPI_LCD_WriteRAM(u16 RGB_Set);
void SPI_LCD_CharDraw(u8 X_Location, u16 Y_Location, u16 *Cptr);
void SPI_LCD_PicDraw(u8 X_Location, u16 Y_Location, u8 Height, u16 Width, uc8 *Cptr);
void SPI_LCD_WriteRAMWord(u16 RGB_Set);

使用此SDk的流程




注意：在中断中添加否则SPI_LCD_delay(10);延时函数不执行
	void SysTick_Handler(void){
			SPI_LCD_TimingDelay();
	}