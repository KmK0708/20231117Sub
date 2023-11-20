#include "Wall.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	SortOrder = 100;
	bCollideWithWall = true;
}

AWall::AWall(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
	bCollideWithWall = true;
}

AWall::~AWall()
{
}
