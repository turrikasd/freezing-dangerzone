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

	if (!(error == NOERROR))
		DisplayError(error);

	return error;
}

void System::Destroy()
{
	windowMgr->Destroy();
	delete windowMgr;
}