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

	static Vector3 Vector3::Zero() { return Vector3(0.0f, 0.0f, 0.0f); }
	static Vector3 Vector3::One() { return Vector3(1.0f, 1.0f, 1.0f); }
	static Vector3 Vector3::Up() { return Vector3(0.0f, 1.0f, 0.0f); }
	static Vector3 Vector3::Down() { return Vector3(0.0f, -1.0f, 0.0f); }
	static Vector3 Vector3::Right() { return Vector3(1.0f, 0.0f, 0.0f); }
	static Vector3 Vector3::Left() { return Vector3(-1.0f, 0.0f, 0.0f); }
	static Vector3 Vector3::Forward() { return Vector3(0.0f, 0.0f, 1.0f); }
	static Vector3 Vector3::Back() { return Vector3(0.0f, 0.0f, -1.0f); }
};

std::ostream& operator << (std::ostream& os, const Vector3 v3)
{
	return os << "{" << "X:" << v3.x << "|Y:" << v3.y << "|Z:" << v3.z << "}";
}