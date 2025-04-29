#include "Engine.h"
#include "World.h"
#include "Input.h"
#include "Renderer.h"
#include <SDL3/SDL.h>

UEngine* UEngine::Instance = nullptr;

UEngine::UEngine()// : World(nullptr)
{
	World = nullptr;
	InputDevice = nullptr;
}

UEngine::~UEngine()
{
	Terminate();
	
}

void UEngine::Initialize(std::string filename)
{
	IsRunning = true;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	MyWindow = SDL_CreateWindow("Sample", 800, 600, SDL_WINDOW_OPENGL);

	InputDevice = new UInput();
	World = new UWorld();
	World->Load(filename);
	URenderer::GetInstance();
}

void UEngine::Run()
{
	while (IsRunning)
	{
		SDL_PollEvent(&Event);
		switch (Event.type)
		{
		case SDL_EVENT_QUIT:
			IsRunning = false;
			break;
		}

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
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
	
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
