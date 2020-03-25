/*
 * @Author: Zale
 * @Date: 2020-02-07 15:33:20
 * @LastEditTime : 2020-02-07 15:34:00
 * @LastEditors  : Please set LastEditors
 * @Description: 模拟I2C驱动模块
 * @FilePath: \Nixie\App\I2C_Sim.c
 */
#include <I2C_Sim.h>

/**
 * @Author:  Zale
 * @Brief:   模拟I2C起始信号
 * @Param:   None
 * @Example: I2C_Sim_Start()
 * @Retval:  None
 */
void I2C_Sim_Start()
{
    SCL_H;
    SDA_H;
    delay_us(5);
    SDA_L;
    delay_us(6);
    SCL_L;
}

/**
 * @Author:  Zale
 * @Brief:  模拟I2C中止信号
 * @Param:  None
 * @Example:  I2C_Sim_stop()
 * @Retval:  None
 */
void I2C_Sim_Stop()
{
    SCL_L;
    delay_us(4);
    SDA_H;
    delay_us(5);

}

