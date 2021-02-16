// Cole Thiessen (30027689) & Isaac Lutzko
// This program is a driver for the SNES controller
// It will output what buttons are pressed in the console

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include "initGPIO.h"

#define CLK 11
#define LAT 9
#define DAT 10
#define INP_GPIO(g) *(gpioPtr + ((g) / 10)) &= ~(7 << (((g) % 10) * 3))
#define OUT_GPIO(g) *(gpioPtr + ((g) / 10)) |= (1 << (((g) % 10) * 3))
#define GPSET0 7  // 28/4
#define GPCLR0 10 // 40/4
#define GPLEV0 13
#define NUM_BUTTONS 16
#define HIGH 1
#define LOW 0

// Register gpio base address global
unsigned int *gpioPtr;

void initSNES(unsigned int *gpioPtr)
{
    INP_GPIO(CLK); // CLK
    OUT_GPIO(CLK);
    INP_GPIO(LAT); // LATCH
    OUT_GPIO(LAT);
    INP_GPIO(DAT); // DATA
}

// Writing to pins 0 to 31
void writeGPIO(unsigned int pinNumber, unsigned int bit)
{
    if (bit == HIGH)
    {
        gpioPtr[GPSET0] = 1 << pinNumber;
    }
    else
    {
        gpioPtr[GPCLR0] = 1 << pinNumber;
    }
}

// Reading from pins 0 to 31
int readGPIO(unsigned int pinNumber)
{
    return (gpioPtr[GPLEV0] >> pinNumber) & 1;
}

void debugButtons(int buttons[])
{
    for (size_t i = 1; i <= NUM_BUTTONS; i++)
    {
        printf("buttons[%d] = %d\n", i, buttons[i]);
    }
}

char* getButtonName(int buttonIndex) {
    switch (buttonIndex)
    {
    case 1:
        printf("You pressed B\n");
        return "B"; 
        break;
    case 2:
        printf("You pressed Y\n");
        return "Y"; 
        break;
    default:
        break;
    }
}

const char* checkForButtonPress(int buttons[])
{
    for (size_t i = 0; i < NUM_BUTTONS; i++)
    {
        if(buttons[i] == 0) {
            // return getButtonName(i+1);
            debugButtons(buttons);
        }
    }
    return "";
}

void readControllerInput(int buttons[])
{
    writeGPIO(CLK, HIGH);
    writeGPIO(LAT, HIGH);

    // Wait 12 Microsec
    delayMicroseconds(12);

    writeGPIO(LAT, LOW);

    int buttonSignal;
    for (size_t i = 1; i <= NUM_BUTTONS; i++)
    {
        // wait 6 ms
        delayMicroseconds(6);
        writeGPIO(CLK, HIGH);

        // wait 6 ms
        delayMicroseconds(6);
        buttonSignal = readGPIO(DAT); // Read bit i
        printf("button %d = %d\n", i, buttonSignal);
        // buttons[i-1] = buttonSignal;
        // if(buttonSignal == 0) {
        //     getButtonName(buttonSignal);
        // }
        // debugButtons(buttons);
        writeGPIO(CLK, HIGH); // Rising edge; new cycle
    }
    // checkForButtonPress(buttons);
}

int main()
{
    printf("Created by: Cole Thiessen and Isaac Lutzko\n");

    // Get gpio pointer
    gpioPtr = getGPIOPtr();

    // Initialize the SNES controller
    initSNES(gpioPtr);

    // Store sampled buttons

    printf("Please press a button...\n");

    int buttons[NUM_BUTTONS];
    do
    {
        memset(buttons, 0, NUM_BUTTONS * sizeof(int));
        // debugButtons(buttons);
        sleep(3);
        readControllerInput(buttons);
        // debugButtons(buttons);
        // checkForButtonPress(buttons);
    } while (1);

    return 0;
}
