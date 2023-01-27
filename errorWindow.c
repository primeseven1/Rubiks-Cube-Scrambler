#include "errorWindow.h"

void errorWindowExit(LPCSTR errorType, LPCSTR errorInfo)
{
	MessageBoxA(NULL, errorInfo, errorType, MB_OK | MB_ICONERROR);
	exit(EXIT_FAILURE);
}