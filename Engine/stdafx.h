// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

#ifdef DLL
#define DLLEI __declspec(dllexport)
#else
#define DLLEI __declspec(dllimport)
#endif

#include "DataManager.h"