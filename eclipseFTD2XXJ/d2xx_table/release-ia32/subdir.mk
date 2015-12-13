################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../d2xx_debug.c \
../d2xx_init.c \
../d2xx_table.c 

OBJS += \
./d2xx_debug.o \
./d2xx_init.o \
./d2xx_table.o 

C_DEPS += \
./d2xx_debug.d \
./d2xx_init.d \
./d2xx_table.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -m32 -ansi -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


