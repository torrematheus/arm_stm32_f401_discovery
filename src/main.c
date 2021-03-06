/*
 * Matheus Torres Rocha
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stm32f401_led.h>
#include "diag/Trace.h"
#include "stm32f401_led.h"

// ----------------------------------------------------------------------------
//
// Semihosting STM32F4 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

#define GROUP_D_GPIO		3
#define GPIO_RED			14

int main(int argc, char* argv[])
{
  // At this stage the system clock should have already been configured
  // at high speed.

	stm32f401_led_init(GROUP_D_GPIO,GPIO_RED); //GPIO RED!

#define LOOP_COUNT (5)
  int loops = LOOP_COUNT;
  if (argc > 1)
    {
      // If defined, get the number of loops from the command line,
      // configurable via semihosting.
      loops = atoi (argv[1]);
    }

  // Short loop.
  for (int i = 0; i < loops; i++)
    {
	  stm32f401_led_set_status(GPIO_RED, true);

	  stm32f401_led_set_status(GPIO_RED, false);

	  stm32f401_led_set_status(GPIO_RED, true);
       // Add your code here.
    }
  return 0;
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
