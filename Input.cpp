#include "Input.h"
#include "Windows.h"
#include "conio.h"

int UInput::KeyCode;

UInput::UInput()
{
}

UInput::~UInput()
{
}

void UInput::Tick()
{
	if (_kbhit())
	{
		KeyCode = _getch();
	}
	else
	{
		KeyCode = 0;
	}
}
