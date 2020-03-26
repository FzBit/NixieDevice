/*
 * @Author: Frumig
 * @Date: 2020-02-02 22:45:42
 * @LastEditTime: 2020-03-26 17:14:12
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
  DS1302_GPIO_Config();
  DS1302_Init();
  
  while(1){

    DS1302_ReadTime();
  }
    
  return 0;
}