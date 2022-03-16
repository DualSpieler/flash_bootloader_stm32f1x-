################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../app/sys/src/startup_stm32.s 

C_SRCS += \
../app/sys/src/sys.c \
../app/sys/src/sysmem.c 

OBJS += \
./app/sys/src/startup_stm32.o \
./app/sys/src/sys.o \
./app/sys/src/sysmem.o 

C_DEPS += \
./app/sys/src/sys.d \
./app/sys/src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
app/sys/src/%.o: ../app/sys/src/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/sys/src/%.o: ../app/sys/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/inc" -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/app/hdr" -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/drv/hdr" -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/myLib/hdr" -I"D:/CB Learning/Bootloader/git/flash_bootloader_stm32f1x-/stubs/mcu_test_app/stm32_app1/platform/hdr" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


