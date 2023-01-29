#include "errorWindow.h"
#include <string.h>

void loadFileError(const char* filePath)
{
	char error1[] = "There was an error loading file:\n\n";

	char* error = malloc(strlen(filePath) + strlen(error1) + 1);

	strcpy_s(error, strlen(error1) + 1, error1);
	strcat_s(error, strlen(error) + strlen(filePath) + 1, filePath);

	MessageBoxA(NULL, error, "File Loading Error", MB_OK | MB_ICONERROR);

	free(error);
	error = NULL;

	exit(EXIT_FAILURE);
}

int errorWindow(LPCSTR errorType, LPCSTR errorInfo)
{
	int error = MessageBoxA(NULL, errorInfo, errorType, MB_ABORTRETRYIGNORE | MB_ICONERROR);

	switch (error)
	{
		case IDABORT:
			exit(EXIT_FAILURE);
			break;

		case IDRETRY:
		case IGNORE:
			return error;
			break;
	}

	// Removes compiler warning, but if somehow the switch statement doesn't work, it just assums abort
	return IDABORT; 
}