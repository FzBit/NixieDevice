/*
 * @Author: Frumig
 * @Date: 2020-02-03 12:52:23
 * @LastEditTime : 2020-02-06 19:25:12
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NixieDevice-master\App\inc\74HC595.h
 */
#ifndef HC595_H
#define HC595_H

#include <public.h>

/***************重定义74HC595_0的引脚***************/
#define GPIO_PORT_SHCP_0    GPIOA
#define GPIO_CLK_SHCP_0     RCC_APB2Periph_GPIOA
#define GPIO_PIN_SHCP_0     GPIO_Pin_0

#define GPIO_PORT_STCP_0    GPIOA
#define GPIO_CLK_STCP_0     RCC_APB2Periph_GPIOA
#define GPIO_PIN_STCP_0     GPIO_Pin_0

#define GPIO_PORT_DS_0    GPIOA
#define GPIO_CLK_DS_0     RCC_APB2Periph_GPIOA
#define GPIO_PIN_DS_0     GPIO_Pin_0

/***************重定义74HC595_1的引脚***************/
#define GPIO_PORT_SHCP_1    GPIOA
#define GPIO_CLK_SHCP_1     RCC_APB2Periph_GPIOA
#define GPIO_PIN_SHCP_1     GPIO_Pin_0

#define GPIO_PORT_STCP_1    GPIOA
#define GPIO_CLK_STCP_1     RCC_APB2Periph_GPIOA
#define GPIO_PIN_STCP_1     GPIO_Pin_0

#define GPIO_PORT_DS_1    GPIOA
#define GPIO_CLK_DS_1     RCC_APB2Periph_GPIOA
#define GPIO_PIN_DS_1     GPIO_Pin_0

/***************重定义74HC595_2的引脚***************/
#define GPIO_PORT_SHCP_2    GPIOA
#define GPIO_CLK_SHCP_2     RCC_APB2Periph_GPIOA
#define GPIO_PIN_SHCP_2     GPIO_Pin_0

#define GPIO_PORT_STCP_2    GPIOA
#define GPIO_CLK_STCP_2     RCC_APB2Periph_GPIOA
#define GPIO_PIN_STCP_2     GPIO_Pin_0

#define GPIO_PORT_DS_2    GPIOA
#define GPIO_CLK_DS_2     RCC_APB2Periph_GPIOA
#define GPIO_PIN_DS_2     GPIO_Pin_0

/***************重定义74HC595_3的引脚***************/
#define GPIO_PORT_SHCP_3    GPIOA
#define GPIO_CLK_SHCP_3     RCC_APB2Periph_GPIOA
#define GPIO_PIN_SHCP_3     GPIO_Pin_0

#define GPIO_PORT_STCP_3    GPIOA
#define GPIO_CLK_STCP_3     RCC_APB2Periph_GPIOA
#define GPIO_PIN_STCP_3     GPIO_Pin_0

#define GPIO_PORT_DS_3    GPIOA
#define GPIO_CLK_DS_3     RCC_APB2Periph_GPIOA
#define GPIO_PIN_DS_3     GPIO_Pin_0


typedef enum HC595_n
{
  HC595_0 = 0,
  HC595_1 = 1,
  HC595_2 = 2,
  HC595_3 = 3
}HC595_n;

typedef enum Status_Pin
{
  High = 0,
  Low = 1
}Status_Pin;

void GPIO_Config_HC595(void);
void HC595_Send_Multi_Byte(u8 *data, u8 len, HC595_n addr);

#endif