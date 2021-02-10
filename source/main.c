#include <unistd.h>
#include <stdio.h>
#include "initGPIO.h"

int main()
{
    // get gpio pointer
    unsigned int *gpioPtr = getGPIOPtr();  
    printf("pointer address: %p\n", gpioPtr);
    
    //TODO: Set pin 17 to input
    //TODO: Set pin 24 to output
    //TODO: Set pin 24 value to 1, and display result
    //TODO: Set pin 24 value to 0, and display result
    
    return 0;
}
