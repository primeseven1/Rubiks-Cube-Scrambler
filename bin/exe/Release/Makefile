# O2 compiler optimizations + static linking and the windows subsystem

CC := gcc -c
CCPP := g++ -c
LINK := gcc
INCLUDE_DIR := ../../../include
LINK_DEPENDENCIES = -L../../link_dependencies/SFML -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main -lstdc++
LINK_FLAGS := -O2 -o scrambler.exe
SRC_DIR = ../../../src
CPP_FLAGS = -DSFML_STATIC -std=c++17 -I$(INCLUDE_DIR) -include $(SRC_DIR)/Precompiled_Headers/pch.h
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