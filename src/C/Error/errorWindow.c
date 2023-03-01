#include "errorWindow.h"
#include <string.h>

void loadFileError(LPCSTR filePath)
{
	const char error1[] = "There was an error loading file: ";
	const char error2[] = "\n\nThe program will now exit";

	char* fullError = (char*)malloc(strlen(filePath) + strlen(error1) + strlen(error2) + 1);

	if (!fullError) exit(-2);

	// Adds the file to the error information
	strcpy_s(fullError, strlen(error1) + 1, error1);
	strcat_s(fullError, strlen(fullError) + strlen(filePath) + 1, filePath);
	strcat_s(fullError, strlen(fullError) + strlen(error2) + 1, error2);

	MessageBoxA(NULL, fullError, "File Loading Error", MB_OK | MB_ICONERROR);

	free(fullError);
	fullError = NULL;

	exit(-1);
}