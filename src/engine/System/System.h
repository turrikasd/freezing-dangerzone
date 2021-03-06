#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_EI __declspec(dllexport)
#else
#define ENGINE_EI __declspec(dllimport)
#endif

#include "../WindowMgr/WindowMgr.h"
#include "../ErrorHandling/Error.h"

class ENGINE_EI System
{
public:
	int Initialize(HINSTANCE hInstance);
	void Destroy();

private:
	WindowMgr* windowMgr;
};