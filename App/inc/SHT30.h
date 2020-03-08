/*
 * @Author: Zale
 * @Date: 2020-02-02 20:54:39
 * @LastEditTime: 2020-03-04 21:09:43
 * @LastEditors: Please set LastEditors
 * @Description  : SHT30模块驱动
 * @FilePath: \Nixie\App\inc\SHT30.h
 */
#ifndef SHT30_H
#define SHT30_H
#include <public.h>

#define SHT30_SDA GPIO_ReadInputData(GPIOB,GPIO_Pin_11)
#define SHT30_SCL GPIO_ReadInputData(GPIOB,GPIO_Pin_10)
#define SHT30_I2C_ADDR 0x44
#define SHT30_CMD 0xE000

#define I2C_WR	0		/* 写控制bit */
#define I2C_RD	1		/* 读控制bit */




void SHT30_Init();
uint8_t SHT30_Write(char* pBuffer,uint8_t Length);
uint8_t SHT30_Read(char* pBuffer, uint8_t Length);
#endif