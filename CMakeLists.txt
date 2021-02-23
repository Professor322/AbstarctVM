cmake_minimum_required(VERSION 3.17)
project(AbstarctVM)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)



add_executable(AbstarctVM
        ./src/IOperand.cpp
        ./src/main.cpp src/Utils.cpp src/OperandDerived.cpp)
