cmake_minimum_required(VERSION 3.3)
project(LeetCodeCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES LinkedList/ReverseLinkedList.cpp Math/PowerOfThree.cpp BitManipulation/PowerOfTwo.cpp BitManipulation/NumberOf1Bits.cpp)
add_executable(leetCode ${SOURCE_FILES})