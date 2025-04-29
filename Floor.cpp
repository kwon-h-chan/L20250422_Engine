#include "Floor.h"

AFloor::AFloor()
{
	Shape = ' ';
	RenderOrder = 10;
	Color.r = 255;
	Color.g = 255;
	Color.b = 255;
	Color.a = 0;
	Filename = "floor.bmp";

	Load();
}

AFloor::AFloor(const FVector2D& InVector)
{
	Shape = ' ';
	Location = InVector;
	RenderOrder = 10;
	Color.r = 255;
	Color.g = 255;
	Color.b = 255;
	Color.a = 0;
	Filename = "floor.bmp";

	Load();
}

AFloor::~AFloor()
{
}
