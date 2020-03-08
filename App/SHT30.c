/*
 * @Author: Zale
 * @Date: 2020-02-02 20:54:31
 * @LastEditTime: 2020-03-08 11:17:43
 * @LastEditors: Please set LastEditors
 * @Description  : SHT30模块驱动
 * @FilePath: \Nixie\App\SHT30.c
 */

#include <SHT30.h>


/**
 * @author: Zale 
 * @brief: SHT30驱动初始化
 * @param : 无
 * @retval:  无
 */
void SHT30_Init()
{
    I2C_InitTypeDef* SHT30_I2C_Init;

    

    GPIO_InitTypeDef  SHT30_GPIO_Init;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);   
    //引脚配置
    /*
    SHT30_GPIO_Init.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    SHT30_GPIO_Init.GPIO_Mode = GPIO_Mode_AF_OD;
    SHT30_GPIO_Init.GPIO_Speed = GPIO_Speed_50MHz;
    

    GPIO_Init(GPIOB, &SHT30_GPIO_Init);
    // GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,); 
    // GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_I2C2);
    */
    //I2C模块配置
    SHT30_I2C_Init->I2C_Mode=I2C_Mode_I2C;
    SHT30_I2C_Init->I2C_DutyCycle = I2C_DutyCycle_2;
    //SHT30_I2C_Init.I2C_OwnAddress1 = 0XA0;//主机的地址        
    SHT30_I2C_Init->I2C_Ack = I2C_Ack_Enable;
    SHT30_I2C_Init->I2C_AcknowledgedAddress= I2C_AcknowledgedAddress_7bit;
    SHT30_I2C_Init->I2C_ClockSpeed = 100000;//100KHZ

    I2C_Init(I2C2,SHT30_I2C_Init);
}

/**
 * @author: Zale
 * @brief : SHT30模块写入数据
 * @param : pBuffer 待写入数组指针
 * @param : Length 待写入数组长度
 * @retval: 0成功，其他为在不同阶段的超时失败 //大概只会在debug阶段用，确保能用就ok了
 * 
 */
uint8_t SHT30_Write(char* pBuffer,uint8_t Length)
{
    uint8_t i=0;
    while(I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY))
    {
        i++;
        if(i>1000)
        return 1;
    };i=0;

    I2C_GenerateSTART(I2C2,ENABLE);     //I2C Start
    while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
    {
        i++;
        if(i>1000)
        return 2;
    };i=0;
    
    I2C_Send7bitAddress(I2C2, SHT30_I2C_ADDR, I2C_Direction_Transmitter);       //I2C写从机地址
    while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
    {
        i++;
        if(i>1000)
        return 3;
    };i=0;
    
    while(Length--)     //写入pBuffer数据
    {
        I2C_SendData(I2C2, *pBuffer);
        while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        {
            i++;
            if(i>1000)
            return 4;
        };i=0;
        pBuffer++;
    }
    I2C_GenerateSTOP(I2C2, ENABLE);
    while ((I2C2->CR1&0x200) == 0x200)
    {
            i++;
            if(i>1000)
            return 4;
    };i=0;

    return 0;

}

/**
 * @author: Zale
 * @brief : 读取SHT30模块数据
 * @param : Length 读取的数据长度 
 * @param : pBuffer 读取数据存储到的数组
 * @retval : 0为成功，其他为不同阶段的超时失败 //大概只会在debug阶段用，确保能用就ok了
 */
uint8_t SHT30_Read(char* pBuffer, uint8_t Length)
{
    uint8_t i;
    while(I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY))
    {
        i++;
        if(i>1000)
        return 0;
    };i=0;
    I2C_AcknowledgeConfig(I2C2, ENABLE);
    /* 1.开始*/
    I2C_GenerateSTART(I2C2, ENABLE);
    while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
    {
        i++;
        if(i>1000)
        return 1;
    };i=0;
    /* 2.设备地址·/写 */
    I2C_Send7bitAddress(I2C2, SHT30_I2C_ADDR, I2C_Direction_Transmitter);
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
    {
        i++;
        if(i>1000)
        return 2;
    };i=0;

    /* 3.开始*/
    I2C_GenerateSTART(I2C2, ENABLE);
    while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
    {
        i++;
        if(i>1000)
        return 3;
    };i=0;
    /* 4.设备地址·/读 */
    I2C_Send7bitAddress(I2C2, SHT30_I2C_ADDR, I2C_Direction_Receiver);
    while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
    {
        i++;
        if(i>1000)
        return 4;
    };i=0;

    /* 5.连续写数据 */
    while (Length)
    {
        if(Length==1)
        {
            I2C_AcknowledgeConfig(I2C2, DISABLE);
            I2C_GenerateSTOP(I2C2, ENABLE);//6.停止，非应答
        }

        while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED))
        {
            i++;
            if(i>1000)
            return 5;
        };i=0;
        *pBuffer++ = I2C_ReceiveData(I2C2);
        Length--;
    }

    I2C_AcknowledgeConfig(I2C2, ENABLE);
    return 0;

}