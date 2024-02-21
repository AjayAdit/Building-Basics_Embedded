#include "stm32f4xx_hal.h"   

void LEDpins (void);
void Pushbutton(void); // Declaration of fuctions to be called below

int main(void) // Manin function root of the program
{

LEDpins();//1: Configure LEDs pins
	
Pushbutton();//2: Configure pushbuttons

while(1)
{
if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0))
	{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET); // PIN_SET means on
	}
	else 
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET); // PIN_RESET means off
}
}
void LEDpins (void)
{
__HAL_RCC_GPIOD_CLK_ENABLE();// / enable cloack of board for port D
GPIO_InitTypeDef myLEDConfig; //  Here myLEDConfig is a variable and then GPIO_InitTypeDef has its own definition which are the below 3 lines
myLEDConfig.Mode = GPIO_MODE_OUTPUT_PP;
myLEDConfig.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
HAL_GPIO_Init(GPIOD, &myLEDConfig); //Here GPIOA is of type myLEDConfig
		
}

void Pushbutton(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();// enable cloack of board for port A
	GPIO_InitTypeDef pushbutton; //  Here pushbutton is a variable and then GPIO_InitTypeDef has its own definition which are the below 3 lines
	pushbutton.Mode = GPIO_MODE_INPUT;
	pushbutton.Pin = GPIO_PIN_0;
	pushbutton.Pull= GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &pushbutton);// Here GPIOA is of type push button
	}