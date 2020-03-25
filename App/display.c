/*
 * @Author: your name
 * @Date: 2020-03-23 20:22:03
 * @LastEditTime: 2020-03-25 22:39:02
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \Nixie\App\display.c
 */
/*
 * @Author: Frumig
 * @Date: 2020-02-11 21:10:40
 * @LastEditTime: 2020-03-17 22:23:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NixieDevice-master\App\display.c
 */
#include <display.h>

//用来储存驱动辉光管的锁存器编码信息，从0到10依次代表辉光管从一点钟方向顺时针的引脚
//每个数的11，12位用来储存对应的锁存器组号。即级联在一起的锁存器为同一组
//9，10位用来储存该组的锁存器的位号，即该组锁存器中的哪一个锁存器。
//1-8位用来储存应该写入该锁存器的数
//                        一点钟   二点钟   三点钟  四点钟   五点钟   六点钟  七点钟  八点钟   九点钟  十点钟  十一点钟  方向引脚
u16 decode_Nixie_0[11] = {0xf17f, 0xf1fd, 0xf1fb, 0xf0f7, 0xf0ef, 0xf0df, 0xf0bf, 0xf07f, 0xf0fb, 0xf0fd, 0xf0fe};
u16 decode_Nixie_1[11] = {0xf27f, 0xf2bf, 0xf4f7, 0xf4ef, 0xf4df, 0xf4fe, 0xf1f7, 0xf1ef, 0xf1df, 0xf1bf, 0xf1fe};
u16 decode_Nixie_2[11] = {0xf2f7, 0xf2fd, 0xf5ef, 0xf5df, 0xf5fe, 0xf47f, 0xf4bf, 0xf4fd, 0xf4fb, 0xf2df, 0xf2ef};
u16 decode_Nixie_3[11] = {0xf2fe, 0xf6df, 0xf6bf, 0xf67f, 0xf6fe, 0xf57f, 0xf5bf, 0xf5fd, 0xf5fb, 0xf5f7, 0xf2fb};
u16 decode_Nixie_4[11] = {0xfafb, 0xfafd, 0xfaef, 0xfadf, 0xfefb, 0xfefe, 0xf6fb, 0xf6fd, 0xf6f7, 0xf6ef, 0xfaf7};
u16 decode_Nixie_5[11] = {0xfddf, 0xfdfe, 0xfe7f, 0xfebf, 0xfedf, 0xfeef, 0xfef7, 0xfefd, 0xfabf, 0xfa7f, 0xfafe};
u16 decode_Nixie_6[11] = {0xf9fb, 0xf9fd, 0xf9f7, 0xf9ef, 0xf9df, 0xfd7f, 0xfdbf, 0xfdfd, 0xfdfb, 0xfdf7, 0xfdef};
u16 decode_Nixie_7[11] = {0xfc7f, 0xfcbf, 0xfcdf, 0xfcef, 0xfcfd, 0xfcfb, 0xfcf7, 0xfcfe, 0xf9bf, 0xf97f, 0xf9fe};


//用来将信息送入锁存器
u8 data_HC595_0[3] = {0xff, 0xff, 0xff};
u8 data_HC595_1[3] = {0xff, 0xff, 0xff};
u8 data_HC595_2[3] = {0xff, 0xff, 0xff};
u8 data_HC595_3[3] = {0xff, 0xff, 0xff};

/**
 * @Author:Frumig  
 * @brief: 用来打开指定辉光管的的指定引脚
 * @param nixie: 需要操作的辉光管编号Nixie_n(n为0-7)
 * @param number: 选中的辉光管的引脚可输入0-10
 * @Example： Display(Nixie_0, 7);      //打开0号辉光管的第七个引脚(即八点钟方向的引脚)
 * @retval: None
 * @Notic: 该程序只能打开辉光管的引脚，即当你在此使用此函数让辉光管显示另一个数字时，上一次显示的数字并不会熄灭，此使辉光管会显示两个数字；所以期间要搭配Clear函数使用
 */
void Display(Nixie_n nixie, u8 number)
{
    u16 decode;
    u8  n, m;           //m用来储存decode的11，12位即锁存器的组号；n用来储存decode的9，10位即第m组锁存器中的哪一个锁存器
    
    switch (nixie)
    {
        case Nixie_0:   decode = decode_Nixie_0[number];    break;
        case Nixie_1:   decode = decode_Nixie_1[number];    break;
        case Nixie_2:   decode = decode_Nixie_2[number];    break;
        case Nixie_3:   decode = decode_Nixie_3[number];    break;
        case Nixie_4:   decode = decode_Nixie_4[number];    break;
        case Nixie_5:   decode = decode_Nixie_5[number];    break;
        case Nixie_6:   decode = decode_Nixie_6[number];    break;
        case Nixie_7:   decode = decode_Nixie_7[number];    break;
        default:
            break;
    }

    n = (decode & 0x0300) >> 8;
    m = (decode & 0x0c00) >>10;
    switch (m)
    {
        case 0:    data_HC595_0[n] &= decode;   HC595_Send_Multi_Byte(data_HC595_0, 3, HC595_0);  break;
        case 1:    data_HC595_1[n] &= decode;   HC595_Send_Multi_Byte(data_HC595_1, 3, HC595_1);  break;
        case 2:    data_HC595_2[n] &= decode;   HC595_Send_Multi_Byte(data_HC595_2, 3, HC595_2);  break;
        case 3:    data_HC595_3[n] &= decode;   HC595_Send_Multi_Byte(data_HC595_3, 3, HC595_3);  break;
        
        default:
            break;
    }
}
/**
 * @Author:Frumig  
 * @brief: 用来将所有的辉光管中的数字清空
 * @Example： DisplayClear();      //调用此函数后，所有的辉光管都会关闭
 * @retval: None
 */
void DisplayClear()
{
    for (u8 i = 0; i < 3; i++)
    {
        data_HC595_0[i] = 0xff;
        data_HC595_1[i] = 0xff;
        data_HC595_2[i] = 0xff;
        data_HC595_3[i] = 0xff;
    }
    
    HC595_Send_Multi_Byte(data_HC595_0, 3, HC595_0);
    HC595_Send_Multi_Byte(data_HC595_1, 3, HC595_1);
    HC595_Send_Multi_Byte(data_HC595_2, 3, HC595_2);
    HC595_Send_Multi_Byte(data_HC595_3, 3, HC595_3);
}

/**
 * @Author:Frumig  
 * @brief: 用来将指定的辉光管中的数字清空
 * @param nixie: 需要操作的辉光管编号Nixie_n(n为0-7)
 * @Example： DisplayClear(Nixie_7);      //N7数码管被清空
 * @retval: None
 */
void DisplayClearDesignated(Nixie_n nixie)
{
    switch (nixie)
    {
        case Nixie_0:
            data_HC595_0[0] |= 0xff;
            data_HC595_0[1] |= 0x86;
            break;

        case Nixie_1:
            data_HC595_0[1] |= 0x79;
            data_HC595_0[2] |= 0xc0;
            data_HC595_1[0] |= 0x39;
            break;

        case Nixie_2:
            data_HC595_0[2] |= 0x3a;
            data_HC595_1[0] |= 0xc6;
            data_HC595_1[1] |= 0x31;
            break;

        case Nixie_3:
            data_HC595_0[2] |= 0x05;
            data_HC595_1[1] |= 0xce;
            data_HC595_1[2] |= 0xe1;
            break;
        case Nixie_4:
            data_HC595_1[2] |= 0x1e;
            data_HC595_2[2] |= 0x3e;
            data_HC595_3[2] |= 0x05;
            break;
            
        case Nixie_5:
            data_HC595_2[2] |= 0xc1;
            data_HC595_3[2] |= 0xfa;
            data_HC595_3[1] |= 0x21;
            break;

        case Nixie_6:
            data_HC595_2[1] |= 0x3e;
            data_HC595_3[1] |= 0xde;
            break;
        
        case Nixie_7:
            data_HC595_2[1] |= 0xc1;
            data_HC595_3[0] |= 0xff;
            break;
        
        default:
            break;
    }

    HC595_Send_Multi_Byte(data_HC595_0, 3, HC595_0);
    HC595_Send_Multi_Byte(data_HC595_1, 3, HC595_1);
    HC595_Send_Multi_Byte(data_HC595_2, 3, HC595_2);
    HC595_Send_Multi_Byte(data_HC595_3, 3, HC595_3);
}





