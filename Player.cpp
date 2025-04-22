#include "Player.h"
#include "Input.h"

APlayer::APlayer()
{
	Shape = 'P';
	Location.X = 1;
	Location.Y = 1;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	switch (UInput::KeyCode)
	{
	case 'w':
		AddActorWorldOffset(FVector2D(0, -1));
			break;
	case 's':
		AddActorWorldOffset(FVector2D(0, 1));
			break;
	case 'a':
		AddActorWorldOffset(FVector2D(-1, 0));
			break;
	case 'd':
		AddActorWorldOffset(FVector2D(1, 0));
			break;
	}
}
