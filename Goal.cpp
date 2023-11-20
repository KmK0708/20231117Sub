#include "Goal.h"

AGoal::AGoal()
{
	X = 10;
	Y = 10;
	Shape = 'G';
	SortOrder = 200;
}

AGoal::AGoal(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	X = NewX;
	Y = NewY;
	SortOrder = NewSortOrder;
}

AGoal::~AGoal()
{
}
