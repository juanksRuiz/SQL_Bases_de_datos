################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ArbolB.cpp \
../Tabla.cpp \
../Tupla.cpp \
../prueba.cpp 

OBJS += \
./ArbolB.o \
./Tabla.o \
./Tupla.o \
./prueba.o 

CPP_DEPS += \
./ArbolB.d \
./Tabla.d \
./Tupla.d \
./prueba.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


