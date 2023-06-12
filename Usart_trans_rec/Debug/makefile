################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Usart_trans_rec.lss \

FLASH_IMAGE += \
Usart_trans_rec.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Usart_trans_rec.elf secondary-outputs

# Tool invocations
Usart_trans_rec.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Usart_trans_rec.map -mmcu=atmega32 -o "Usart_trans_rec.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Usart_trans_rec.lss: Usart_trans_rec.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Usart_trans_rec.elf  >"Usart_trans_rec.lss"
	@echo 'Finished building: $@'
	@echo ' '

Usart_trans_rec.hex: Usart_trans_rec.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Usart_trans_rec.elf  "Usart_trans_rec.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Usart_trans_rec.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Usart_trans_rec.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Usart_trans_rec.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
