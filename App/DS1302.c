/*
 * @Author: Zale
 * @Date: 2020-03-23 20:37:20
 * @LastEditTime: 2020-03-26 17:41:24
 * @LastEditors: Please set LastEditors
 * @Description: DS1302驱动
 * @FilePath: \Nixie\App\DS1302.c
 */

#include <DS1302.h>

//---DS1302写入和读取时分秒的地址命令---//
//---秒分时日月周年 最低位读写位;-------//
uchar READ_RTC_ADDR[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d}; 
uchar WRITE_RTC_ADDR[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};

//---DS1302时钟初始化2016年5月7日星期六12点00分00秒。---//
//---存储顺序是秒分时日月周年,存储格式是用BCD码---//
uchar TIME[7] = {0, 0, 0x12, 0x07, 0x05, 0x06, 0x16};

/**
 * @Name: DS1302_Write
 * @Author:	frumig
 * LastEditor: Zale
 * @Brief:  DS1302引脚配置
 * @Param:  none
 * @Example:  
 * @Retval:  
 */
void DS1302_GPIO_Config()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_Cfg;
	GPIO_Cfg.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Cfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Cfg.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOB, &GPIO_Cfg); 

	GPIO_Cfg.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Cfg.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Cfg.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOB, &GPIO_Cfg); 
}
/**
 * Name：DS1302_Turn_IO
 * @Author: Zale
 * @LastEditor:	Zale
 * @Brief: 转变DS1302IO脚的方向 
 * @Param: 1 input 0 output
 * @Example: 
 * @Retval: 
 */
void DS1302_Turn_IO(uchar dir)
{
	GPIO_InitTypeDef GPIO_Cfg;
    if(dir)
	{
		GPIO_Cfg.GPIO_Mode = GPIO_Mode_IPD;
		GPIO_Cfg.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Cfg.GPIO_Pin = GPIO_Pin_7;
		GPIO_Init(GPIOB, &GPIO_Cfg); 
	}
	else
	{
		GPIO_Cfg.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Cfg.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Cfg.GPIO_Pin = GPIO_Pin_7;
		GPIO_Init(GPIOB, &GPIO_Cfg); 
	}
}

/**
 * @Name: DS1302_Write
 * @Author:	Zale
 * LastEditor: Zale
 * @Brief:  DS1302写入8字节
 * @Param:  addr 器件地址, dat 写入的数据
 * @Example:  
 * @Retval:  
 */
void DS1302_Write(uchar addr, uchar dat)
{
	uchar n;
	DS1302_Turn_IO(0);
    DSRST_L;
	delay_us(5);

	DSCLK_L;//先将SCLK置低电平。
	delay_us(5);
	DSRST_H; //然后将RST(CE)置高电平。
	delay_us(5);

	for (n=0; n<8; n++)	//开始传送八位地址命令
	{
		if (addr & 0x01)	//数据从低位开始传送
			DSIO_H;
		else DSIO_L;
		addr >>= 1;
		DSCLK_H;	//数据在上升沿时，DS1302读取数据
		delay_us(5);
		DSCLK_L;
		delay_us(5);
	}
	for (n=0; n<8; n++)//写入8位数据
	{
		if (dat & 0x01)	//数据从低位开始传送
			DSIO_H;
		else DSIO_L;
		dat >>= 1;
		DSCLK_H;//数据在上升沿时，DS1302读取数据
		delay_us(5);
		DSCLK_L;
		delay_us(5);
	}

	DSRST_L;//传送数据结束
	delay_us(95);
}

/**
 * @Name: DS1302_Write
 * @Author:	Zale
 * LastEditor: Zale
 * @Brief:  DS1302读取8字节
 * @Param:  addr 器件地址
 * @Example:  
 * @Retval:   读取到的8位数据
 */
uchar DS1302_Read(uchar addr)
{
	uchar n,dat,dat1;
	DS1302_Turn_IO(0);
	DSRST_L;
	delay_us(5);

	DSCLK_L;//先将SCLK置低电平。
	delay_us(5);
	DSRST_H;//然后将RST(CE)置高电平。
	delay_us(5);

	for(n=0; n<8; n++)//开始传送八位地址命令
	{
		if (addr & 0x01)	//数据从低位开始传送
			DSIO_H;
		else DSIO_L;
		addr >>= 1;
		DSCLK_H;//数据在上升沿时，DS1302读取数据
		delay_us(5);
		DSCLK_L;//DS1302下降沿时，放置数据
		delay_us(5);
	}
	DS1302_Turn_IO(1);
	delay_us(15);
	for(n=0; n<8; n++)	//读取8位数据
	{
		dat1 = DSIO_R;	//从最低位开始接收
		dat = (dat>>1) | (dat1<<7);
		DSCLK_H;
		delay_us(5);
		DSCLK_L;//DS1302下降沿时，放置数据
		delay_us(5);
	}
	DS1302_Turn_IO(0);
	DSRST_L;
	delay_us(5);	//以下为DS1302复位的稳定时间,必须的。
	DSCLK_H;
	delay_us(5);
	DSIO_L;
	delay_us(5);
	DSIO_H;
	delay_us(5);
	return dat;	
}

/**
 * @Name: DS1302_Init
 * @Author:	Zale
 * LastEditor: Zale
 * @Brief:  DS1302初始化
 * @Param:  
 * @Example:  
 * @Retval:  
 */
void DS1302_Init()
{
	uchar n;
	DS1302_Write(0x8E,0X00);		 //禁止写保护，就是关闭写保护功能
	for (n=0; n<7; n++)//写入7个字节的时钟信号：分秒时日月周年
	{
		DS1302_Write(WRITE_RTC_ADDR[n],TIME[n]);	
	}
	DS1302_Write(0x8E,0x80);		 //打开写保护功能
}

/**
 * @Name: DS1302_ReadTime
 * @Author:	Zale
 * LastEditor: Zale
 * @Brief:  DS1302读取时间
 * @Param:  
 * @Example:  
 * @Retval:  
 */
void DS1302_ReadTime()
{
	uchar n;
	for (n=0; n<7; n++)//读取7个字节的时钟信号：分秒时日月周年
	{
		TIME[n] = DS1302_Read(READ_RTC_ADDR[n]);
	}
}