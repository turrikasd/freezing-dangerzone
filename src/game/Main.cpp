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

	System* systemC = new System();
	error = systemC->Initialize(hInstance);

	// Cleanup
	systemC->Destroy();
	delete systemC;

	return error;
}