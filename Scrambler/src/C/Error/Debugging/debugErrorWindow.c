#include "debugErrorWindow.h"

void wrongFunctionCall(LPCSTR functionName)
{
	char error1[] = "The wrong function was called, the function will not continue to execute.\n\nContinue?\n\nFunction name: ";
	char* fullError = (char*)malloc(strlen(error1) + strlen(functionName) + 1);

	if (!fullError) exit(-3);

	// Adds the function name to the error message
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

void mallocFailure(LPCSTR functionName, LPCSTR variableName)
{
	char error1[] = "Memory allocation failure. \n\nFunction Name: ";
	char error2[] = "\n\nVariable name: ";
	char* fullError = (char*)malloc(strlen(error1) + strlen(error2) + 
									strlen(functionName) + strlen(variableName) + 1);

	if (!fullError) exit(-3);

	strcpy_s(fullError, strlen(error1) + 1, error1);
	strcat_s(fullError, strlen(fullError) + strlen(functionName) + 1, functionName);
	strcat_s(fullError, strlen(fullError) + strlen(error2) + 1, error2);
	strcat_s(fullError, strlen(fullError) + strlen(variableName) + 1, variableName);

	MessageBoxA(NULL, fullError, "Error", MB_OK | MB_ICONERROR);
}