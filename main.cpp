#include "scrambler.h"
#include "window.h"

int main()
{
	srand(time(0));

	Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Scrambler");
	return 0;
}