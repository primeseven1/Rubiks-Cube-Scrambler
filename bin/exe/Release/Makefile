# O2 compiler optimizations + static linking and the windows subsystem

CC := gcc -c
CCPP := g++ -c
LINK := gcc
INCLUDE_DIR := ../../../include
LINK_DEPENDENCIES = -L../../link_dependencies/SFML -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main -lstdc++
LINK_FLAGS := -O2 -o scrambler.exe
SRC_DIR = ../../../src
CPP_FLAGS = -DSFML_STATIC -std=c++17 -I$(INCLUDE_DIR) -include $(SRC_DIR)/Precompiled_Headers/pch.h
OBJ_FILES = main.o window.o scrambleText.o scrambler.o valid.o skewbScramble.o pyraminxScramble.o megaminxScramble.o clockScramble.o scrambleInfo.o threeScramble.o sevenScramble.o fiveScramble.o allocator.o errorWindow.o debugErrorWindow.o

all: obj
	$(LINK) $(OBJ_FILES) $(LINK_DEPENDENCIES) $(LINK_FLAGS)
	make clean

obj:
	$(CCPP) $(SRC_DIR)/main.cpp $(CPP_FLAGS)
	$(CCPP) $(SRC_DIR)/C++/Window/window.cpp $(CPP_FLAGS)
	$(CCPP) $(SRC_DIR)/C++/ScrambleText/scrambleText.cpp $(CPP_FLAGS)
	$(CC) $(SRC_DIR)/C/Scramblers/scrambler.c
	$(CC) $(SRC_DIR)/C/Scramblers/Valid/valid.c
	$(CC) $(SRC_DIR)/C/Scramblers/Side_Events/clockScramble.c $(SRC_DIR)/C/Scramblers/Side_Events/megaminxScramble.c $(SRC_DIR)/C/Scramblers/Side_Events/pyraminxScramble.c $(SRC_DIR)/C/Scramblers/Side_Events/skewbScramble.c
	$(CC) $(SRC_DIR)/C/Scramblers/Scramble_Info/scrambleInfo.c
	$(CC) $(SRC_DIR)/C/Scramblers/NxN/fiveScramble.c $(SRC_DIR)/C/Scramblers/NxN/sevenScramble.c $(SRC_DIR)/C/Scramblers/NxN/threeScramble.c
	$(CC) $(SRC_DIR)/C/Scramblers/allocator/allocator.c
	$(CC) $(SRC_DIR)/C/Error/errorWindow.c $(SRC_DIR)/C/Error/Debugging/DebugErrorWindow.c

clean:
	del -f *.o 