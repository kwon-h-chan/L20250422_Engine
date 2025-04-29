#pragma once
#include "Actor.h"
#include "Vector2D.h"

class AFloor : public AActor
{
public:
	AFloor();
	AFloor(const FVector2D& InVector);
	virtual ~AFloor();
};

