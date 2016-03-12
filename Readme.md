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
	
私有函数（一般不在逻辑层进行调用的函数）：
void SPI_LCD_SysTick_Config(void);	
	//Configure SYSTICK 开启SysTick时钟，SysTick时钟源选择为SYSTICK_SRC_STCLK（9M）SysTick的重载间隔为1ms，并开启SysTick定时器
	//此函数会在SPI_LCD_Init(void)函数中调用，既在LCD功能初始化时就开启了SysTick定时器，因为SPI_LCD功能函数会用到SysTick定时器来延时
	//此函数主要功能：
		开启StsTick定时器，以便于SPI_LCD_TimingDelay()延时函数的正常运行，SysTick可形成以1s为基的延时，
	//若想延时1S，则操作方法如下：
		SPI_LCD_SysTick_Config(void);	//先要开启SysTick定时器，但此函数一般在SPI_LCD_Init(void)函数中进行了调用
		
		在需要的地方使用SPI_LCD_TimingDelay(1000)；即可1000代表1000ms
		
void SPI_LCD_TimingDelay(void);	
	//延时函数，最小延时单位由SPI_LCD_SysTick_Config(void)决定（默认为1ms）
void SPI_LCD_WriteRegIndex(u8 LCD_Reg_Index);
	//选择需要写入的寄存器，被SPI_LCD_WriteReg()函数使用
void SPI_LCD_WriteReg(u8 LCD_Reg_Index, u16 LCD_Reg_Value);
	//向LCD_Reg_Index寄存器中写入LCD_Reg_Value
u16  SPI_LCD_ReadReg(u8 LCD_Reg_Index);
	//读取LCD_Reg_Index寄存器中的内容
void SPI_LCD_StarterSet(u16 X_Location, u16 Y_Location);
	//设置指针的位置（应该是设置光标起点）
void SPI_LCD_WriteRAMPrior(void);
	//准备将数据写入LCD_RAM
void SPI_LCD_WriteRAM(u16 RGB_Set);
	//写数据到LCD_RAM
void SPI_LCD_CharDraw(u8 X_Location, u16 Y_Location, u16 *Cptr);
	//被SPI_LCD_CharDisplay()函数调用，来显示字符（可模仿此函数来编写，带字号的中英文）
void SPI_LCD_WriteRAMWord(u16 RGB_Set);
	//向LCD_RAM中写入1字（16位），
	//与SPI_LCD_WriteRAM区别是自带SPI_LCD_WriteRAMPrior(void)函数


使用此SDk的流程（按如下操作即可正常使用HT32F1765_TFT SDK）
	1.SPI_LCD_Init(void);	//首先进行初始化
	2.在ht32f175x_275x_it.c 头部添加如下代码extern void SPI_LCD_TimingDelay(void);
	3.在ht32f175x_275x_it.c中添加SysTick中断处理代码效果如下
				/*********************************************************************************************************//**
				 * @brief   This function handles SysTick Handler.
				 * @retval  None
				 ************************************************************************************************************/
				void SysTick_Handler(void)
				{
				  SPI_LCD_TimingDelay();
				}
	4.在初始部分添加初始化和配置代码如下
		  /* Initialize LCD related peripheral */
		  SPI_LCD_Init();
		
		  /* LCD driver configuration */
		  SPI_LCD_Config();
/****至此HT32F1765 TFT3P4263初始化完毕，之后只需在需要的地方使用公开工具进行屏幕绘图即可****/
	



注意：在中断中添加否则SPI_LCD_delay(10);延时函数不执行
	void SysTick_Handler(void){
			SPI_LCD_TimingDelay();
	}	SPI_LCD_TimingDelay();
	}