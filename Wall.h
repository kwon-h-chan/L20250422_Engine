#pragma once
#include "Actor.h"
#include "Vector2D.h"

class AWall : public AActor
{
public:

	AWall();
	AWall(const FVector2D& InVector);
	virtual ~AWall();
};

