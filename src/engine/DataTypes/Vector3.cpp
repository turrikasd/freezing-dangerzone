#include "Vector3.h"

std::ostream& operator << (std::ostream& os, const Vector3 v3)
{
	return os << "{" << "X:" << v3.x << "|Y:" << v3.y << "|Z:" << v3.z << "}";
}