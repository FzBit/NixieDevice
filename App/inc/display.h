/*
 * @Author: Frumig
 * @Date: 2020-02-11 21:10:23
 * @LastEditTime: 2020-03-17 22:23:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NixieDevice-master\App\inc\display.h
 */
#ifndef DISPLAY_H
#define DISPLAY_H

#include <public.h>

typedef enum Nixie_n
{
  Nixie_0 = 0,
  Nixie_1 = 1,
  Nixie_2 = 3,
  Nixie_3 = 4,
  Nixie_4 = 5,
  Nixie_5 = 6,
  Nixie_6 = 7,
  Nixie_7 = 8,
  Nixie_Led = 9
}Nixie_n;

void Display(Nixie_n nixie, u8 number);
void DisplayClear();
void DisplayClearDesignated(Nixie_n nixie);

#endif