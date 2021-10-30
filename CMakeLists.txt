cmake_minimum_required(VERSION 3.20)
project(matrix)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrix main.cpp matrix.cpp matrix.h powerMethod.cpp powerMethod.h matrixOperation.cpp matrixOperation.h usedPackage.h inversePowerMethod.cpp inversePowerMethod.h matrix_test.cpp matrix_test.h)
