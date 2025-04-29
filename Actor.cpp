#include <iostream>
#include "Windows.h"
#include "Actor.h"
#include "Renderer.h"
#include "SDL3/SDL.h"


AActor::AActor()
{
	//Shape = ' ';
	ColorKey = { 255,255,255,255 };
}

AActor::AActor(const FVector2D& InVector)
{
	Location = InVector;
	ColorKey = { 255,255,255,255 };
}

AActor::~AActor()
{
}

void AActor::AddActorWorldOffset(FVector2D offset)
{
	Location.X += offset.X;
	Location.Y += offset.Y;
}

void AActor::Tick()
{
}

void AActor::Render()
{
	/*COORD Position = { (SHORT)Location.X, (SHORT)Location.Y };

	SetConsoleCursorPosition(GetStdHandle
	(STD_OUTPUT_HANDLE), Position);

	std::cout << Shape;*/

	URenderer* URender = URenderer::GetInstance();
	URender->Render(this);
}

void AActor::Load()
{
	if (Filename.size() > 0)
	{
		std::string Temp = "./data/" + Filename;
		Surface = SDL_LoadBMP(Temp.c_str()); //RAM
		const SDL_PixelFormatDetails* pixelDetails =
			SDL_GetPixelFormatDetails(Surface->format);

		SDL_SetSurfaceColorKey(Surface, true, SDL_MapRGB(pixelDetails, nullptr,
			ColorKey.r, ColorKey.g, ColorKey.a));

		Texture = SDL_CreateTextureFromSurface
		(URenderer::GetInstance()->Renderer, Surface); //VRAM
	}
}

bool AActor::CompareByRenderOrder(const AActor* A, const AActor* B)
{
	return (A->RenderOrder) > (B->RenderOrder);
}