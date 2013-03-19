// Game.cpp : Defines the entry point for the console application.
//

#include "Main.h"

using namespace std;

void HoldExec()
{
	int a;
	std::cin >> a;
}

int _tmain(int argc, _TCHAR* argv[])
{

	cout << Vector3(1, 1, 1) << endl;
	cout << Vector3::Zero() << endl;
	cout << Quaternion(1, 2, 3, 4) << endl;

	HoldExec();
	return 0;
}