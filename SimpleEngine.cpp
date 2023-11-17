#include "SimpleEngine.h"
#include "World.h"

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

SimpleEngine::SimpleEngine()
{
	IsRunning = true;
}

SimpleEngine::~SimpleEngine()
{
}

void SimpleEngine::Init()
{
	// 시작 (윈도우창,그래픽창,사운드카드...)
}

void SimpleEngine::Run()
{
	// 구동
	while (IsRunning)
	{
		// Input
		// Tick
		// Render
		//World;
	}
}

void SimpleEngine::Term()
{
	// 종료
}

void SimpleEngine::Stop()
{
	// 중지
	IsRunning = false;
}
