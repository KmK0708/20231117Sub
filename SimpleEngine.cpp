#include "SimpleEngine.h"
#include "World.h"

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

SimpleEngine::SimpleEngine()
{
	IsRunning = true;
}

SimpleEngine::~SimpleEngine()
{
}

void SimpleEngine::Init()
{
	// ���� (������â,�׷���â,����ī��...)
}

void SimpleEngine::Run()
{
	// ����
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
	// ����
}

void SimpleEngine::Stop()
{
	// ����
	IsRunning = false;
}
