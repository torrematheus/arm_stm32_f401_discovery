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
  *
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
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>
/**************************************************************************************************
 * Preprocessor Macros and Defines
 **************************************************************************************************/

/**************************************************************************************************
 * Typedefs and Variable Definitions
 **************************************************************************************************/

/**************************************************************************************************
 * Private Function Prototypes
 **************************************************************************************************/

/*************************************************************************************************/
/**
 * \brief       This function init led on stm32f401.
 */
/*************************************************************************************************/
void stm32f401_led_init(uint8_t group_gpio, uint8_t gpio_pin);

/*************************************************************************************************/
/**
 * \brief       This function set status of led on stm32f401.
 */
/*************************************************************************************************/
void stm32f401_led_set_status(uint8_t gpio_pin, bool value);

/**************************************************************************************************
 * Public Function Prototypes
 **************************************************************************************************/



#endif /* OSDEVICEDRIVER_STM32F401_STM32F401_LED_H_ */
