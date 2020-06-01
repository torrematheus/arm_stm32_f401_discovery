/**
  **********************************************************************************************
  * @file     STM32f401/stm32f401_led.c
  * @project
  * @platform
  * @device   STM32f401
  * @author   Matheus Torres Rocha
  * @version  V1.0.0
  * @date     26-May-2020
  * @brief    This file contains the functions to abstract the GPIO functions.
  *
  * @history
  *
  * When         Who               What
  * -----------  ----------------  -------------------------------------------------------------
  * 26-May-2020  Matheus Torres     - Initial version.
  * *************************************************************************************************
  * @attention
  *	• LD1 COM:
  * LD1 default status is red. LD1 turns to green to indicate that communications are in
  * progress between the PC and the ST-LINK/V2.
  * • LD2 PWR:
  * The red LED indicates that the board is powered.
  * • User LD3:
  * The orange LED is a user LED connected to the I/O PD13 of the STM32F401VCT6.
  * • User LD4:
  * The green LED is a user LED connected to the I/O PD12 of the STM32F401VCT6.
  * • User LD5:
  * The red LED is a user LED connected to the I/O PD14 of the STM32F401VCT6.
  * • User LD6:
  * The blue LED is a user LED connected to the I/O PD15 of the STM32F401VCT6.
  * • USB LD7:
  * The green LED indicates when VBUS is present on CN5 and is connected to PA9 of
  * the STM32F401VCT6.
  * • USB LD8:
  * The red LED indicates an overcurrent from VBUS of CN5 and is connected to the I/O
  * PD5 of the STM32F401VCT6.
  * *************************************************************************************************
  *
  * *************************************************************************************************
  * @bug
  *
  * *************************************************************************************************
  */

  /**************************************************************************************************
 * Includes
 **************************************************************************************************/
#include <stm32f401_led.h>

/**************************************************************************************************
 * Preprocessor Macros and Defines
 **************************************************************************************************/

#define BIT(N)       (1U<<(N))

/**************************************************************************************************
 * Typedefs and Variable Definitions
 **************************************************************************************************/

/**************************************************************************************************
 * Private Function Prototypes
 **************************************************************************************************/

/**************************************************************************************************
 * Public Function Prototypes
 **************************************************************************************************/
void stm32f401_led_init_native(led_native_t led_pin_native);
void stm32f401_led_set_status_native(led_native_t gpio_pin, bool value);

/**************************************************************************************************
 * Public Function Definitions
 **************************************************************************************************/
void stm32f401_led_init_native(led_native_t led_pin_native)
{
	stm32f401_gpio_clock_config(AHB1ENR_GPIOD);

	GPIO_InitTypeDef GPIO_InitStructure;

	switch(led_pin_native)
	{
		case LED_RED:
			GPIO_InitStructure.Pin = BIT(LED_RED);
			break;
		case LED_ORANGE:
			GPIO_InitStructure.Pin = BIT(LED_ORANGE);
			break;
		case LED_BLUE:
			GPIO_InitStructure.Pin = BIT(LED_BLUE);
			break;
		case LED_GREEN:
			GPIO_InitStructure.Pin = BIT(LED_GREEN);
			break;
	};

	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pull = GPIO_PULLUP;

	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void stm32f401_led_set_status_native(led_native_t gpio_pin, bool value)
{
    HAL_GPIO_WritePin(GPIOD, BIT(gpio_pin), value);
}

/**************************************************************************************************
 * Private Function Definitions
 **************************************************************************************************/





