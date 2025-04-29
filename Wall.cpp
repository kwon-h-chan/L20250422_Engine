#include "Wall.h"

AWall::AWall()
{
	Shape = '*';
	RenderOrder = 9;
	Color.r = 255;
	Color.g = 255;
	Color.b = 0;
	Color.a = 0;
	Filename = "wall.bmp";

	Load();
}

AWall::AWall(const FVector2D& InVector)
{
	Shape = '*';
	Location = InVector;
	RenderOrder = 9;
	Color.r = 255;
	Color.g = 255;
	Color.b = 0;
	Color.a = 0;
	Filename = "wall.bmp";

	Load();
}

AWall::~AWall()
{
}
