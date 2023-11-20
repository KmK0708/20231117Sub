#pragma once
class AActor
{
public:
		AActor();
		AActor(int NewX, int NewY);
		virtual ~AActor();
		// ������ ��� ����
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

		// �÷��̾ ���� �΋H���°�
		bool bCollideWithWall = false;

protected:
	int X;
	int Y;


	char Shape;
	char WallShape;

		// �Լ��� = 0 ���̸� ���� �����Լ��� ��
		// ���� �����Լ��� �����ΰ� ����
		// ���� �����Լ��� �ϳ��� ������ �ִ� Ŭ������
		// �߻� Ŭ������ ��
		// �߻� Ŭ������ ��ü�� ���� �� ����

};

