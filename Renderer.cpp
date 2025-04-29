#include "Renderer.h"
#include "Engine.h"
#include "Actor.h"

URenderer* URenderer::Instance = nullptr;

URenderer::URenderer()
{
	ScreenHandles[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenHandles[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CurrentScreenIndex = 0;

	Renderer = SDL_CreateRenderer(GEngine->MyWindow, nullptr);
}

URenderer::~URenderer()
{
	CloseHandle(ScreenHandles[0]);
	CloseHandle(ScreenHandles[1]);
	SDL_DestroyRenderer(Renderer);
}

URenderer* URenderer::GetInstance()
{
	if (!Instance)
	{
		Instance = new URenderer();
	}

	return Instance;
}

void URenderer::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenHandles[CurrentScreenIndex],
		' ', 100 * 40, COORD{ 0,0 }, &DW);

	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
	SDL_RenderClear(Renderer);
}

void URenderer::Render(const AActor* RenderObject)
{
	char Shapes[2] = { RenderObject->Shape, '\0' };
	SetConsoleCursorPosition(ScreenHandles[CurrentScreenIndex],
		COORD{ (short)RenderObject->Location.X,(short)RenderObject->Location.Y });

	WriteConsole(ScreenHandles[CurrentScreenIndex], Shapes, 1, NULL, NULL);

	//SDL_SetRenderDrawColor(Renderer,
	//	RenderObject->Color.r,
	//	RenderObject->Color.g,
	//	RenderObject->Color.b,
	//	RenderObject->Color.a);
	//SDL_RenderPoint(Renderer, (float)RenderObject->Location.X,
	//	(float)RenderObject->Location.Y);

	SDL_FRect Location= { RenderObject->Location.X * 30,
	RenderObject->Location.Y * 30,30,30 };

	//SDL_RenderFillRect(Renderer, &Location);

	SDL_RenderTexture(Renderer, RenderObject->Texture, nullptr, &Location);
}

void URenderer::Present()
{
	SetConsoleActiveScreenBuffer(ScreenHandles[CurrentScreenIndex]);

	CurrentScreenIndex++;
	CurrentScreenIndex %= 2;

	SDL_RenderPresent(Renderer);
}

