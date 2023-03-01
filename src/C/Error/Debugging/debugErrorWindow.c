#include "debugErrorWindow.h"

void wrongFunctionCall(LPCSTR functionName)
{
	// Parts of the error message
	const char error1[] = "The wrong function was called, the function will not continue to execute.\n\nYou can continue, but there may be problems\nContinue?\n\nFunction name: ";
	char* fullError = (char*)malloc(strlen(error1) + strlen(functionName) + 1);

	// Worst case senario basically
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
	// All parts of the error message
	const char error1[] = "Memory allocation failure. \n\nFunction Name: ";
	const char error2[] = "\n\nVariable name: ";
	const char error3[] = "\n\nYou can continue, but the program will not work as expected\nContinue?";
	char* fullError = (char*)malloc(strlen(error1) + strlen(error2) + strlen(error3) +
									strlen(functionName) + strlen(variableName) + 1);

	if (!fullError) exit(-3);

	// Adding all of the error information and the parts of the message together
	strcpy_s(fullError, strlen(error1) + 1, error1);
	strcat_s(fullError, strlen(fullError) + strlen(functionName) + 1, functionName);
	strcat_s(fullError, strlen(fullError) + strlen(error2) + 1, error2);
	strcat_s(fullError, strlen(fullError) + strlen(variableName) + 1, variableName);
	strcat_s(fullError, strlen(fullError) + strlen(error3) + 1, error3);

	// Since this is not a fatal error, they have the option to exit or not
	if (MessageBoxA(NULL, fullError, "Memory Allocation Failure", MB_YESNO | MB_ICONERROR) == IDYES)
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