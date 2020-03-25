/*
 * @Author: Zale
 * @Date: 2020-02-07 15:25:56
 * @LastEditTime : 2020-02-08 13:08:49
 * @LastEditors  : Please set LastEditors
 * @Description: 模拟I2C驱动
 * @FilePath: \Nixie\App\inc\I2C_Sim.h
 */
#ifndef I2C_SIM_H
#define I2C_SIM_H
#include <public.h>

#define SDA_H_0 GPIO_SetBits(GPIOA,GPIO_Pin_3)
#define SDA_L_0 GPIO_ResetBits(GPIOA,GPIO_Pin_3)
#define SCL_H_0 GPIO_SetBits(GPIOA,GPIO_Pin_4)
#define SCL_L_0 GPIO_ResetBits(GPIOA,GPIO_Pin_4)

#define SDA_H_1 GPIO_SetBits(GPIOA,GPIO_Pin_6)
#define SDA_L_1 GPIO_ResetBits(GPIOA,GPIO_Pin_6)
#define SCL_H_1 GPIO_SetBits(GPIOA,GPIO_Pin_7)
#define SCL_L_1 GPIO_ResetBits(GPIOA,GPIO_Pin_7)



#define I2C_Delay delay_us(6)

typedef enum I2C_Sim_x
{
    I2C_Sim_0 = 0,      //模拟I2C0，SDA-A3 SCL-A4
    I2C_Sim_1 = 1,      //模拟I2C1，SDA-A6 SCL-A7
};


void I2C_Sim_Start();
void I2C_Sim_Stop();
void I2C_Sim_ACK();
uint8_t I2C_Sim_WaitAck();
void I2C_Sim_SendByte(uint8_t Data);
uint8_t I2C_Sim_ReadByte();




#endif