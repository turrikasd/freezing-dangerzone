#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_EI	__declspec(dllexport)
#else
#define	ENGINE_EI	__declspec(dllimport)
#endif

#include <iostream>

struct ENGINE_EI Vector3
{
	float x, y, z;

	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	friend std::ostream& operator << (std::ostream& os, const Vector3 v3);
};

std::ostream& operator << (std::ostream& os, const Vector3 v3)
{
	return os << "{" << "X:" << v3.x << "|Y:" << v3.y << "|Z:" << v3.z << "}";
}