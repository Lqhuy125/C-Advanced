#include <stdio.h>
#include "main.h"

//Vi du su dung stm32 
#define MCU STM32F103       

int main(int argc, char const *argv[])
{
    while(1){
        BlinkLed();
    }
    return 0;
}
