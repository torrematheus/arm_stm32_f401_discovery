/**
  **********************************************************************************************
  * @file     STM32f401/stm32f401_clock.h
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

#ifndef STM32F401_CLOCK_H_
#define STM32F401_CLOCK_H_


/**************************************************************************************************
 * Includes
 **************************************************************************************************/
#include "stm32f401_register.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f401xc.h"

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
	AHB1ENR_GPIOA = 0,
	AHB1ENR_GPIOB = 1,
	AHB1ENR_GPIOC = 2,
	AHB1ENR_GPIOD = 3,
	AHB1ENR_GPIOH = 7,
	AHB1ENR_CRCLPEN = 12,
	AHB1ENR_FLITFLPEN = 15,
	AHB1ENR_SRAM1LPEN = 16,
	AHB1ENR_DMA1LPEN = 21,
	AHB1ENR_DMA2LPEN = 22,
} AHB1ENR_bits_map_t;
/**************************************************************************************************
 * Private Function Prototypes
 **************************************************************************************************/

/**************************************************************************************************
 * Public Function Prototypes
 **************************************************************************************************/
void stm32f401_clock_anable_AHB1ENR(AHB1ENR_bits_map_t type_bit);

#endif /* STM32F401_CLOCK_H_ */
