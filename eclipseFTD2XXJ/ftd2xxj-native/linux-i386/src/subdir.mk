################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/device.c \
../src/deviceDescriptor.c \
../src/eeprom.c \
../src/error.c \
../src/ftd2xxj.c \
../src/logger.c \
../src/port.c \
../src/service.c 

OBJS += \
./src/device.o \
./src/deviceDescriptor.o \
./src/eeprom.o \
./src/error.o \
./src/ftd2xxj.o \
./src/logger.o \
./src/port.o \
./src/service.o 

C_DEPS += \
./src/device.d \
./src/deviceDescriptor.d \
./src/eeprom.d \
./src/error.d \
./src/ftd2xxj.d \
./src/logger.d \
./src/port.d \
./src/service.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/pi/eclipseFTD2XXJ/ftd2xxj-native/external/include -I/include -I/include/linux -O0 -Wall -c -fmessage-length=0 -fPIC -march=armv7-a -mfpu=vfp -mfloat-abi=hard -ftree-vectorize -Wno-psabi -pipe -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


