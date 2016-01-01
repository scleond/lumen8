################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3

ORDERED_OBJS += \
"./clk_lumen8.obj" \
"./i2c_lumen8.obj" \
"./isl29125.obj" \
"./lumen8.obj" \
"./main.obj" \
"./msp432_startup_ccs.obj" \
"./printf.obj" \
"./tsl2561.obj" \
"./uart_lumen8.obj" \
"../msp432p401r.cmd" \
"S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/ccs/msp432p4xx_driverlib.lib" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
lumen.out \

EXE_OUTPUTS__QUOTED += \
"lumen.out" \

BIN_OUTPUTS += \
lumen.hex \

BIN_OUTPUTS__QUOTED += \
"lumen.hex" \


# All Target
all: lumen.out

# Tool invocations
lumen.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP432 Linker'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off -z -m"lumen.map" --heap_size=1024 --stack_size=512 -i"S:/ti/ccsv6/ccs_base/arm/include" -i"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/lib" -i"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="lumen_linkInfo.xml" --rom_model -o "lumen.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

lumen.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP432 Hex Utility'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armhex"  -o "lumen.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "clk_lumen8.pp" "i2c_lumen8.pp" "isl29125.pp" "lumen8.pp" "main.pp" "msp432_startup_ccs.pp" "printf.pp" "tsl2561.pp" "uart_lumen8.pp" 
	-$(RM) "clk_lumen8.obj" "i2c_lumen8.obj" "isl29125.obj" "lumen8.obj" "main.obj" "msp432_startup_ccs.obj" "printf.obj" "tsl2561.obj" "uart_lumen8.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

