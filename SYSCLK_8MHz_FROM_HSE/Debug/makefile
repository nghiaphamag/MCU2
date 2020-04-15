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
SYSCLK_8Mhz_FROM_HSE.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SYSCLK_8Mhz_FROM_HSE.list \

OBJCOPY_BIN += \
SYSCLK_8Mhz_FROM_HSE.bin \


# All Target
all: SYSCLK_8Mhz_FROM_HSE.elf secondary-outputs

# Tool invocations
SYSCLK_8Mhz_FROM_HSE.elf: $(OBJS) $(USER_OBJS) C:\9004060731\Study\ Case\MCU2\SYSCLK_8Mhz_FROM_HSE\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "SYSCLK_8Mhz_FROM_HSE.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\9004060731\Study Case\MCU2\SYSCLK_8Mhz_FROM_HSE\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SYSCLK_8Mhz_FROM_HSE.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SYSCLK_8Mhz_FROM_HSE.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SYSCLK_8Mhz_FROM_HSE.list"
	@echo 'Finished building: $@'
	@echo ' '

SYSCLK_8Mhz_FROM_HSE.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "SYSCLK_8Mhz_FROM_HSE.bin"
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
