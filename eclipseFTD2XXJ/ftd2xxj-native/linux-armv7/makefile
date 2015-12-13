################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: libftd2xxj-native.so

# Tool invocations
libftd2xxj-native.so: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L/usr/lib/jvm/java-7-openjdk-armhf/jre/lib/arm/client/ -L/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/jre/lib/arm/client -L../external -L"/home/pi/eclipseFTD2XXJ/ftd2xxj-native/external" -Xlinker --no-undefined -shared -Wl,-soname=libftd2xxj-native.so.2 -o "libftd2xxj-native.so" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(LIBRARIES) libftd2xxj-native.so
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
