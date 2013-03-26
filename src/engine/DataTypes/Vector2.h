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

	static Vector2 Vector2::Zero() { return Vector2(0.0f, 0.0f); }
	static Vector2 Vector2::One() { return Vector2(1.0f, 1.0f); }
	static Vector2 Vector2::Up() { return Vector2(0.0f, 1.0f); }
	static Vector2 Vector2::Down() { return Vector2(0.0f, -1.0f); }
	static Vector2 Vector2::Right() { return Vector2(1.0f, 0.0f); }
	static Vector2 Vector2::Left() { return Vector2(-1.0f, 0.0f); }
};