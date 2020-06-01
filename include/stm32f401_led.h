/**
  **********************************************************************************************
  * @file     STM32f401/stm32f401_led.h
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
  *
  * *************************************************************************************************
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
  * @bug
  *
  * *************************************************************************************************
  */

#ifndef OSDEVICEDRIVER_STM32F401_STM32F401_LED_H_
#define OSDEVICEDRIVER_STM32F401_STM32F401_LED_H_

/**************************************************************************************************
 * Includes
 **************************************************************************************************/
#include <stdbool.h>
#include "stm32f401_gpio.h"
/**************************************************************************************************
 * Preprocessor Macros and Defines
 **************************************************************************************************/

/**************************************************************************************************
 * Typedefs and Variable Definitions
 **************************************************************************************************/
/**
 * @brief STM32F4XX Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
typedef enum
{
	LED_RED = 14,
	LED_GREEN = 12,
	LED_BLUE = 15,
	LED_ORANGE = 13,
} led_native_t;
/**************************************************************************************************
 * Private Function Prototypes
 **************************************************************************************************/

/*************************************************************************************************/
/**
 * \brief       This function init led native on stm32f401.
 */
/*************************************************************************************************/
void stm32f401_led_init_native(led_native_t led_pin_native);

/*************************************************************************************************/
/**
 * \brief       This function set status of led native on stm32f401.
 */
/*************************************************************************************************/
void stm32f401_led_set_status_native(led_native_t gpio_pin, bool value);

/**************************************************************************************************
 * Public Function Prototypes
 **************************************************************************************************/



#endif /* OSDEVICEDRIVER_STM32F401_STM32F401_LED_H_ */
