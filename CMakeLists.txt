cmake_minimum_required(VERSION 3.17)
project(AbstarctVM)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)



add_executable(AbstarctVM
        ./src/IOperand.cpp
        ./src/main.cpp src/Utils.cpp src/OperandDerived.cpp src/Stack.cpp include/Stack.h src/Engine.cpp include/Engine.h src/Token.cpp include/Token.h)
