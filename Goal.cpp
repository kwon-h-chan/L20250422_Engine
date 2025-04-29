#include "Goal.h"

AGoal::AGoal()
{
	Shape = 'G';
	RenderOrder = 8;
	Color.r = 0;
	Color.g = 255;
	Color.b = 0;
	Color.a = 0;
	Filename = "goal.bmp";

	Load();
}

AGoal::AGoal(const FVector2D& InVector)
{
	Shape = 'G';
	Location = InVector;
	RenderOrder = 8;
	Color.r = 0;
	Color.g = 255;
	Color.b = 0;
	Color.a = 0;
	Filename = "goal.bmp";

	Load();
}

AGoal::~AGoal()
{
}
