#include "errorWindow.h"
#include <string.h>

void loadFileError(LPCSTR filePath)
{
	char error1[] = "There was an error loading file:\n\n";

	char* fullError = malloc(strlen(filePath) + strlen(error1) + 1);

	strcpy_s(fullError, strlen(error1) + 1, error1);
	strcat_s(fullError, strlen(fullError) + strlen(filePath) + 1, filePath);

	MessageBoxA(NULL, fullError, "File Loading Error", MB_OK | MB_ICONERROR);

	free(fullError);
	fullError = NULL;

	exit(-1);
}