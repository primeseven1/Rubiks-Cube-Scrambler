# Optimizations are disabled, using debugging versions of the SFML libraries, and not using static linking

CC := gcc -c
CCPP := g++ -c
LINK := gcc
INCLUDE_DIR := ../../../include
LINK_DEPENDENCIES = -L../../link_dependencies/SFML -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lstdc++
LINK_FLAGS := -o scrambler.exe
SRC_DIR = ../../../src
CPP_FLAGS = -std=c++17 -I$(INCLUDE_DIR) -include $(SRC_DIR)/Precompiled_Headers/pch.h
SRCS_C := $(wildcard $(SRC_DIR)/C/**/*.c) $(wildcard $(SRC_DIR)/C/**/**/*.c)
SRCS_CPP := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/C++/**/*.cpp) 
OBJ_C_FILES := $(patsubst %.c, %.o, $(notdir $(SRCS_C)))
OBJ_CPP_FILES := $(patsubst %.cpp, %.o, $(notdir $(SRCS_CPP)))

all: obj
	$(LINK) $(OBJ_CPP_FILES) $(OBJ_C_FILES) $(LINK_DEPENDENCIES) $(LINK_FLAGS)
	make clean

obj: 
	$(CC) $(SRCS_C)
	$(CCPP) $(CPP_FLAGS) $(SRCS_CPP)

clean:
	del -f *.o 