/*
 * @Author: Frumig
 * @Date: 2020-02-02 22:45:42
<<<<<<< HEAD
 * @LastEditTime: 2020-03-08 09:11:08
=======
 * @LastEditTime: 2020-03-09 22:20:08
>>>>>>> 9cfbe10c618fd1f46aa0509d0de6a7b3b1f26c0f
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NixieDevice-master\App\main.c
 */
#include "public.h"    

  char d[8]={0,0,0,0,0,0,0};
  int k=9;
  int f=0;

int main()
{
<<<<<<< HEAD
  // SystemInit();
  // GPIO_Config_HC595();

  GPIO_InitTypeDef KeyS1;
  RCC_APB1PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  KeyS1.GPIO_Mode=GPIO_Mode_Out_PP;
  KeyS1.GPIO_Pin=GPIO_Pin_15;
  KeyS1.GPIO_Speed=GPIO_Speed_50MHz;

  GPIO_ResetBits(GPIOA,GPIO_Pin_15);
  
#if 0
  while(++k)
  {
    if(k%2==0)
    {
      GPIO_ResetBits(GPIOA,GPIO_Pin_15);
      delay_ms(500);
      f=2;
    }
    else
    {
      GPIO_SetBits(GPIOA,GPIO_Pin_15);
      delay_ms(500);
      f=3;
    }
  }
#endif
=======
  SystemInit();
  GPIO_Config();

  BEE_ON;
>>>>>>> 9cfbe10c618fd1f46aa0509d0de6a7b3b1f26c0f
  
  while(1);
  return 0;
}