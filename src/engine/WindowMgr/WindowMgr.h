#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_EI __declspec(dllexport)
#else
#define ENGINE_EI __declspec(dllimport)
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Engine.h"
#include "OpenGL.h"

class ENGINE_EI WindowMgr
{
public:
	int Initialize(HINSTANCE applicationInstance);
	void Destroy();
	int Run();

	LRESULT CALLBACK MessageHandler(HWND mHwnd, UINT mMessage, WPARAM mWparam, LPARAM mLparam);

private:
	int SetupWindows(int& screenWidth, int& screenHeight);
	void DestroyWindows();
	int Frame();

private:
	HINSTANCE hInstance;
	WNDCLASSEX windowClass;
	HWND hWnd;
	char* applicationTitle;
	MSG msg;
	bool done;

	OpenGLClass* openGL;
	InputClass* input;
	GraphicsClass* graphics;
};

// Function Prototypes
static LRESULT CALLBACK WndProc(HWND wHwnd, UINT wMessage, WPARAM wWparam, LPARAM wLparam);

// Globals
static WindowMgr* Handle;