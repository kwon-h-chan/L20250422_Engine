#include "Engine.h"
#include "World.h"
#include "Input.h"

UEngine::UEngine()// : World(nullptr)
{
	World = nullptr;
	InputDevice = nullptr;
}

UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Initialize()
{
	InputDevice = new UInput();
	World = new UWorld();
}

void UEngine::Run()
{
	while (true)
	{
		Input();
		Tick();
		Render();
	}
}

void UEngine::Terminate()
{
	if (World)
	{
		delete World;
		World = nullptr;
	}
	if (InputDevice)
	{
		delete InputDevice;
		InputDevice = nullptr;
	}
	
}

void UEngine::Input()
{
	InputDevice->Tick();
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}
