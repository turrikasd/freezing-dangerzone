#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_EI	__declspec(dllexport)
#else
#define	ENGINE_EI	__declspec(dllimport)
#endif

#include <iostream>

struct ENGINE_EI Vector2
{
	float x, y;

	Vector2(float x, float y) : x(x), y(y) {}

	friend std::ostream& operator << (std::ostream& os, const Vector2 v2);
};

std::ostream& operator << (std::ostream& os, const Vector2 v2)
{
	return os << "{" << "X:" << v2.x << "|Y:" << v2.y << "}";
}