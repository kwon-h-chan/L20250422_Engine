#include <iostream>
#include "Engine.h"

using namespace std;

int main()
{
	UEngine* Engine = new UEngine();

	Engine->Initialize();
	Engine->Run();

	return 0;
}