#pragma once
#include <string>
#include "Vector2D.h"
#include "SDL3/SDL.h"

class AActor
{
public:
	AActor();
	AActor(const FVector2D& InVector);
	virtual ~AActor();

	void AddActorWorldOffset(FVector2D offset);
	FVector2D Location;

	virtual void Tick();
	virtual void Render();

	void Load();

	char Shape;
	int RenderOrder = 0;

	static bool CompareByRenderOrder(const AActor* A, const AActor* B);

	SDL_Color Color;
	SDL_Color ColorKey;

	std::string Filename;
	SDL_Surface* Surface;
	SDL_Texture* Texture;
};

class ActorCompareByRenderOrder
{
public:
	bool operator()(const AActor* A, const AActor* B)
	{
		return (A->RenderOrder > B->RenderOrder);
	}
};

