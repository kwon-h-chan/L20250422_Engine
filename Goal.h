#pragma once
#include "Actor.h"
#include "Vector2D.h"

class AGoal : public AActor
{
public:
	AGoal();
	AGoal(const FVector2D& InVector);
	virtual ~AGoal();
};

