#include "Monster.h"

AMonster::AMonster()
{
	Shape = 'M';
	RenderOrder = 6;
	Color.r = 0;
	Color.g = 0;
	Color.b = 255;
	Color.a = 0;
	Filename = "monster.bmp";

	Load();

}

AMonster::AMonster(const FVector2D& InVector)
{
	Shape = 'M';
	Location = InVector;
	RenderOrder = 6;
	Color.r = 0;
	Color.g = 0;
	Color.b = 255;
	Color.a = 0;
	Filename = "monster.bmp";

	Load();
}

AMonster::~AMonster()
{
}
