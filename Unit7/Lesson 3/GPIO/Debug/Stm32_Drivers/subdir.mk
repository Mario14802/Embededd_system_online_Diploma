################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_Drivers/Stm32_GPIO_driver.c 

OBJS += \
./Stm32_Drivers/Stm32_GPIO_driver.o 

C_DEPS += \
./Stm32_Drivers/Stm32_GPIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_Drivers/Stm32_GPIO_driver.o: ../Stm32_Drivers/Stm32_GPIO_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/MARIO/OneDrive/Desktop/Learn in depth/Unit 7/Lesson 3/GPIO/Stm32_Drivers" -I"C:/Users/MARIO/OneDrive/Desktop/Learn in depth/Unit 7/Lesson 3/GPIO/Stm32_Drivers/inc" -I"C:/Users/MARIO/OneDrive/Desktop/Learn in depth/Unit 7/Lesson 3/GPIO/Stm32_Drivers" -I"C:/Users/MARIO/OneDrive/Desktop/Learn in depth/Unit 7/Lesson 3/GPIO/Stm32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_Drivers/Stm32_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

