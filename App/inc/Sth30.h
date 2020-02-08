/*
 * @Author: Zale
 * @Date: 2020-02-02 20:54:39
 * @LastEditTime : 2020-02-07 14:30:51
 * @LastEditors  : Please set LastEditors
 * @Description  : Sth30模块驱动
 * @FilePath: \Nixie\App\inc\Sth30.h
 */
#ifndef STH30_H
#define STH30_H
#include <public.h>

#define STH30_SDA GPIO_ReadInputData(GPIOB,GPIO_Pin_11)
#define STH30_SCL GPIO_ReadInputData(GPIOB,GPIO_Pin_10)
#define STH30_I2C_ADDR 0x00




void Sth30_Init();
uint8_t Sth30_Write(char* pBuffer,uint8_t Length);
uint8_t Sth30_Read(char* pBuffer, uint8_t Length);
#endif