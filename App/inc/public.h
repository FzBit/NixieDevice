/*
 * @Author: Frumig
 * @Date: 2020-02-07 13:41:25
 * @LastEditTime: 2020-03-09 22:17:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NixieDevice-master\App\inc\public.h
 */

#ifndef PUBLIC_H
#define PUBLIC_H

#include <stm32f10x_conf.h>
#include <tick.h>
#include <74HC595.h>
#include <Sth30.h>

#define BEE_ON GPIO_ResetBits(GPIOA, GPIO_Pin_15)
#define BEE_OFF GPIO_SetBits(GPIOA, GPIO_Pin_15)

void GPIO_Config();

#endif