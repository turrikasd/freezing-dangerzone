#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_EI __declspec(dllexport)
#else
#define ENGINE_EI __declspec(dllimport)
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "../ErrorHandling/ErrorDefinitions.h"

LRESULT CALLBACK WndProc(HWND wHwnd, UINT wMessage, WPARAM wWparam, LPARAM wLparam);

class ENGINE_EI WindowMgr
{
public:
	int Initialize(HINSTANCE applicationInstance);
	void Destroy();
	int Run();

private:
	int SetupWindow();

	HINSTANCE hInstance;
	WNDCLASSEX windowClass;
	HWND hWnd;
	MSG msg;
	bool done;
};