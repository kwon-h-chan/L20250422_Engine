#pragma once
struct FVector2D
{
	//FVector2D();
	FVector2D(int InX = 0, int InY = 0);
	virtual ~FVector2D();

	FVector2D& operator+(const FVector2D& RHS)
	{
		X += RHS.X;
		Y += RHS.Y;

		return *this;
	}

	int X;
	int Y;

};

