cmake_minimum_required(VERSION 3.3)
project(LeetCodeCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Tree/ConvertSortedListToBinarySearchTree.cpp Math/LexicographicalNumbers.cpp DynamicProgramming/Triangle.cpp "TwoPointer/ LinkedListCycleII.cpp" DynamicProgramming/GuessNumberHigherOrLowerII.cpp Math/SuperPow.cpp)
add_executable(leetCode ${SOURCE_FILES})