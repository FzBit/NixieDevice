/*
 * @Author: Frumig
 * @Date: 2020-02-03 12:52:38
 * @LastEditTime: 2020-03-13 15:13:03
 * @LastEditors: Please set LastEditors
 * @Description: 74HC595锁存器驱动 （待测试）
 * @reference:https://blog.csdn.net/k1ang/article/details/80397173
 * @FilePath: \NixieDevice-master\App\74HC595.c
 */
#include <74HC595.h>



/**
 * @Author: Frumig；  
 * @brief: 配置74HC595的引脚为推挽输出； 
 * @param None；
 * @retval: None；
 */
void GPIO_Config_HC595()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(GPIO_CLK_DS_0 | GPIO_CLK_DS_1 | GPIO_CLK_DS_2 | GPIO_CLK_DS_3 |
                            GPIO_CLK_SHCP_0 | GPIO_CLK_SHCP_1 | GPIO_CLK_SHCP_2 | GPIO_CLK_SHCP_3 |
                            GPIO_CLK_STCP_0 | GPIO_CLK_STCP_1 | GPIO_CLK_STCP_2 | GPIO_CLK_STCP_3, ENABLE); //使能相应的端口时钟

  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    //设置输出状态为推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   //设置引脚频率

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_DS_0;        //设置引脚
    GPIO_Init(GPIO_PORT_DS_0, &GPIO_InitStructure);     //初始化引脚

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_DS_1;
    GPIO_Init(GPIO_PORT_DS_1, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_DS_2;
    GPIO_Init(GPIO_PORT_DS_2, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_DS_3;
    GPIO_Init(GPIO_PORT_DS_3, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_SHCP_0;
    GPIO_Init(GPIO_PORT_SHCP_0, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_SHCP_1;
    GPIO_Init(GPIO_PORT_SHCP_1, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_SHCP_2;
    GPIO_Init(GPIO_PORT_SHCP_2, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_SHCP_3;
    GPIO_Init(GPIO_PORT_SHCP_3, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_STCP_0;
    GPIO_Init(GPIO_PORT_STCP_0, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_STCP_1;
    GPIO_Init(GPIO_PORT_STCP_1, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_STCP_2;
    GPIO_Init(GPIO_PORT_STCP_2, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_STCP_3;
    GPIO_Init(GPIO_PORT_STCP_3, &GPIO_InitStructure);



    //将上述配置好的引脚全部拉低
    GPIO_ResetBits(GPIO_PORT_SHCP_0, GPIO_PIN_SHCP_0);
    GPIO_ResetBits(GPIO_PORT_SHCP_1, GPIO_PIN_SHCP_1);
    GPIO_ResetBits(GPIO_PORT_SHCP_2, GPIO_PIN_SHCP_2);
    GPIO_ResetBits(GPIO_PORT_SHCP_3, GPIO_PIN_SHCP_3);
    GPIO_ResetBits(GPIO_PORT_DS_0, GPIO_PIN_DS_0);
    GPIO_ResetBits(GPIO_PORT_DS_1, GPIO_PIN_DS_1);
    GPIO_ResetBits(GPIO_PORT_DS_2, GPIO_PIN_DS_2);
    GPIO_ResetBits(GPIO_PORT_DS_3, GPIO_PIN_DS_3);
    GPIO_ResetBits(GPIO_PORT_STCP_0, GPIO_PIN_STCP_0);
    GPIO_ResetBits(GPIO_PORT_STCP_1, GPIO_PIN_STCP_1);
    GPIO_ResetBits(GPIO_PORT_STCP_2, GPIO_PIN_STCP_2);
    GPIO_ResetBits(GPIO_PORT_STCP_3, GPIO_PIN_STCP_3);
    
}

/**
 * @Author:  Frumig；
 * @brief:  控制74H595的SHCP引脚；
 * @param status: 设置引脚的状态；输入High or Low；
 * @param addr： 选择外围设备； 可输入HC595_0, HC595_1, HC595_2, HC595_3；   
 * @retval: None；
 */
void HC595_Shcp(Status_Pin status, HC595_n addr)
{
    if(status)  //选择输出状态
    {
        switch(addr)    //选择外围设备
        {
            case HC595_0:   GPIO_SetBits(GPIO_PORT_SHCP_0, GPIO_PIN_SHCP_0);    break;
            case HC595_1:   GPIO_SetBits(GPIO_PORT_SHCP_1, GPIO_PIN_SHCP_1);    break;
            case HC595_2:   GPIO_SetBits(GPIO_PORT_SHCP_2, GPIO_PIN_SHCP_2);    break;
            case HC595_3:   GPIO_SetBits(GPIO_PORT_SHCP_3, GPIO_PIN_SHCP_3);    break;
            default: break;
        }
    }
    else
    {
        switch(addr)
        {
            case HC595_0:   GPIO_ResetBits(GPIO_PORT_SHCP_0, GPIO_PIN_SHCP_0);    break;
            case HC595_1:   GPIO_ResetBits(GPIO_PORT_SHCP_1, GPIO_PIN_SHCP_1);    break;
            case HC595_2:   GPIO_ResetBits(GPIO_PORT_SHCP_2, GPIO_PIN_SHCP_2);    break;
            case HC595_3:   GPIO_ResetBits(GPIO_PORT_SHCP_3, GPIO_PIN_SHCP_3);    break;
            default: break;
        }
    }
    
}

/**
 * @Author:  Frumig；
 * @brief:  控制74H595的STCP引脚；
 * @param status: 设置引脚的状态；输入High or Low；
 * @param addr： 选择外围设备； 可输入HC595_0, HC595_1, HC595_2, HC595_3；   
 * @retval: None；
 */
void HC595_Stcp(Status_Pin status, HC595_n addr)
{
    if(status)
    {
        switch(addr)
        {
            case HC595_0:   GPIO_SetBits(GPIO_PORT_STCP_0, GPIO_PIN_STCP_0);    break;
            case HC595_1:   GPIO_SetBits(GPIO_PORT_STCP_1, GPIO_PIN_STCP_1);    break;
            case HC595_2:   GPIO_SetBits(GPIO_PORT_STCP_2, GPIO_PIN_STCP_2);    break;
            case HC595_3:   GPIO_SetBits(GPIO_PORT_STCP_3, GPIO_PIN_STCP_3);    break;
            default: break;
        }
    }
    else
    {
        switch(addr)
        {
            case HC595_0:   GPIO_ResetBits(GPIO_PORT_STCP_0, GPIO_PIN_STCP_0);    break;
            case HC595_1:   GPIO_ResetBits(GPIO_PORT_STCP_1, GPIO_PIN_STCP_1);    break;
            case HC595_2:   GPIO_ResetBits(GPIO_PORT_STCP_2, GPIO_PIN_STCP_2);    break;
            case HC595_3:   GPIO_ResetBits(GPIO_PORT_STCP_3, GPIO_PIN_STCP_3);    break;
            default: break;
        }
    }
}

/**
 * @Author:  Frumig；
 * @brief:  控制74H595的Data引脚；
 * @param status: 设置引脚的状态；输入High or Low；
 * @param addr: 选择外围设备； 可输入HC595_0, HC595_1, HC595_2, HC595_3； 
 * @retval: None；
 */
void HC595_Data(Status_Pin status, HC595_n addr)
{
    if(status)
    {
        switch(addr)
        {
            case HC595_0:   GPIO_SetBits(GPIO_PORT_DS_0, GPIO_PIN_DS_0);    break;
            case HC595_1:   GPIO_SetBits(GPIO_PORT_DS_1, GPIO_PIN_DS_1);    break;
            case HC595_2:   GPIO_SetBits(GPIO_PORT_DS_2, GPIO_PIN_DS_2);    break;
            case HC595_3:   GPIO_SetBits(GPIO_PORT_DS_3, GPIO_PIN_DS_3);    break;
            default: break;
        }
    }
    else
    {
        switch(addr)
        {
            case HC595_0:   GPIO_ResetBits(GPIO_PORT_DS_0, GPIO_PIN_DS_0);    break;
            case HC595_1:   GPIO_ResetBits(GPIO_PORT_DS_1, GPIO_PIN_DS_1);    break;
            case HC595_2:   GPIO_ResetBits(GPIO_PORT_DS_2, GPIO_PIN_DS_2);    break;
            case HC595_3:   GPIO_ResetBits(GPIO_PORT_DS_3, GPIO_PIN_DS_3);    break;
            default: break;
        }
    }
}

/**
 * @Author: Frumig；
 * @brief: 通过控制74HC595的STCP引脚产生一个高电平的脉冲使移位寄存器中的数据送入储存寄存器中；
 * @param addr: 选择外围设备； 可输入HC595_0, HC595_1, HC595_2, HC595_3；
 * @retval: None；
 */
void HC595_CS(HC595_n addr)
{
    HC595_Stcp(Low, addr);
    delay_us(2);
    HC595_Stcp(High, addr);
    delay_us(2);
}

/**
 * @Author: Frumig；
 * @brief: 将一个字节的数据送入74HC595中；
 * @param byte: 要送入的数据；
 * @param addr：选择外围设备； 可输入HC595_0, HC595_1, HC595_2, HC595_3；
 * @retval: None；
 */
void HC595_Send_Byte(u8 byte, HC595_n addr)
{

    for(u8 i = 0; i < 8; i++)
    {
        //将byte的最高位的状态赋予Data引脚
        if(byte & 0x80)
            HC595_Data(High, addr);
        else
            HC595_Data(Low, addr);

        //通过一个是，高电平的脉冲使Data引脚的数据送入移位寄存器中
        HC595_Shcp(Low, addr);
        delay_us(2);
        HC595_Shcp(High,addr);
        delay_us(2);

        byte <<= 1; //左移一位；使数据依次输入到移位寄存器中
    }
}
/**
 * @Author: Frumig；  
 * @brief:  送入len个数据到74H595中；用于74HC595的级联；
 * @param data：要送入的数据的地址；
 * @param len：输入的字节个数；那个设备级联则需要n个字节的数据；
 * @retval: None；
 */
void HC595_Send_Multi_Byte(u8 *data, u8 len, HC595_n addr)
{
    for(u8 i = 0; i < len; i++){
        HC595_Send_Byte(data[i], addr);//
    }
    

    HC595_CS(addr);
    //因为74HC595的OE引脚(使能引脚)在硬件上已接地，所以当把移位寄存器中的数据送入储存寄存器中是，锁存器的并行输出口就会立即改变状态
    //如果OE引脚连接了MCU的引脚，则需要软件上的使能
}