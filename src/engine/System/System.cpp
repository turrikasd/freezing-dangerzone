#include "System.h"

int System::Initialize(HINSTANCE hInstance)
{
	int error;

	windowMgr = new WindowMgr();
	error = windowMgr->Initialize(hInstance);

	// Check for error. Jump to message loop if no error initializing
	if (!(error == NOERROR))
		DisplayError(error);
	else
		error = windowMgr->Run();

	if (!(error == NOERROR)) // Check for error in the message loop
		DisplayError(error);

	return error;
}

void System::Destroy()
{
	// Shutdown and release everything that exists
	if (windowMgr)
	{
		windowMgr->Destroy();
		delete windowMgr;
	}
}