#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_EI	__declspec(dllexport)
#else
#define ENGINE_EI	__declspec(dllimport)
#endif

#include <iostream>
#include <vector>

class ENGINE_EI Texture2D
{
	std::vector<unsigned char> red;
	std::vector<unsigned char> green;
	std::vector<unsigned char> blue;
};