#include "Player.h"
#include "Actor.h"
#include "World.h"
#include "SimpleEngine.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 10;
	Y = 10;
	SortOrder = 500;
}

APlayer::APlayer(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	X = NewX;
	Y = NewY;
	SortOrder = NewSortOrder;
}

APlayer::~APlayer()
{
}

void APlayer::Tick(int KeyCode)
{
	AActor::Tick(KeyCode);
	// 또는 __super::Tick(KeyCode); 로도 사용 가능 이건 Vs에서만 사용 가능
	if (KeyCode == 'A' || KeyCode == 'a')
	{
		if (!IsCollide(X - 1,Y))
		{
			X--;
		}
		//GENGINE->GetWorld()->GetAllActors();
		//X--;	
	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}

	}

}

bool APlayer::IsCollide(int NewX, int NewY)
{
	for (const auto& Actor : GENGINE->GetWorld()->GetAllActors())
	{
		if (this == Actor)
		{
			continue;
		}
		if (Actor->bCollideWithWall == true && Actor->GetX() == NewX && Actor->GetY() == NewY)
		{
			return true;
		}
	}
	return false;
}
