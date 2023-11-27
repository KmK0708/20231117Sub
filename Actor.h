#pragma once
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY);
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	//accessor
	inline int GetX() const { return X; }
	inline int GetY() const { return Y; }

	inline void SetX(int NewX) { X = NewX; }
	inline void SetY(int NewY) { Y = NewY; }

	virtual bool operator<(const AActor& RHS) const
	{
		return this->SortOrder < RHS.SortOrder;
	}

	virtual bool operator>(const AActor& RHS) const
	{
		return this->SortOrder > RHS.SortOrder;
	}

	int SortOrder;
	bool bCollide;

protected:
	int X;
	int Y;

	char Shape;
};


		// 함수에 = 0 붙이면 순수 가상함수가 됨
		// 순수 가상함수는 구현부가 없음
		// 순수 가상함수를 하나라도 가지고 있는 클래스는
		// 추상 클래스가 됨
		// 추상 클래스는 객체를 만들 수 없음
