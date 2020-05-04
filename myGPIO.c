/*
 * GPIO.c
 *
 *  Created on: 03/05/2020
 *      Author: Hamud Hamud
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    //L1 peripherals
    P1DIR = P1DIR & ~L1;
    P1REN = P1REN | L1;
    P1OUT = P1OUT | L1;

    //LED1 peripheral
    //P1DIR = P1DIR | LED1R;

    //L2 peripherals
    P1DIR = P1DIR & ~L2;
    P1REN = P1REN | L2;
    P1OUT = P1OUT | L2;

    //LED2R peripheral
    P2DIR = P2DIR | LED2R;

    //LED2G peripheral
    P2DIR = P2DIR | LED2G;

    //LED2B peripheral
    P2DIR = P2DIR | LED2B;

    //BLEDR peripheral
    P2DIR = P2DIR | BLEDR;

    //B2 peripherals
    P3DIR = P3DIR & ~B2;
    P3REN = P3REN | B2;
    P3OUT = P3OUT | B2;

    //BLEDG peripheral
    P2DIR = P2DIR | BLEDG;

    //B1 peripherals
    P5DIR = P5DIR & ~B1;
    P5REN = P5REN | B1;
    P5OUT = P5OUT | B1;

    //BLEDB peripheral
    P5DIR = P5DIR | BLEDB;

    // Turn off all LEDs at the start.

    P2OUT = P2OUT & ~LED2R;
    P2OUT = P2OUT & ~LED2B;
    P2OUT = P2OUT & ~LED2G;

    P2OUT = P2OUT & ~BLEDR;
    P2OUT = P2OUT & ~BLEDG;
    P5OUT = P5OUT & ~BLEDB;

}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & L1) == L1);////
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & L2) == L2);////
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & B1) == B1);////
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P5IN & B2) == B2);////
}

// TODO: Create a function to turn on Launchpad LED1.


// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | LED2R;
    P2OUT = P2OUT & ~LED2G;
    P2OUT = P2OUT & ~LED2B;
}

// TODO: Create a function to turn off the Red Launchpad LED2. //
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LED2R;
    P2OUT = P2OUT & ~LED2G;
    P2OUT = P2OUT & ~LED2B;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LED2R;
    P2OUT = P2OUT | LED2G;
    P2OUT = P2OUT & ~LED2B;
}

// TODO: Create a function to turn off the Green Launchpad LED2. //
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LED2G;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LED2R;
    P2OUT = P2OUT & ~LED2G;
    P2OUT = P2OUT | LED2B;
}

// TODO: Create a function to turn off the Blue Launchpad LED2. //
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LED2B;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | BLEDR;
    P2OUT = P2OUT & ~BLEDG;
    P5OUT = P5OUT & ~BLEDB;
}

// TODO: Create a function to turn off the Red Boosterpack LED2. //
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~BLEDR;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BLEDR;
    P2OUT = P2OUT | BLEDG;
    P5OUT = P5OUT & ~BLEDB;
}

// TODO: Create a function to turn off the Green Boosterpack LED2. //
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BLEDG;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P2OUT = P2OUT & ~BLEDR;
    P2OUT = P2OUT & ~BLEDG;
    P5OUT = P5OUT | BLEDB;
}

// TODO: Create a function to turn off the Green Boosterpack LED2. //
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BLEDB;
}
