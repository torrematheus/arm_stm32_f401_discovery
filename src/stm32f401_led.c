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
#define REGISTER_BASE_RCC   		0x40023800U
#define RCC_AHB1_ENABLE_OFF_SET		0x30U
#define REGISTER_AHB1_GPIO  		(*((volatile uint32_t *)(REGISTER_BASE_RCC + RCC_AHB1_ENABLE_OFF_SET)))

#define REGISTER_GPIOD_MORDER 		(*((volatile uint32_t *)0x40020C00))
#define REGISTER_GPIOD_OTYPER 		(*((volatile uint32_t *)0x40020C04))
#define REGISTER_GPIOD_OSPEEDR 		(*((volatile uint32_t *)0x40020C08))
#define REGISTER_GPIOD_PUPDR 		(*((volatile uint32_t *)0x40020C0C))
#define REGISTER_GPIOD_IDR 			(*((volatile uint32_t *)0x40020C10))
#define REGISTER_GPIOD_ODR 			(*((volatile uint32_t *)0x40020C14))
#define REGISTER_GPIOD_BSRR 		(*((volatile uint32_t *)0x40020C18))
#define REGISTER_GPIOD_LCKR 		(*((volatile uint32_t *)0x40020C1C))
#define REGISTER_GPIOD_AFRL 		(*((volatile uint32_t *)0x40020C20))
#define REGISTER_GPIOD_AFRH 		(*((volatile uint32_t *)0x40020C24))

/**************************************************************************************************
 * Typedefs and Variable Definitions
 **************************************************************************************************/


/**************************************************************************************************
 * Private Function Prototypes
 **************************************************************************************************/

/**************************************************************************************************
 * Public Function Prototypes
 **************************************************************************************************/
void stm32f401_led_init(uint8_t group_gpio, uint8_t gpio_pin);
void stm32f401_led_set_status(uint8_t gpio_pin, bool value);

/**************************************************************************************************
 * Public Function Definitions
 **************************************************************************************************/
void stm32f401_led_init(uint8_t group_gpio, uint8_t gpio_pin)
{
	REGISTER_AHB1_GPIO |= (0x00000001U << group_gpio);	//Enable Clock GPIOD

	REGISTER_GPIOD_MORDER 	|= (0b01 << 2*gpio_pin); 	//General purpose output mode
	REGISTER_GPIOD_OTYPER 	|= (0b00 << gpio_pin); 		//Output push-pull (reset state)
	REGISTER_GPIOD_OSPEEDR  |= (0b10 << 2*gpio_pin); 	//High speed
	REGISTER_GPIOD_PUPDR	|= (0b01 << 2*gpio_pin);	//Pull-up

}

void stm32f401_led_set_status(uint8_t gpio_pin, bool value)
{
	REGISTER_GPIOD_ODR |= (value << gpio_pin);

	REGISTER_GPIOD_ODR &= (value << gpio_pin);

	REGISTER_GPIOD_ODR |= (value << gpio_pin);
}

/**************************************************************************************************
 * Private Function Definitions
 **************************************************************************************************/





