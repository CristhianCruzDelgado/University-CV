# Bachelor's Degree in Computer Engineering
# Subject: Informática Básica 2023-2024
# Year: 1st
# Lab assignment 9: functions, CMake and constexpr
#
# Author: Cristhian Adoney Cruz Delgado
# Email: alu0101648293@ull.edu.es
# Date: 21/11/2024
# File CMakelist.txt: build script.
# Description: cmake
#
# Build process:
#   1. cd P1_scalar_product
#   2. mkdir doc
#   3. mkdir build
#   4. cd build
#   5. cmake ..
#   6. make

cmake_minimum_required(VERSION 3.1)

# set the project name
project(scalar_product
    VERSION 1.0
    DESCRIPTION "A simple CMake project for calculate scalar product"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic -Weffc++")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "xxx" to be built from the source files listed in the command invocation.
add_executable(scalar_product
    src/scalar_product.cc)

# Add expected compiler features to a target.
target_compile_features(scalar_product PRIVATE cxx_std_17)

# Add compile options to a target.
target_compile_options(scalar_product PRIVATE -Wall -Wextra -Wpedantic -Weffc++)
