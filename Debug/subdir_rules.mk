################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
clk_lumen8.obj: ../clk_lumen8.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="S:/ti/ccsv6/ccs_base/arm/include" --include_path="S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/" --include_path="S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="S:/ti/ccsv6/ccs_base/arm/include/CMSIS" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="clk_lumen8.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

i2c_lumen8.obj: ../i2c_lumen8.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="S:/ti/ccsv6/ccs_base/arm/include" --include_path="S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/" --include_path="S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="S:/ti/ccsv6/ccs_base/arm/include/CMSIS" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="i2c_lumen8.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

isl29125.obj: ../isl29125.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="S:/ti/ccsv6/ccs_base/arm/include" --include_path="S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/" --include_path="S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="S:/ti/ccsv6/ccs_base/arm/include/CMSIS" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="isl29125.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

lumen8.obj: ../lumen8.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="S:/ti/ccsv6/ccs_base/arm/include" --include_path="S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/" --include_path="S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="S:/ti/ccsv6/ccs_base/arm/include/CMSIS" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="lumen8.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="S:/ti/ccsv6/ccs_base/arm/include" --include_path="S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/" --include_path="S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="S:/ti/ccsv6/ccs_base/arm/include/CMSIS" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

msp432_startup_ccs.obj: ../msp432_startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="S:/ti/ccsv6/ccs_base/arm/include" --include_path="S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/" --include_path="S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="S:/ti/ccsv6/ccs_base/arm/include/CMSIS" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="msp432_startup_ccs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

printf.obj: ../printf.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="S:/ti/ccsv6/ccs_base/arm/include" --include_path="S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/" --include_path="S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="S:/ti/ccsv6/ccs_base/arm/include/CMSIS" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="printf.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

tsl2561.obj: ../tsl2561.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="S:/ti/ccsv6/ccs_base/arm/include" --include_path="S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/" --include_path="S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="S:/ti/ccsv6/ccs_base/arm/include/CMSIS" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="tsl2561.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uart_lumen8.obj: ../uart_lumen8.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="S:/ti/ccsv6/ccs_base/arm/include" --include_path="S:/ti/msp430/MSPWare_2_00_00_41/driverlib/driverlib/MSP432P4xx/" --include_path="S:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="S:/ti/ccsv6/ccs_base/arm/include/CMSIS" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="uart_lumen8.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


