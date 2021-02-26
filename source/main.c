// Authors: Cole Thiessen (30027689) & Isaac Lutzko (30026703)
// CPSC359 Winter 2021 Project (Part 1) SNES Controller Device Driver
// February 26, 2021
// Description: This program is a driver for the SNES controller.
//              It will output what buttons are pressed in the console.

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
#define START 4

// Register gpio base address global
unsigned int *gpioPtr;

/*
@Params: gpioPtr: The register GPIO base address gpioPtr
@Returns: This subroutine does not return anything
This subroutine initializes a GPIO line for the three SNES lines: the latch line, the clock line, and the data line
*/
void init_GPIO(unsigned int *gpioPtr)
{
    INP_GPIO(CLK); // CLK
    OUT_GPIO(CLK); // CLK
    INP_GPIO(LAT); // LATCH
    OUT_GPIO(LAT); // LATCH
    INP_GPIO(DAT); // DATA
}

// Writing from pins 0 to 31
/*
@Params: pinNumber: The unsigned integer pin number that we are writing a bit to - in this case the GPIO latch line or the GPIO clock line
@Params: bit: The unsigned integer bit that we are writing to the pin
@Returns: This subroutine does not return anything
This subroutine writes a bit to a GPIO line depending on the pin we use as input.  In our program we use this to 
either write a bit to the GPIO latch line or the GPIO clock line.
*/
void writeGPIO_LAT_CLK(unsigned int pinNumber, unsigned int bit)
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
/*
@Params: pinNumber: The unsigned integer pin number that we are reading a bit from - in this case from the GPIO data line
@Returns: Integer Number: the bit that is read from the GPIO data line
This subroutine reads a bit from the GPIO data line
*/
int Read_Data(unsigned int pinNumber)
{
    return (gpioPtr[GPLEV0] >> pinNumber) & 1;
}

/*
@Params: buttonIndex: The integer that corresponds to the button that has been pressed or lack thereof
@Returns: This subroutine does not return anything
This subroutine prints a messasge for a button that has been pressed 
*/
void Print_Message(int buttonIndex)
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
        break;
    }
    // return name;
    printf("You pressed %s\n", name);
    
    
}

/*
@Params: buttons[]: integer array that tracks the status of the buttons 
@Returns: Integer Number: button number from 0-12 if that button has been pressed or -1 if no button has been pressed
This subroutine checks if a button has been press by iterating through the button integer array.  Called in Read_SNES()
*/
int checkForButtonPress(int buttons[])
{
    for (size_t i = 0; i < NUM_BUTTONS; i++)
    {
        if (buttons[i] == 0)
        {
            // Did detect button press
            return i + 1;
        }
    }
    // Did not detect button press
    return -1;
}

/*
@Returns: Integer Number: the button number that corresponds to a button if it is pressed or lack thereof.
This is the main SNES subroutine.  Reads input (buttons pressed or not pressed) from a SNES controller.  The returns
the button number/code of a pressed button in a register.
*/
int Read_SNES()
{
    // integer button array that keeps track of the status of the buttons on the SNES
    int buttons[NUM_BUTTONS];

    // write 1 to the GPIO clock line
    writeGPIO_LAT_CLK(CLK, HIGH);
    // write 1 to the GPIO latch line
    writeGPIO_LAT_CLK(LAT, HIGH);

    // Wait 12 Microsec
    delayMicroseconds(12);

    // write 0 to the GPIO latch line
    writeGPIO_LAT_CLK(LAT, LOW);

    int buttonSignal;
    for (size_t i = 1; i <= NUM_BUTTONS; i++)
    {
        // wait 6 ms
        delayMicroseconds(6);
        // write 0 to the GPIO clock line
        writeGPIO_LAT_CLK(CLK, LOW);

        // wait 6 ms
        delayMicroseconds(6);
        buttonSignal = Read_Data(DAT); // Read bit i
        buttons[i - 1] = buttonSignal;

        // write 1 to the GPIO clock line
        writeGPIO_LAT_CLK(CLK, HIGH); // Rising edge; new cycle
    }
    return checkForButtonPress(buttons);
}

//======================Main Function============================
int main()
{
    printf("Created by: Cole Thiessen and Isaac Lutzko\n");

    // Get gpio pointer
    gpioPtr = getGPIOPtr();

    // Initialize the SNES controller
    init_GPIO(gpioPtr);

    // Store sampled buttons
    int buttonIndex;
    int prevPress = -1;

    // While the program is still running and a user has not pressed START which ends the program
    while(buttonIndex != START) {
        
        printf("\n");
        printf("Please press a button...\n");

        buttonIndex = -1;

        // Delay to prevent printing too much -- 175000 microseconds because not too slow and still very responsive
        delayMicroseconds(175000);

        while(1) {
            buttonIndex = -1;

            // Get button code that corresponds to the button that is pressed or lack thereof
            buttonIndex = Read_SNES();

            // If same button pressed two or more times or held pressed:
            if(buttonIndex != -1 && buttonIndex == prevPress){
                printf("\n");
                // Print appropriate message for button press
                Print_Message(buttonIndex);
                break;
            }
            // If pressed button is not the previously pressed button
            else if(buttonIndex != -1 && buttonIndex != prevPress) {
                break;
            }
        }

        if(buttonIndex != prevPress && buttonIndex != START) { 
            printf("\n");
            // Print appropriate message for button press
            Print_Message(buttonIndex);
            // Set previous button code to the button code that was just pressed
            prevPress = buttonIndex;
        }
    }
    printf("\n");
    printf("Program is terminating...\n");

    return 0;
}
