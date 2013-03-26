// Game.cpp : Defines the entry point for the console application.
//

#include "Main.h"

using namespace std;

void HoldExec()
{
	int a;
	std::cin >> a;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int nShowCmd)
{
	int error;

	WindowMgr* windowMgr = new WindowMgr();
	error = windowMgr->Initialize(hInstance);

	if (!(error == NOERROR))
	{
		DisplayError(error);
	}

	// Clean
	windowMgr->Destroy();
	delete windowMgr;

	return 0;
}