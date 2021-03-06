#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_EI __declspec(dllexport)
#else
#define ENGINE_EI __declspec(dllimport)
#endif

#include "../ErrorHandling/Error.h"

class ENGINE_EI InputClass
{
public:

	int Initialize();

	bool IsKeyDown(char key);
	bool IsKeyUp(char key);

private:

	char keys[4096];
};