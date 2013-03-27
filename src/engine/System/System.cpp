#include "System.h"

int System::Initialize(HINSTANCE hInstance)
{
	int error;

	windowMgr = new WindowMgr();
	error = windowMgr->Initialize(hInstance);

	// If there was no error initializing, jump to the message loop. Else display the error
	if (error == NOERROR)
		error = windowMgr->Run();
	else
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