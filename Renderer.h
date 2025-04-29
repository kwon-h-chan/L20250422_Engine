#pragma once
#include <Windows.h>
#include "Vector2D.h"
#include "SDL3/SDL.h"

class AActor;

class URenderer
{
protected:
	URenderer();
	virtual ~URenderer();
	static URenderer* Instance;

	HANDLE ScreenHandles[2];
	int CurrentScreenIndex = 0;

public:
	static URenderer* GetInstance();

	SDL_Renderer* Renderer;

	void Clear();
	void Render(const AActor* RenderObject);
	void Present();
};

