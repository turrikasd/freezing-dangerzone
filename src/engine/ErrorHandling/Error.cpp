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

	case OPENGLCLASS_INITIALIZE_ERROR:
		errorText = "OPENGLCLASS_INITIALIZE_ERROR";
		errorTitle = "ERROR: 0x0100";
		break;

	case INPUTCLASS_INITIALIZE_ERROR:
		errorText = "INPUTCLASS_INITIALIZE_ERROR";
		errorTitle = "ERROR: 0x0003";
		break;

	case GRAPHICSCLASS_INITIALIZE_ERROR:
		errorText = "GRAPHICSCLASS_INITIALIZE_ERROR";
		errorTitle = "ERROR: 0x0004";
		break;

	case USER_ESCAPE_DURING_FRAME_DRAW:
		errorText = "USER_ESCAPE_DURING_FRAME_DRAW";
		errorTitle = "ERROR: 0x0005";
		break;

	default:
		errorText = "Unknown Error";
		errorTitle = "ERROR: 0x0000";
		break;
	}

	MessageBox(NULL, errorText, errorTitle, MB_OK);
}