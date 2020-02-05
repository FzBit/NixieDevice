/*
 * @Author: your name
 * @Date: 2020-02-02 20:54:39
 * @LastEditTime: 2020-02-05 22:40:05
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \Nixie\App\inc\Sth30.h
 */
#ifndef STH30_H
#define STH30_H
#include <stm32f10x_conf.h>

#define STH30_SDA GPIO_ReadInputData(GPIOB,GPIO_Pin_11)
#define STH30_SCL GPIO_ReadInputData(GPIOB,GPIO_Pin_10)
#define STH30_I2C_ADDR 0x00




void Sth30_Init();

#endif