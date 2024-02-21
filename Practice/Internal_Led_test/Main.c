#include "stm32f4xx_hal.h"	    //library functions and definitions needed for configuring and controlling the microcontroller peripherals.

void configureLEDpins (void); 
void msDelay(uint32_t msTime); // The above and this line are fuction prototypes usefull in informing compilers about functions before their actual implementation 


int main(void)
{
    HAL_Init(); // Initialize HAL from the above header files

    configureLEDpins(); //Calls a function to configure the GPIO pins connected to the LEDs.

    while (1)// This block is a infinite loop that toggles the LED pins in he belowq sequence the with 100 ms delay. HAL_GPIO_TogglePin() is the fuction to toggle the pins and msDelay is to delay.
    {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
        msDelay(100);
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
        msDelay(100);
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
        msDelay(100);
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
        msDelay(100);
    }
}

void configureLEDpins(void) // This block configures the GPIO pins connected to the LEDs.
{
    GPIO_InitTypeDef myLEDConfig; // declares myLEDConfig of type GPIO_InitTypeDef, which is used to configure the GPIO pins.

    __HAL_RCC_GPIOD_CLK_ENABLE(); //  Enables the clock for GPIO Port D which is the pins for internal LEDS as per the pin diagram of the board

    myLEDConfig.Mode = GPIO_MODE_OUTPUT_PP; // Sets the pin mode to output push-pull,which allows the pins to drive the LEDs.
    myLEDConfig.Pull = GPIO_NOPULL; //Specifies there is no internal pull-up or pull-down resistor enabled
    myLEDConfig.Speed = GPIO_SPEED_FREQ_LOW; // Sets the speed of the GPIO pins to low frequency 
    myLEDConfig.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15; //Specifies the pins to be initialized. In this case, all four LED pins (12, 13, 14, and 15)

    HAL_GPIO_Init(GPIOD, &myLEDConfig); //Initializes the GPIO pins of GPIOD according to the configuration specified in myLEDConfig (GPIOD means GPIO port D to which Led is connected)
}

void msDelay(uint32_t msTime) // This function calls HAL_Delay() with the specified delay duration 
{
    HAL_Delay(msTime);
}
