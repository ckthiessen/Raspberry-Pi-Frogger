#include <unistd.h>
#include <stdio.h>
#include "initGPIO.h"

#define CLK 11
#define LAT 9
#define DAT 10
#define INP_GPIO(g) *(gpioPtr +((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpioPtr+((g)/10)) |= (1<<(((g)%10)*3))
#define SET_GPIO_ALT(g,a) *(gpioPtr+(((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))
#define NUM_BUTTONS 16

void initSNES(unsigned int *gpioPtr) {
    INP_GPIO( CLK );        // CLK
    OUT_GPIO( CLK );
    INP_GPIO( LAT );        // LATCH
    OUT_GPIO( LAT );
    INP_GPIO( DAT );        // DATA
}

int main()
{
    // get gpio pointer
    unsigned int *gpioPtr = getGPIOPtr();  
    printf("pointer address: %p\n", gpioPtr);

    initSNES(gpioPtr);

    int buttons[NUM_BUTTONS]; 

    for (size_t i = 0; i < NUM_BUTTONS; i++)
    {
    }
    
    // Writing to pins 0 to 31
    // #define	GPSET0	7 // 28/4
    // #define 	GPCLR0	10 // 40/4
    // if (writing 1)
    //     gpio[GPSET0] = 1 << pinNumber;
    // else
    //     gpio[GPCLR0] = 1 << pinNumber;


    // Reading from pins 0 to 31
    // unsigned int *gpio = 0x7E200000;
    // #define	GPLEV0	13
    // int v;
    // v = (gpio[GPLEV0] >> 3) & 1; 
    // v = pin 3 value


    
    return 0;
}

