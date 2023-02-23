#include "debugErrorWindow.h"

void wrongFunctionCall(LPCSTR functionName)
{
	char error1[] = "The wrong function was called, the function will not continue.\n\nContinue?\n\nFunction name: ";

	char* fullError = (char*)malloc(strlen(error1) + strlen(functionName) + 1);

	strcpy_s(fullError, strlen(error1) + 1, error1);
	strcat_s(fullError, strlen(fullError) + strlen(functionName) + 1, functionName);

	if (MessageBoxA(NULL, fullError, "Wrong Function Call", MB_ICONWARNING | MB_YESNO) == IDYES)
	{
		free(fullError);
		fullError = NULL;
		return;
	}
	else
	{
		free(fullError);
		fullError = NULL;
		exit(-2);
	}
}