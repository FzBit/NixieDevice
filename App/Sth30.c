#include <Sth30.h>

void Sth30_Init()
{
    I2C_InitTypeDef* Sth30_init_struct;
    Sth30_init_struct->I2C_Mode=I2C_Mode_I2C;
    
    I2C_Init(I2C2,Sth30_init_struct);
}