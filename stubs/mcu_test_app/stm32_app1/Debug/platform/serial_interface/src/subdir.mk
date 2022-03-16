################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../platform/serial_interface/src/serial_interface.c 

OBJS += \
./platform/serial_interface/src/serial_interface.o 

C_DEPS += \
./platform/serial_interface/src/serial_interface.d 


# Each subdirectory must supply rules for building sources it contributes
platform/serial_interface/src/%.o: ../platform/serial_interface/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/inc" -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/app/hdr" -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/drv/hdr" -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/myLib/hdr" -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/platform/hdr" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


