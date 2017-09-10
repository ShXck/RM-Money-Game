################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Buyer.cpp \
../src/Game.cpp \
../src/GameDataHandler.cpp \
../src/MoneyGame.cpp \
../src/util.cpp 

OBJS += \
./src/Buyer.o \
./src/Game.o \
./src/GameDataHandler.o \
./src/MoneyGame.o \
./src/util.o 

CPP_DEPS += \
./src/Buyer.d \
./src/Game.d \
./src/GameDataHandler.d \
./src/MoneyGame.d \
./src/util.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/marcelo/Documents/libs/rapidjson/include -I/home/marcelo/Desktop/rmlib/rmlib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


