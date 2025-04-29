#include "World.h"
#include "Actor.h"
#include "Player.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"
#include "Monster.h"
#include "Renderer.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>


UWorld::UWorld()
{
	/*SpawnActor(new APlayer());
	SpawnActor(new AWall());

	AWall* NewWall = new AWall();
	NewWall->Location.X = 1;
	NewWall->Location.Y = 0;
	SpawnActor(NewWall);

	NewWall = new AWall();
	NewWall->Location.X = 2;
	NewWall->Location.Y = 0;
	SpawnActor(NewWall);*/

}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	URenderer::GetInstance()->Clear();
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
	URenderer::GetInstance()->Present();
}

void UWorld::Load(std::string filename)
{
	std::string str;
	std::ifstream file(filename);

	int X = 0;
	int Y = 0;

	while (!file.eof())
	{
		char Buf[100];
		file.getline(Buf,100);
		for (X=0; X<strlen(Buf); X++)
		{
			if (Buf[X] == '*')
			{
				SpawnActor(new AWall(FVector2D(X, Y)));
			}
			else if (Buf[X] == 'P')
			{
				SpawnActor(new APlayer(FVector2D(X, Y)));
			}
			else if (Buf[X] == 'G')
			{
				SpawnActor(new AGoal((FVector2D(X, Y))));
			}
			else if (Buf[X] == ' ')
			{
				//SpawnActor(new AFloor((FVector2D(X, Y))));
			}
			else if (Buf[X] == 'M')
			{
				SpawnActor(new AMonster((FVector2D(X, Y))));
			}
			SpawnActor(new AFloor((FVector2D(X, Y))));
		}
		Y++;
		
	}
	file.close();
	//lamda »ç¿ë
	std::sort(Actors.begin(), Actors.end(), [](const AActor* A, const AActor* B) {
		return (A->RenderOrder) > (B->RenderOrder);
		});
}

void UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void UWorld::DestroyActor(AActor* DestroyedActor)
{
	Actors.erase(find(Actors.begin(), Actors.end(),
		DestroyedActor));
}

std::vector<AActor*>& UWorld::GetAllActors()
{
	return Actors;
}
