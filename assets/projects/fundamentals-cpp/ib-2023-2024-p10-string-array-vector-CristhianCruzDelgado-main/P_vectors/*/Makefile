# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Bachelor's Degree in Computer Engineering
# Subject: Informática Básica 2023-2024
# Year: 1st
# Lab assignment 10: string, array and vector
#
# Author: Cristhian Adoney Cruz Delgado
# Email: alu0101648293@ull.edu.es
# Date: 28/11/2024
# File Makefile: build script.
# Description: makefile

CC = g++
CFLAGS = -I
TARGET = string_espacios
SRC = strings_main.cc strings.cc

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
