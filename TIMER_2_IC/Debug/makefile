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
TIMER_2_IC.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
TIMER_2_IC.list \

OBJCOPY_BIN += \
TIMER_2_IC.bin \


# All Target
all: TIMER_2_IC.elf secondary-outputs

# Tool invocations
TIMER_2_IC.elf: $(OBJS) $(USER_OBJS) C:\Users\AD\Desktop\MCU-1_Course\MCU2\TIMER_2_IC\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "TIMER_2_IC.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\AD\Desktop\MCU-1_Course\MCU2\TIMER_2_IC\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="TIMER_2_IC.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

TIMER_2_IC.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "TIMER_2_IC.list"
	@echo 'Finished building: $@'
	@echo ' '

TIMER_2_IC.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "TIMER_2_IC.bin"
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
