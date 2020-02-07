/*
 * @Author: Frumig
 * @Date: 2020-02-06 19:36:14
 * @LastEditTime : 2020-02-06 20:31:57
 * @LastEditors  : Frumig
 * @reference：https://zhuanlan.zhihu.com/p/34289673
 * @FilePath: \NixieDevice-master\App\inc\tick.h
 */
#ifndef TICK_H
#define TICK_H

#include <public.h>

#define FAC_US 9        //延时基数
#define FAC_MS 9000
#define CLEAR_SYSTICK  0x00;
#define ENABLE_SYSTICK 0x01;


void delay_us(u32 n_us);
void delay_ms(u32 n_ms);

#endif