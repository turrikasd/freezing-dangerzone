#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Engine.h"

LRESULT CALLBACK WndProc(HWND wHwnd, UINT wMessage, WPARAM wWparam, LPARAM wLparam);

class WindowMgr
{
public:
	int Initialize(HINSTANCE applicationInstance);
	void Destroy();
	

private:
	int SetupWindow();
	int WindowLoop();

	HINSTANCE hInstance;
	WNDCLASSEX windowClass;
	HWND hWnd;
	MSG msg;
	bool done;
};