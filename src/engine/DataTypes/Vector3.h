#pragma once

struct __declspec(dllexport) Vector3
{
	float x, y, z;

	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};