#include "Player.h"
#include "Input.h"
#include "Engine.h"
#include "SDL3/SDL.h"

APlayer::APlayer()
{
	Shape = 'P';
	RenderOrder = 7;
	Color.r = 255;
	Color.g = 0;
	Color.b = 0;
	Color.a = 0;
	ColorKey = { 255,0,255,255 };
	Filename = "player.bmp";

	Load();
}
APlayer::APlayer(const FVector2D& Invector)
{
	Shape = 'P';
	Location = Invector;
	RenderOrder = 7;
	Color.r = 255;
	Color.g = 0;
	Color.b = 0;
	Color.a = 0;
	ColorKey = { 255,0,255,255 };
	Filename = "player.bmp";

	Load();
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	if (GEngine->Event.type == SDL_EVENT_KEY_DOWN)
	{
		switch (GEngine->Event.key.key)
		{
		case SDLK_W:
		case SDLK_UP:
			AddActorWorldOffset(FVector2D(0, -1));
			break;
		case SDLK_S:
		case SDLK_DOWN:
			AddActorWorldOffset(FVector2D(0, 1));
			break;
		case SDLK_A:
		case SDLK_LEFT:
			AddActorWorldOffset(FVector2D(-1, 0));
			break;
		case SDLK_D:
		case SDLK_RIGHT:
			AddActorWorldOffset(FVector2D(1, 0));
			break;
		}
	}
}
