#include <iostream>
#include <Windows.h>
#include "Engine.h"
#include <SDL3/SDL.h>
#pragma comment(lib,"SDL3")

using namespace std;

int main()
{
	GEngine->Initialize();
	GEngine->Run();

	return 0;
}