/*
 * @Author: Frumig
 * @Date: 2020-02-02 22:45:42
 * @LastEditTime: 2020-03-10 21:42:23
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
  SystemInit();
  BEE_Config(); 
  Key_Test_Init();
  BEE_ON;
  delay_ms(1000);
  BEE_OFF;
  while(1)
  {
    if(KEY_IN)
      BEE_OFF;
    else
      BEE_ON;
  }
  return 0;
}