#include "System.h"

int System::Initialize(HINSTANCE hInstance)
{
	int error;

	windowMgr = new WindowMgr();
	error = windowMgr->Initialize(hInstance);

	if (!(error == NOERROR))
		DisplayError(error);

	return error;
}

void System::Destroy()
{
	windowMgr->Destroy();
	delete windowMgr;
}