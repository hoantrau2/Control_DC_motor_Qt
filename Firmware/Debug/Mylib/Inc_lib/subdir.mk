################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mylib/Inc_lib/PID.c \
../Mylib/Inc_lib/PWM.c \
../Mylib/Inc_lib/crc16.c \
../Mylib/Inc_lib/encoder.c \
../Mylib/Inc_lib/uart_proto.c 

OBJS += \
./Mylib/Inc_lib/PID.o \
./Mylib/Inc_lib/PWM.o \
./Mylib/Inc_lib/crc16.o \
./Mylib/Inc_lib/encoder.o \
./Mylib/Inc_lib/uart_proto.o 

C_DEPS += \
./Mylib/Inc_lib/PID.d \
./Mylib/Inc_lib/PWM.d \
./Mylib/Inc_lib/crc16.d \
./Mylib/Inc_lib/encoder.d \
./Mylib/Inc_lib/uart_proto.d 


# Each subdirectory must supply rules for building sources it contributes
Mylib/Inc_lib/%.o Mylib/Inc_lib/%.su Mylib/Inc_lib/%.cyclo: ../Mylib/Inc_lib/%.c Mylib/Inc_lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/FileCode_STM32/Embed_System_BTL/Mylib/Inc_lib" -I"E:/FileCode_STM32/Embed_System_BTL/Mylib" -I"E:/FileCode_STM32/Embed_System_BTL/Mylib/Src_lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Mylib/Inc_lib/crc16.o: ../Mylib/Inc_lib/crc16.c Mylib/Inc_lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/FileCode_STM32/Embed_System_BTL/Mylib/Inc_lib" -I"E:/FileCode_STM32/Embed_System_BTL/Mylib" -I"E:/FileCode_STM32/Embed_System_BTL/Mylib/Src_lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Mylib-2f-Inc_lib

clean-Mylib-2f-Inc_lib:
	-$(RM) ./Mylib/Inc_lib/PID.cyclo ./Mylib/Inc_lib/PID.d ./Mylib/Inc_lib/PID.o ./Mylib/Inc_lib/PID.su ./Mylib/Inc_lib/PWM.cyclo ./Mylib/Inc_lib/PWM.d ./Mylib/Inc_lib/PWM.o ./Mylib/Inc_lib/PWM.su ./Mylib/Inc_lib/crc16.cyclo ./Mylib/Inc_lib/crc16.d ./Mylib/Inc_lib/crc16.o ./Mylib/Inc_lib/crc16.su ./Mylib/Inc_lib/encoder.cyclo ./Mylib/Inc_lib/encoder.d ./Mylib/Inc_lib/encoder.o ./Mylib/Inc_lib/encoder.su ./Mylib/Inc_lib/uart_proto.cyclo ./Mylib/Inc_lib/uart_proto.d ./Mylib/Inc_lib/uart_proto.o ./Mylib/Inc_lib/uart_proto.su

.PHONY: clean-Mylib-2f-Inc_lib

