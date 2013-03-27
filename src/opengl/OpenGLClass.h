#pragma once

#ifdef OPENGL_EXPORTS
#define OPENGL_EI __declspec(dllexport)
#else
#define OPENGL_EI __declspec(dllimport)
#endif

class OPENGL_EI OpenGLClass
{
	//TODO
};