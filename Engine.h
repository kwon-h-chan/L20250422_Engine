#pragma once
#include <string>
#include <SDL3/SDL.h>


class UWorld;
class UInput;

class UEngine
{
private:
	UEngine();
	static UEngine* Instance;

public:

	static UEngine* GetInstance()
	{
		if (!Instance)
		{
			Instance = new UEngine();
		}
		return Instance;
	}

	virtual ~UEngine();

	void Initialize(std::string filename = "level01.map");
	void Run();
	void Terminate();

	SDL_Window* MyWindow;
	SDL_Event Event;

private:
	void Input();
	void Tick();
	void Render();

	UWorld* World;
	UInput* InputDevice;
	bool IsRunning;
};

#define GEngine	UEngine::GetInstance()
