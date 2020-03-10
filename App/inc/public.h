/*
 * @Author: Frumig
 * @Date: 2020-02-07 13:41:25
 * @LastEditTime: 2020-03-10 21:04:54
 * @LastEditors: Please set LastEditors
 * @Description: 包含所有的共用文件以供调用，并且包含了一些较简单的模块函数如BEE
 * @FilePath: \NixieDevice-master\App\inc\public.h
 */

#ifndef PUBLIC_H
#define PUBLIC_H

#define KEY_IN GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)

#include <stm32f10x_conf.h>
#include <tick.h>
#include <74HC595.h>
#include <SHT30.h>

#define BEE_ON GPIO_ResetBits(GPIOA, GPIO_Pin_15)
#define BEE_OFF GPIO_SetBits(GPIOA, GPIO_Pin_15)

void BEE_Config();
void Key_Test_Init();

#endif