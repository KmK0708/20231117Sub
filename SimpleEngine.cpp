#include "SimpleEngine.h"
#include "World.h"
#include "Player.h"
#include "Wall.h"
#include "Monster.h"
#include "Goal.h"
#include "Floor.h"
#include <conio.h>

// * �� ���� �� �簢���� ���
//**********
//*P       *
//*        *
//*        *
//*     M  *
//*        *
//*        *
//*        *
//*       G*
//**********

SimpleEngine* SimpleEngine::Instance = nullptr;

SimpleEngine::SimpleEngine()
{
	Init();
}

SimpleEngine::~SimpleEngine()
{
	Term();
}

void SimpleEngine::Init()
{
	// ���� (������â,�׷���â,����ī��...)
	IsRunning = true;
	World = new UWorld();
}

void SimpleEngine::Run()
{
	// ����
	while (IsRunning)
	{
		int KeyCode = Input();
		Tick(KeyCode);
		// Clear Screen
		system("cls");
		Render();
	}
}

void SimpleEngine::Term()
{
	// ����
	IsRunning = false;
	delete World;
}

void SimpleEngine::Stop()
{
	// ����
	IsRunning = false;
}

void SimpleEngine::LoadLevel(std::string Filename)
{
	// Save
	// Memory -> Disk : Serialize , Text(JSon), Binary(Umap)

	// Load
	// Disk -> Memory : Deserialize

	std::string Maps[10] = {
		"**********",
		"*P       *",
		"*        *",
		"*        *",
		"*     M  *",
		"*        *",
		"*        *",
		"*        *",
		"*       G*",
		"**********",
	};
	// for�� 2���� 2���� �迭�� ��ȸ�ؼ� *�̸� ���� �����ϰ� P�̸� �÷��̾ ����
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (Maps[Y][X] == '*')
			{
				// �� ����
				GetWorld()->SpawnActor(new AWall(X, Y));

			}
			else if (Maps[Y][X] == 'P')
			{
				// �÷��̾� ����
				GetWorld()->SpawnActor(new APlayer(X, Y));
			}
			else if (Maps[Y][X] == 'M')
			{
				// ���� ����
				GetWorld()->SpawnActor(new AMonster(X, Y));
			}
			else if (Maps[Y][X] == 'G')
			{
				// �������� ����
				GetWorld()->SpawnActor(new AGoal(X, Y));
			}
			else if (Maps[Y][X] == ' ')
			{
				// ����� ����
				
			}
			// �ٴڻ���
			GetWorld()->SpawnActor(new AFloor(X, Y));

		}
	}

	//GetWorld()->SpawnActor(new APlayer(10, 10));
	//GetWorld()->SpawnActor(new AWall(0, 0));
	//GetWorld()->SpawnActor(new AWall(1, 0));
	//GetWorld()->SpawnActor(new AWall(0, 1));
	GetWorld()->SortRenderOrder();
}

int SimpleEngine::Input()
{
	// Ű����, ���콺, �����е�, ��Ʈ��ũ
	int KeyCode = _getch();

	return KeyCode;
}

void SimpleEngine::Tick(int KeyCode)
{
	GetWorld()->Tick(KeyCode);
}

void SimpleEngine::Render()
{
	GetWorld()->Render();
}

