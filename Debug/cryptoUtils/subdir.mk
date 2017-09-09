################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../cryptoUtils/BigInteger.cc \
../cryptoUtils/BigIntegerUtils.cc \
../cryptoUtils/BigUnsigned.cc \
../cryptoUtils/BigUnsignedInABase.cc 

CPP_SRCS += \
../cryptoUtils/CryptGenRandom.cpp \
../cryptoUtils/PaillierUtils.cpp 

CC_DEPS += \
./cryptoUtils/BigInteger.d \
./cryptoUtils/BigIntegerUtils.d \
./cryptoUtils/BigUnsigned.d \
./cryptoUtils/BigUnsignedInABase.d 

OBJS += \
./cryptoUtils/BigInteger.o \
./cryptoUtils/BigIntegerUtils.o \
./cryptoUtils/BigUnsigned.o \
./cryptoUtils/BigUnsignedInABase.o \
./cryptoUtils/CryptGenRandom.o \
./cryptoUtils/PaillierUtils.o 

CPP_DEPS += \
./cryptoUtils/CryptGenRandom.d \
./cryptoUtils/PaillierUtils.d 


# Each subdirectory must supply rules for building sources it contributes
cryptoUtils/%.o: ../cryptoUtils/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cryptoUtils/%.o: ../cryptoUtils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


