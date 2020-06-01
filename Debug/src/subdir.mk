################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/_initialize_hardware.c \
../src/_write.c \
../src/main.c \
../src/stm32f401_clock.c \
../src/stm32f401_gpio.c \
../src/stm32f401_led.c \
../src/stm32f401_register.c \
../src/stm32f401_timer.c \
../src/stm32f4xx_hal_msp.c 

OBJS += \
./src/_initialize_hardware.o \
./src/_write.o \
./src/main.o \
./src/stm32f401_clock.o \
./src/stm32f401_gpio.o \
./src/stm32f401_led.o \
./src/stm32f401_register.o \
./src/stm32f401_timer.o \
./src/stm32f4xx_hal_msp.o 

C_DEPS += \
./src/_initialize_hardware.d \
./src/_write.d \
./src/main.d \
./src/stm32f401_clock.d \
./src/stm32f401_gpio.d \
./src/stm32f401_led.d \
./src/stm32f401_register.d \
./src/stm32f401_timer.d \
./src/stm32f4xx_hal_msp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DOS_USE_SEMIHOSTING -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/stm32f4xx_hal_msp.o: ../src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DOS_USE_SEMIHOSTING -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/stm32f4xx_hal_msp.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


