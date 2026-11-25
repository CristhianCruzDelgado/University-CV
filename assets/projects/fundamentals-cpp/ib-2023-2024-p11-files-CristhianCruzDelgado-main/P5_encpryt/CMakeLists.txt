# Bachelor's Degree in Computer Engineering
# Subject: Informática Básica 2023-2024
# Year: 1st
# Lab assignment 11: files
#
# Author: Cristhian Adoney Cruz Delgado
# Email: alu0101648293@ull.edu.es
# Date: 5/12/2024
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
project(crypto
    VERSION 1.0
    DESCRIPTION "A simple CMake project for encrypt"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic -Weffc++")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# The full set of flags for every build mode can be added here
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall -Wextra -Wpedantic \
           -Wshadow -Wnon-virtual-dtor -Wold-style-cast \
           -Wcast-align -Wunused -Woverloaded-virtual \
           -Wconversion -Wsign-conversion -Wnull-dereference \
           -Wdouble-promotion -Wformat=2 -Wmisleading-indentation \
           -Wduplicated-cond -Wduplicated-branches -Wlogical-op \
           -Wuseless-cast")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "crypto" to be built from the source files listed in the command invocation.
add_executable(crypto
    src/tools.h
    src/tools.cc
    src/crypto.cc)

# Add expected compiler features to a target.
target_compile_features(crypto PRIVATE cxx_std_23)

# Add compile options to a target.
target_compile_options(crypto PRIVATE
    -std=c++23
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wconversion
    -Wsign-conversion
    -Wnull-dereference
    -Wdouble-promotion
    -Wformat=2
    -Wmisleading-indentation
    -Wduplicated-cond
    -Wduplicated-branches
    -Wlogical-op
    -Wuseless-cast
)
