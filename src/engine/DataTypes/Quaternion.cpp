#include "Quaternion.h"

std::ostream& operator << (std::ostream& os, const Quaternion q)
{
	return os << "{" << "X:" << q.x << "|Y:" << q.y << "|Z:" << q.z << "|W:" << q.w << "}";
}