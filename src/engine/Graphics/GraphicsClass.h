#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_EI __declspec(dllexport)
#else
#define ENGINE_EI __declspec(dllimport)
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "OpenGL.h"
#include "../ErrorHandling/Error.h"

class ENGINE_EI GraphicsClass
{
public:

	int Initialize(OpenGLClass* openGL, HWND hWnd);
	void Destroy();
};