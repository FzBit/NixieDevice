/*
 * @Author: Frumig
 * @Date: 2020-03-09 22:10:29
 * @LastEditTime: 2020-03-09 22:21:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NixieDevice-master\App\public.c
 */
#include "public.h"

void GPIO_Config()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);               //使能相应的端口时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);         //使能复用时钟
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);     //SWJ端口重映射     Ref：https://blog.csdn.net/qhw5279/article/details/72630637

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    //设置输出状态为推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   //设置引脚频率

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;          //设置引脚
    GPIO_Init(GPIOA, &GPIO_InitStructure);              //初始化引脚

    GPIO_SetBits(GPIOA, GPIO_Pin_15);                   //默认高电平（PA_15与蜂鸣器连接，高电平关闭蜂鸣器）


    GPIO_Config_HC595();        //配置74HC595的引脚
}