#include "SimpleEngine.h"
#include "World.h"
#include "Player.h"
#include "Wall.h"
#include "Monster.h"
#include "Goal.h"
#include "Floor.h"
#include <conio.h>

// * 로 안이 빈 사각형을 출력
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
	// 시작 (윈도우창,그래픽창,사운드카드...)
	IsRunning = true;
	World = new UWorld();
}

void SimpleEngine::Run()
{
	// 구동
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
	// 종료
	IsRunning = false;
	delete World;
}

void SimpleEngine::Stop()
{
	// 중지
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
	// for문 2개로 2차원 배열을 순회해서 *이면 벽을 생성하고 P이면 플레이어를 생성
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (Maps[Y][X] == '*')
			{
				// 벽 생성
				GetWorld()->SpawnActor(new AWall(X, Y));

			}
			else if (Maps[Y][X] == 'P')
			{
				// 플레이어 생성
				GetWorld()->SpawnActor(new APlayer(X, Y));
			}
			else if (Maps[Y][X] == 'M')
			{
				// 몬스터 생성
				GetWorld()->SpawnActor(new AMonster(X, Y));
			}
			else if (Maps[Y][X] == 'G')
			{
				// 골인지점 생성
				GetWorld()->SpawnActor(new AGoal(X, Y));
			}
			else if (Maps[Y][X] == ' ')
			{
				// 빈공간 생성
				
			}
			// 바닥생성
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
	// 키보드, 마우스, 게임패드, 네트워크
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

