#pragma once
#include "Actor.h"
#include "Vector2D.h"

class AMonster : public AActor
{
public:
	AMonster();
	AMonster(const FVector2D& InVector);
	virtual ~AMonster();
};

