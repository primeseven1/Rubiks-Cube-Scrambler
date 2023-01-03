main: main.o cube.o
	gcc main.o cube.o -o cube.exe

main.o:
	gcc -c main.c

cube.o:
	gcc -c cube.c