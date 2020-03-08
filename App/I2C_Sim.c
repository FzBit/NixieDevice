/*
 * @Author: Zale
 * @Date: 2020-02-07 15:33:20
 * @LastEditTime: 2020-03-08 11:46:33
 * @LastEditors: Please set LastEditors
 * @Description: 模拟I2C驱动模块
 * @FilePath: \Nixie\App\I2C_Sim.c
 */
#include <I2C_Sim.h>


void I2C_Sim_Init(I2C_Sim_x I2C_Sim_Ch)
{
    
    if(!I2C_Sim_ch)
    {

    }
    else
    {
        
    }
    
}

/**
 * @author:  Zale
 * @brief:   模拟I2C起始信号
 * @param:   None
 * @example: I2C_Sim_Start()
 * @retval:  None
 */
void I2C_Sim_Start()
{
    SCL_H_1;
    SDA_H_1;
    delay_us(5);
    SDA_L_1;
    delay_us(6);
    SCL_L_1;
    delay_us(5);
}

/**
 * @author:  Zale
 * @brief:  模拟I2C中止信号
 * @param:  None
 * @example:  I2C_Sim_stop()
 * @retval:  None
 */
void I2C_Sim_Stop();
{
    SCL_L_1;
    SDA_L_1;
    delay_us(4);
    SDA_H_1;
    delay_us(5);
    SCL_H_1;
    delay_us(5);
}


