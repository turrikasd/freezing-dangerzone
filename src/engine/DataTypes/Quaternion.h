#pragma once

#ifdef ENGINE_EXPORTS
#define	ENGINE_EI	__declspec(dllexport)
#else
#define	ENGINE_EI	__declspec(dllimport)
#endif

#include <iostream>

struct ENGINE_EI Quaternion
{
	float x, y, z, w;

	Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	friend std::ostream& operator << (std::ostream& os, const Quaternion q);
};

std::ostream& operator << (std::ostream& os, const Quaternion q)
{
	return os << "{" << "X:" << q.x << "|Y:" << q.y << "|Z:" << q.z << "|W:" << q.w << "}";
}