#define STM32F103       0
#define ATMEGA          1
#define PIC16F877A      2


#if MCU == STM32F103
    void BlinkLed(){
        ODR = ^ODR;
        delay(1000);
    }
#elif MCU == STM32F103
    void BlinkLed(){
        ALU = ^ALU;
        delay(1000);
    }
#elif MCU == PIC16F877A   
    void BlinkLed(){
        PORT = ^PORT;
        delay(1000);
    }
#endif