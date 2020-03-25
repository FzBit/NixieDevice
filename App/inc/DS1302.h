#ifndef __DS1302_H_
#define __DS1302_H_

//---包含头文件---//
#include <public.h>
//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

#define DSCLK_L GPIO_ResetBits(GPIOB,GPIO_Pin_6)
#define DSCLK_H GPIO_SetBits(GPIOB,GPIO_Pin_6)

#define DSIO_L GPIO_ResetBits(GPIOB,GPIO_Pin_7)
#define DSIO_H GPIO_SetBits(GPIOB,GPIO_Pin_7)
#define DSIO_R GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)

#define DSRST_L GPIO_ResetBits(GPIOB,GPIO_Pin_8)
#define DSRST_H GPIO_SetBits(GPIOB,GPIO_Pin_8)

/*
sbit DSIO=P3^4;
sbit RST=P3^5;
sbit SCLK=P3^6;
*/
//---定义全局函数---//
void DS1302_Write(uchar addr, uchar dat);
uchar DS1302_Read(uchar addr);
void DS1302_Init();
void DS1302_ReadTime();

//---加入全局变量--//
extern uchar TIME[7];	//加入全局变量

#endif