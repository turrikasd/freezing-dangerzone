#include "Vector2.h"

std::ostream& operator << (std::ostream& os, const Vector2 v2)
{
	return os << "{" << "X:" << v2.x << "|Y:" << v2.y << "}";
}