#include "WindowMgr.h"

int WindowMgr::Initialize(HINSTANCE applicationInstance)
{
	hInstance = applicationInstance; // Save this in the class for later use

	int error, screenWidth, screenHeight;
	screenWidth = 0;
	screenHeight = 0;

	openGL = new OpenGLClass();
	if (!openGL)
		return OPENGLCLASS_INITIALIZE_ERROR;

	// Setup the window and init graphics API
	error = SetupWindows(screenWidth, screenHeight);
	if (!(error == NOERROR))
		return error;

	// Init Input and Graphics objects
	input = new InputClass();
	if (!input)
		return INPUTCLASS_INITIALIZE_ERROR;

	error = input->Initialize();
	if (!(error == NOERROR))
		return error;

	graphics = new GraphicsClass();
	if (!graphics)
		return GRAPHICSCLASS_INITIALIZE_ERROR;

	error = graphics->Initialize(openGL, hWnd); // No need to check for error as it will be returned anyways

	return error;
}

void WindowMgr::Destroy()
{
	// Shutdown and release everything that exists
	if (graphics)
	{
		graphics->Destroy();
		delete graphics;
	}

	if (input)
	{
		delete input;
	}

	if (openGL)
	{
		//openGL->Destroy();
		delete openGL;
	}

	DestroyWindows();
}

int WindowMgr::SetupWindows(int& screenWidth, int& screenHeight)
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
						  applicationTitle, // Title
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

void WindowMgr::DestroyWindows()
{
}

int WindowMgr::Frame()
{
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
			error = Frame();
			if (!(error == NOERROR))
				done = true;
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