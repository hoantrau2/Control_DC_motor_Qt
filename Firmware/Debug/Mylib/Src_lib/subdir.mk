################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mylib/Src_lib/PID.c \
../Mylib/Src_lib/PWM.c \
../Mylib/Src_lib/crc16.c \
../Mylib/Src_lib/encoder.c \
../Mylib/Src_lib/uart_proto.c 

OBJS += \
./Mylib/Src_lib/PID.o \
./Mylib/Src_lib/PWM.o \
./Mylib/Src_lib/crc16.o \
./Mylib/Src_lib/encoder.o \
./Mylib/Src_lib/uart_proto.o 

C_DEPS += \
./Mylib/Src_lib/PID.d \
./Mylib/Src_lib/PWM.d \
./Mylib/Src_lib/crc16.d \
./Mylib/Src_lib/encoder.d \
./Mylib/Src_lib/uart_proto.d 


# Each subdirectory must supply rules for building sources it contributes
Mylib/Src_lib/%.o Mylib/Src_lib/%.su Mylib/Src_lib/%.cyclo: ../Mylib/Src_lib/%.c Mylib/Src_lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/BTL_Embedded_System/Firmware/Mylib" -I"E:/BTL_Embedded_System/Firmware/Mylib/Inc_lib" -I"E:/BTL_Embedded_System/Firmware/Mylib/Src_lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Mylib-2f-Src_lib

clean-Mylib-2f-Src_lib:
	-$(RM) ./Mylib/Src_lib/PID.cyclo ./Mylib/Src_lib/PID.d ./Mylib/Src_lib/PID.o ./Mylib/Src_lib/PID.su ./Mylib/Src_lib/PWM.cyclo ./Mylib/Src_lib/PWM.d ./Mylib/Src_lib/PWM.o ./Mylib/Src_lib/PWM.su ./Mylib/Src_lib/crc16.cyclo ./Mylib/Src_lib/crc16.d ./Mylib/Src_lib/crc16.o ./Mylib/Src_lib/crc16.su ./Mylib/Src_lib/encoder.cyclo ./Mylib/Src_lib/encoder.d ./Mylib/Src_lib/encoder.o ./Mylib/Src_lib/encoder.su ./Mylib/Src_lib/uart_proto.cyclo ./Mylib/Src_lib/uart_proto.d ./Mylib/Src_lib/uart_proto.o ./Mylib/Src_lib/uart_proto.su

.PHONY: clean-Mylib-2f-Src_lib

