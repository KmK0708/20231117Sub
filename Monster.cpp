#include "Monster.h"

AMonster::AMonster()
{
	X = 10;
	Y = 10;
	Shape = 'M';
	SortOrder = 300;
}

AMonster::AMonster(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	X = NewX;
	Y = NewY;
	SortOrder = NewSortOrder;
}

AMonster::~AMonster()
{
}
