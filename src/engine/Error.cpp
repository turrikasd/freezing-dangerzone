#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Error.h"
#include "ErrorDefinitions.h"

void DisplayError(int error)
{
	char* errorText;
	char* errorTitle;

	switch (error)
	{
	case REGISTER_WINDOW_CLASS_ERROR:
		errorText = "REGISTER_WINDOW_CLASS_ERROR";
		errorTitle = "ERROR: 0x0001";
		break;

	case INITIALIZE_WINDOW_ERROR:
		errorText = "INITIALIZE_WINDOW_ERROR";
		errorTitle = "ERROR: 0x0002";
		break;

	default:
		errorText = "Unknown Error";
		errorTitle = "ERROR: 0x0000";
		break;
	}

	MessageBox(NULL, errorText, errorTitle, MB_OK);
}