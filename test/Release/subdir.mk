################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HD44780.c \
../adc.c \
../atkeyboard.c \
../gsm.c \
../lcd.c \
../main.c \
../menu.c \
../usart.c 

OBJS += \
./HD44780.o \
./adc.o \
./atkeyboard.o \
./gsm.o \
./lcd.o \
./main.o \
./menu.o \
./usart.o 

C_DEPS += \
./HD44780.d \
./adc.d \
./atkeyboard.d \
./gsm.d \
./lcd.d \
./main.d \
./menu.d \
./usart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


