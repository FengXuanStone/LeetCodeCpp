cmake_minimum_required(VERSION 3.3)
project(LeetCodeCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Math/FractionToRecurringDecimal.cpp Breadth-firstSearch/SurroundedRegions.cpp DynamicProgramming/DecodeWays.cpp)
add_executable(leetCode ${SOURCE_FILES})