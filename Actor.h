#pragma once
class AActor
{
public:
		AActor();
		AActor(int NewX, int NewY);
		virtual ~AActor();
		// 액터의 기능 정의
		// int X, Y;
		// BeginPlay();
		virtual void BeginPlay();
		// Tick();
		virtual void Tick(int KeyCode);
		// Render();
		virtual void Render();

		//Accessors (Getters and Setters)
		inline int GetX() const { return X; }
		inline int GetY() const { return Y; }

		inline void SetX(int NewX) { X = NewX; }
		inline void SetY(int NewY) { Y = NewY; }
		
		inline bool operator < (const AActor& RHS) const
		{
			return this->SortOrder < RHS.SortOrder;
		}

		int SortOrder;

		// 플레이어가 벽에 부딫혔는가
		bool bCollideWithWall = false;

protected:
	int X;
	int Y;


	char Shape;
	char WallShape;

		// 함수에 = 0 붙이면 순수 가상함수가 됨
		// 순수 가상함수는 구현부가 없음
		// 순수 가상함수를 하나라도 가지고 있는 클래스는
		// 추상 클래스가 됨
		// 추상 클래스는 객체를 만들 수 없음

};

