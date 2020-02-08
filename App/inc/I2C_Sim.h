/*
 * @Author: Zale
 * @Date: 2020-02-07 15:25:56
 * @LastEditTime : 2020-02-08 12:55:24
 * @LastEditors  : Please set LastEditors
 * @Description: 模拟I2C驱动
 * @FilePath: \Nixie\App\inc\I2C_Sim.h
 */
#ifndef I2C_SIM_H
#define I2C_SIM_H
#include <public.h>

#define SDA_H GPIO_SetBits(GPIOA,GPIO_Pin_6)
#define SDA_L GPIO_ResetBits(GPIOA,GPIO_Pin_6)
#define SCL_H GPIO_SetBits(GPIOA,GPIO_Pin_7)
#define SCL_L GPIO_ResetBits(GPIOA,GPIO_Pin_7)
#define I2C_Delay delay_us(6)

void I2C_Sim_Start();
void I2C_Sim_Stop();
void I2C_Sim_ACK();
uint8_t I2C_Sim_WaitAck();
void I2C_Sim_SendByte(uint8_t Data);
uint8_t I2C_Sim_ReadByte();




#endif