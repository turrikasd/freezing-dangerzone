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

	System* systemMgr = new System();
	error = systemMgr->Initialize(hInstance);

	// Cleanup
	systemMgr->Destroy();
	delete systemMgr;

	return error;
}