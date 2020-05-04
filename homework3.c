#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;
    //unsigned char buttonhistory;

    // TODO: Declare the variables that main uses to interact with your state machine.


    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        //turnOn_LaunchpadLED2Red();
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired())
        {
            count0++;
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if(timer1Expired())
        {
            fsmBoosterpackButtonS1(count1);

        }



        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        fsmBoosterpackButtonS1(buttonhistory);



        // TODO: If a completed, debounced button press has occurred, increment count1.
        if (fsmBoosterpackButtonS1(buttonhistory))
        {
            count1++;
        }

    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    switch (count & 7)
    {
        // This function turns off Launchpad LED2.
        case 0:
        {
            P2OUT = P2OUT & ~LED2R;
            P2OUT = P2OUT & ~LED2G;
            P2OUT = P2OUT & ~LED2B;
        }
            break;

        // This function turns on Launchpad Red LED2.
        case 1:
        {
            turnOn_LaunchpadLED2Red();
        }
        break;

        // This function turns on Launchpad Green LED2.
        case 2:
        {
            turnOn_LaunchpadLED2Green();
        }
        break;

        // This function turns on Launchpad (Yellow) LED2.
        case 3:
        {
            P2OUT = P2OUT | LED2R;
            P2OUT = P2OUT | LED2G;
            P2OUT = P2OUT & ~LED2B;
        }
        break;

        // This function turns on Launchpad Blue LED2.
        case 4:
             turnOn_LaunchpadLED2Blue();
        break;

        // This function turns on Launchpad (Magenta) LED2.
        case 5:
        {
            P2OUT = P2OUT | LED2R;
            P2OUT = P2OUT & ~LED2G;
            P2OUT = P2OUT | LED2B;
        }
        break;

        // This function turns on Launchpad (Cyan) LED2.
        case 6:
        {
             P2OUT = P2OUT & ~LED2R;
             P2OUT = P2OUT | LED2G;
             P2OUT = P2OUT | LED2B;
        }
        break;

        // This function turns on Launchpad (White) LED2.
        case 7:
        {
             P2OUT = P2OUT | LED2R;
             P2OUT = P2OUT | LED2G;
             P2OUT = P2OUT | LED2B;

        }
        break;

         // This function turns off Launchpad LED2.
        default:
        {
             P2OUT = P2OUT & ~LED2R;
             P2OUT = P2OUT & ~LED2G;
             P2OUT = P2OUT & ~LED2B;
        }
        break;
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count) //BLED (Buttons)
{
    switch (count & 7)
    {
        //This function turns off Boosterpack LED.
        case 0:
        {
            P2OUT = P2OUT & ~BLEDR;
            P2OUT = P2OUT & ~BLEDG;
            P5OUT = P5OUT & ~BLEDB;
        }
        break;

        // This function turns on Boosterpack Red LED.
        case 1:
             turnOn_BoosterpackLEDRed();
        break;

        // This function turns on Boosterpack Green LED.
        case 2:
             turnOn_BoosterpackLEDGreen();
        break;

        // This function turns on Boosterpack (Yellow) LED.
        case 3:
        {
            P2OUT = P2OUT | BLEDR;
            P2OUT = P2OUT | BLEDG;
            P5OUT = P5OUT & ~BLEDB;
        }
        break;

        // This function turns on Boosterpack Blue LED.
        case 4:
             turnOn_BoosterpackLEDBlue();
        break;

        // This function turns on Boosterpack (Magenta) LED.
        case 5:
        {
            P2OUT = P2OUT | BLEDR;
            P2OUT = P2OUT & ~BLEDG;
            P5OUT = P5OUT | BLEDB;
        }
        break;

        // This function turns on Boosterpack (Cyan) LED.
        case 6:
        {
             P2OUT = P2OUT & ~BLEDR;
             P2OUT = P2OUT | BLEDG;
             P5OUT = P5OUT | BLEDB;
        }
        break;

        // This function turns on Boosterpack (White) LED.
        case 7:
        {
             P2OUT = P2OUT | BLEDR;
             P2OUT = P2OUT | BLEDG;
             P5OUT = P5OUT | BLEDB;
        }
        break;

         // This function turns off Boosterpack LED.
        default:
        {
             P2OUT = P2OUT & ~BLEDR;
             P2OUT = P2OUT & ~BLEDG;
             P5OUT = P5OUT & ~BLEDB;
        }
        break;
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false;

    switch(buttonhistory)
    {
        case A:
            if (checkStatus_BoosterpackS1() == 0) //if PRESSED
            {
                buttonhistory = B;//
                return true;
            }
        break;

        case B:
            if (checkStatus_BoosterpackS1() == 1) //if UNPRESSED
            {
                buttonhistory = A;//
            }
        break;
    }

    return pressed;
}
