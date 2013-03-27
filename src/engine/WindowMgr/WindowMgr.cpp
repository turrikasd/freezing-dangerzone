#include "WindowMgr.h"

int WindowMgr::Initialize(HINSTANCE applicationInstance)
{
	int error, screenWidth, screenHeight;

	screenWidth = 0;
	screenHeight = 0;

	hInstance = applicationInstance;

	error = SetupWindow();
	return error;
}

void WindowMgr::Destroy()
{
	// Todo
}

int WindowMgr::SetupWindow()
{
	// Fill window class for DefaultWindow
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = NULL;
	windowClass.cbWndExtra = NULL;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = NULL; // TODO
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = "DefaultWindow";
	windowClass.hIconSm = NULL; // TODO

	if (!RegisterClassEx(&windowClass))
		return REGISTER_WINDOW_CLASS_ERROR;

	// Drive a window from the DefaultWindow class
	hWnd = CreateWindowEx(NULL,
						  "DefaultWindow", // Window Class
						  "Game Window", // Title
						  WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU, // Style
						  100, 100, // Position
						  800, 600, // Dimensions
						  NULL,
						  NULL,
						  hInstance,
						  NULL);

	if (!hWnd)
		return INITIALIZE_WINDOW_ERROR;
	
	return NOERROR;
}

int WindowMgr::Run()
{
	int error = NOERROR;
	done = false; // Init loop condition bool

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			// error = Frame();
			// if (!(error == NOERROR))
			//	done = true;
		}
	}

	return error;
}

LRESULT CALLBACK WindowMgr::MessageHandler(HWND mHwnd, UINT mMessage, WPARAM mWparam, LPARAM mLparam)
{
	return 0;
}

LRESULT CALLBACK WndProc(HWND wHwnd, UINT wMessage, WPARAM wWparam, LPARAM wLparam)
{
	PAINTSTRUCT paintStruct;
	HDC hDC; // Device Context
	char string[] = "Test string of the doom from the hell";

	switch (wMessage)
	{
	case WM_CREATE: // Window is being created
		return 0;
		break;

	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
		break;

	case WM_PAINT:
		hDC = BeginPaint(wHwnd, &paintStruct);
		SetTextColor(hDC, COLORREF(0x000000FF));
		TextOut(hDC, 150, 150, string, sizeof(string)-1);
		EndPaint(wHwnd, &paintStruct);
		return 0;
		break;
	}

	// Handle messages that we skipped
	return DefWindowProc(wHwnd, wMessage, wWparam, wLparam);
}