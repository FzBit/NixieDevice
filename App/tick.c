/*
 * @Author: Frumig
 * @Date: 2020-02-06 19:33:48
<<<<<<< HEAD
 * @LastEditTime: 2020-03-04 20:45:35
=======
 * @LastEditTime : 2020-02-06 20:36:21
>>>>>>> 9cfbe10c618fd1f46aa0509d0de6a7b3b1f26c0f
 * @LastEditors: Please set LastEditors
 * @Description: 配置了使用SysTick的2个延时函数(待测试)
 * @reference：https://zhuanlan.zhihu.com/p/34289673
 * @FilePath: \NixieDevice-master\App\tick.c
 */
#include <tick.h>

/**
 * @Author:Frumig  
 * @brief: 使用CM3内核中的SysTick定时器实现微秒的延时
 * @param n_us: 需要延时的时间，单位us；
 * @Example： dealy_us(10);   //延时10us
 * @retval: None
 */
void delay_us(u32 n_us)
{
    u32 temp;
    SysTick->LOAD = n_us * FAC_US;                  //装载
    SysTick->VAL = 0x00;                            //清空计数器
    SysTick->CTRL = ENABLE_SYSTICK;                 //开始计时

    do
    {
        temp = SysTick->CTRL;
    } while ((temp&0x01) && !(temp & (1<<16)));     //等待时间到达
    
    SysTick->CTRL = ~ENABLE_SYSTICK;                //关闭计时器
    SysTick->VAL = 0x00;                            //清空定时器
}

/**
 * @Author:Frumig  
 * @brief: 使用CM3内核中的SysTick定时器实现毫秒的延时
 * @param n_ms: 需要延时的时间，单位ms；
 * @Example： dealy_ms(10);   //延时10ms
 * @retval: None
 */
<<<<<<< HEAD
void delay_ms(u32 m_us)
=======
void delay_ms(u32 n_ms)
>>>>>>> 9cfbe10c618fd1f46aa0509d0de6a7b3b1f26c0f
{
    u32 temp;
    SysTick->LOAD = n_ms * FAC_MS;                  //装载
    SysTick->VAL = CLEAR_SYSTICK;                   //清空计数器
    SysTick->CTRL = ENABLE_SYSTICK;                 //开始计时

    do
    {
        temp = SysTick->CTRL;
    } while ((temp&0x01) && !(temp & (1<<16)));     //等待时间到达
    
    SysTick->CTRL = ~ENABLE_SYSTICK;                //关闭计时器
    SysTick->VAL = 0x00;                            //清空定时器
}
