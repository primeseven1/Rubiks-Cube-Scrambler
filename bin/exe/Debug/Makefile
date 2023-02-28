# Optimizations are disabled, using debugging versions of the SFML libraries, and not using static linking

COMPILE_C := gcc -c
COMPILE_CPP := g++ -c
LINK := gcc
INCLUDE_DIR := ../../../include
LINK_DEPENDENCIES = -L../../link_dependencies/SFML -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lstdc++
LINK_FLAGS := -o scrambler.exe
SRC_FOLDER = ../../../src
CPP_FLAGS = -DSFML_STATIC -std=c++17 -I$(INCLUDE_DIR) -include $(SRC_FOLDER)/Precompiled_Headers/pch.h
OBJ_FILES = main.o window.o scrambleText.o scrambler.o valid.o skewbScramble.o pyraminxScramble.o megaminxScramble.o clockScramble.o scrambleInfo.o threeScramble.o sevenScramble.o fiveScramble.o allocator.o errorWindow.o debugErrorWindow.o

all: obj
	$(LINK) $(OBJ_FILES) $(LINK_DEPENDENCIES) $(LINK_FLAGS)
	make clean

obj:
	$(COMPILE_CPP) $(SRC_FOLDER)/main.cpp $(CPP_FLAGS)
	$(COMPILE_CPP) $(SRC_FOLDER)/C++/Window/window.cpp $(CPP_FLAGS)
	$(COMPILE_CPP) $(SRC_FOLDER)/C++/ScrambleText/scrambleText.cpp $(CPP_FLAGS)
	$(COMPILE_C) $(SRC_FOLDER)/C/Scramblers/scrambler.c
	$(COMPILE_C) $(SRC_FOLDER)/C/Scramblers/Valid/valid.c
	$(COMPILE_C) $(SRC_FOLDER)/C/Scramblers/Side_Events/clockScramble.c $(SRC_FOLDER)/C/Scramblers/Side_Events/megaminxScramble.c $(SRC_FOLDER)/C/Scramblers/Side_Events/pyraminxScramble.c $(SRC_FOLDER)/C/Scramblers/Side_Events/skewbScramble.c
	$(COMPILE_C) $(SRC_FOLDER)/C/Scramblers/Scramble_Info/scrambleInfo.c
	$(COMPILE_C) $(SRC_FOLDER)/C/Scramblers/NxN/fiveScramble.c $(SRC_FOLDER)/C/Scramblers/NxN/sevenScramble.c $(SRC_FOLDER)/C/Scramblers/NxN/threeScramble.c
	$(COMPILE_C) $(SRC_FOLDER)/C/Scramblers/allocator/allocator.c
	$(COMPILE_C) $(SRC_FOLDER)/C/Error/errorWindow.c $(SRC_FOLDER)/C/Error/Debugging/DebugErrorWindow.c

clean:
	del -f *.o 