################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
USART2_Example.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
USART2_Example.list \

OBJCOPY_BIN += \
USART2_Example.bin \


# All Target
all: USART2_Example.elf secondary-outputs

# Tool invocations
USART2_Example.elf: $(OBJS) $(USER_OBJS) C:\9004060731\Study\ Case\MCU2\USART2_Example\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "USART2_Example.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\9004060731\Study Case\MCU2\USART2_Example\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="USART2_Example.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

USART2_Example.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "USART2_Example.list"
	@echo 'Finished building: $@'
	@echo ' '

USART2_Example.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "USART2_Example.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
