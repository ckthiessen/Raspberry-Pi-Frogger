#include <unistd.h>
#include <stdio.h>
#include <wiringPi.h>
#include "initGPIO.h"

#define CLK 11
#define LAT 9
#define DAT 10
#define INP_GPIO(g) *(gpioPtr +((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpioPtr+((g)/10)) |= (1<<(((g)%10)*3))
#define SET_GPIO_ALT(g,a) *(gpioPtr+(((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))
#define	GPSET0	7 // 28/4
#define GPCLR0	10 // 40/4
#define	GPLEV0	13
#define NUM_BUTTONS 16

// Register gpio base address global
unsigned int *gpioPtr;

void initSNES(unsigned int *gpioPtr) {
    INP_GPIO( CLK );        // CLK
    OUT_GPIO( CLK );
    INP_GPIO( LAT );        // LATCH
    OUT_GPIO( LAT );
    INP_GPIO( DAT );        // DATA
}

// Writing to pins 0 to 31
void writeGPIO(unsigned int pinNumber, unsigned int bit) {
    if (bit == 1) {
        gpioPtr[GPSET0] = 1 << pinNumber;
    }
    else {
        gpioPtr[GPCLR0] = 1 << pinNumber;
    }
}


// Reading from pins 0 to 31
int readGPIO(unsigned int pinNumber) {
    return (gpioPtr[GPLEV0] >> 3) & 1; 
    // int v;
    // v = (gpio[GPLEV0] >> 3) & 1; 
    // v = pin 3 value
}

int main()
{
    // get gpio pointer
    // Maybe try local if doesn't work
    gpioPtr = getGPIOPtr();  

    printf("pointer address: %p\n", gpioPtr);

    initSNES(gpioPtr);

    // Store sampled buttons
    int buttons[NUM_BUTTONS]; 

    
    writeGPIO(CLK,1);
    writeGPIO(LAT,1);

    // Wait 12 Microsec
    delayMicroseconds(12);

    writeGPIO(LAT, 0);

    int i = 1;
    int buttonSignal;
    while(i <= 16) {
        // wait 6 ms
        delayMicroseconds(6);
        writeGPIO(CLK,1);

        // wait 6 ms
        delayMicroseconds(6);
        buttonSignal = readGPIO(DAT); // Read bit i
        buttons[i] = buttonSignal;
        writeGPIO(CLK, 1); // Rising edge; new cycle
        i++; // Next button
    }

    for (size_t i = 0; i < NUM_BUTTONS; i++)
    {
        printf("buttons[%d] = %d\n", i, buttons[i]);
    }
    
    return 0;
}

