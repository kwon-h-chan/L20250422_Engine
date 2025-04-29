#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(const FVector2D& Invector);

	virtual ~APlayer();
	virtual void Tick() override;
};

