#include "InputClass.h"

int InputClass::Initialize()
{
	return NOERROR;
}

bool InputClass::IsKeyDown(char key)
{
	return keys[key];
}

bool InputClass::IsKeyUp(char key)
{
	return !(keys[key]);
}