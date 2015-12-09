################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include external/include/linux/subdir.mk
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
all: libftd2xxj.so

# Tool invocations
libftd2xxj.so: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L../external -L/usr/lib/jvm/java-7-openjdk-armhf/jre/lib/arm/client/ -Wl -Xlinker --no-undefined -shared -Wl,-soname=libftd2xxj.so.2 -o "libftd2xxj.so" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(LIBRARIES) libftd2xxj.so
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
