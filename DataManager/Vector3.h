// Header
// Vector data type consisting of three single precision floating point values

#include "stdafx.h"

struct DLLEI Vector3
{
	float x, y, z;

	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};