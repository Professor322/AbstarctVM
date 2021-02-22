cmake_minimum_required(VERSION 3.17)
project(AbstarctVM)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)



add_executable(AbstarctVM
        ./src/IOperand.cpp)
