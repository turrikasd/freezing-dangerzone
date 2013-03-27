#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_EI __declspec(dllexport)
#else
#define ENGINE_EI __declspec(dllimport)
#endif

class ENGINE_EI GraphicsClass
{
public:

	int Initialize();
	void Destroy();
};