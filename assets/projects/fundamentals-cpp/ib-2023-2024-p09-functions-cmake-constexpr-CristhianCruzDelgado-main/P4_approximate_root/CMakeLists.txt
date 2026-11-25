# Bachelor's Degree in Computer Engineering
# Subject: Informática Básica 2023-2024
# Year: 1st
# Lab assignment 9: functions 2
#
# Author: Cristhian Adoney Cruz Delgado
# Email: alu0101648293@ull.edu.es
# Date: 21/11/2024
# File CMakelist.txt: build script.
# Description: cmake
#
# Build process:
#   1. cd xxx
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make

cmake_minimum_required(VERSION 3.1)

# set the project name
project(approximate_root
    VERSION 1.0
    DESCRIPTION "A simple CMake project for approximate root"
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
add_executable(approximate_root
    src/tools.h
    src/tools.cc
    src/approximate_root.cc)

# Add expected compiler features to a target.
target_compile_features(approximate_root PRIVATE cxx_std_17)

# Add compile options to a target.
target_compile_options(approximate_root PRIVATE -Wall -Wextra -Wpedantic -Weffc++)
