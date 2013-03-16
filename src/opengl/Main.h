#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>

#ifdef OPENGL_EXPORTS
#define OPENGL_EI	__declspec(dllexport)
#else
#define	OPENGL_EI	__declspec(dllimport)
#endif

struct OPENGL_EI glStruct
{
};