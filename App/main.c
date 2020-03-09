/*
 * @Author: Frumig
 * @Date: 2020-02-02 22:45:42
 * @LastEditTime: 2020-03-09 22:20:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NixieDevice-master\App\main.c
 */
#include "public.h"    



int main()
{
  SystemInit();
  GPIO_Config();

  BEE_ON;
  
  while(1);
  return 0;
}