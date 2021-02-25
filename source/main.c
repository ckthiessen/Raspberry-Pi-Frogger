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
    for (size_t i = 0; i < NUM_BUTTONS; i++)
    {
        printf("buttons[%d] = %d\n", i, buttons[i]);
    }
}

void printButtonName(int buttonIndex)
{
    char *name;
    switch (buttonIndex)
    {
    case 1:
        name = "B";
        break;
    case 2:
        name = "Y";
        break;
    case 3:
        name = "Select";
        break;
    case 4:
        name = "Start";
        break;
    case 5:
        name = "Joy-pad UP";
        break;
    case 6:
        name = "Joy-pad DOWN";
        break;
    case 7:
        name = "Joy-pad LEFT";
        break;
    case 8:
        name = "Joy-pad RIGHT";
        break;
    case 9:
        name = "A";
        break;
    case 10:
        name = "X";
        break;
    case 11:
        name = "Left";
        break;
    case 12:
        name = "Right";
        break;
    default:
        name = "nul"; //-----------------
        break;
    }
    
    // return name;
    printf("You pressed %s\n", name);
    
    
}

int checkForButtonPress(int buttons[])
{
    for (size_t i = 0; i < NUM_BUTTONS; i++)
    {
        if (buttons[i] == 0)
        {
            //debugButtons(buttons);
            return i + 1;
        }
    }
    // Did not detect button press
    return -1;
}

void clearArray(int buttons[]) {
    for (size_t i = 0; i < NUM_BUTTONS; i++)
    {
        buttons[i] = 1;
    }
}

int buttons[NUM_BUTTONS];

//TESTING THIS
int prevButtons[NUM_BUTTONS];

int readControllerInput()
{
    initSNES(gpioPtr);

    //int buttons[NUM_BUTTONS];
    //clearArray(buttons); //-----------------------

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
        writeGPIO(CLK, LOW);

        // wait 6 ms
        delayMicroseconds(6);
        buttonSignal = readGPIO(DAT); // Read bit i
        buttons[i - 1] = buttonSignal;

        writeGPIO(CLK, HIGH); // Rising edge; new cycle
    }
    return checkForButtonPress(buttons);
}

int main()
{
    printf("Created by: Cole Thiessen and Isaac Lutzko\n");

    // Get gpio pointer
    gpioPtr = getGPIOPtr();

    // Initialize the SNES controller
    initSNES(gpioPtr);

    // Store sampled buttons
    int buttonIndex;
    int prevPress = -1;

    while(1) {
        printf("Please press a button...\n");

        buttonIndex = -1; //--------------------------
        // Wait until buttonIndex is a valid button 
        delayMicroseconds(150000);
        while(1) {
            // printf("HERE");
            //clearArray(buttons);//--------------------------
            buttonIndex = -1;

            buttonIndex = readControllerInput();
            // need some kind of a break here if button status is the same?
            if(buttonIndex != -1 && buttonIndex == prevPress){
                //delayMicroseconds(400000);
                printButtonName(buttonIndex);
            //    prevPress = buttonIndex;
                //delayMicroseconds(400000);
                break;
            }
            //prevPress = -1;
            else if(buttonIndex != -1 && buttonIndex != prevPress) {
                break;
            }
            //prevPress = -1;
            //buttonIndex = -1;
        }

        if(buttonIndex == 4) {
            printf("Program is terminating...\n");
            break;
        }

        if(buttonIndex != prevPress) { 
            printf("BI: %d\n", buttonIndex);
            printButtonName(buttonIndex);
            prevPress = buttonIndex;
        }

        //delayMicroseconds(400000);

        //TESTING
        //prevButtons[NUM_BUTTONS] = buttons[NUM_BUTTONS];
        //prevButtons = buttons;
        //clearArray(buttons);

        //if(buttonIndex != -1 && buttonIndex == prevPress) {
        //    printf("BI: %d\n", buttonIndex);
        //    printButtonName(buttonIndex);
        //}

        //clearArray(buttons);
    }
    return 0;
}
