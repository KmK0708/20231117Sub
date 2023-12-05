#include "Actor.h"
#include <windows.h>
#include <iostream>
#include "SimpleEngine.h"

AActor::AActor() :
	X(0), Y(0), Shape(' '), SortOrder(0), bCollide(false), Size(32)
{
	MySurface = nullptr;
	MyTexture = nullptr;
	bIsSprite = false;
	SpriteSizeX = 1;
	SpriteSizeY = 1;
	//X = 0;
	//Y = 0;
}

AActor::AActor(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
	Shape = ' ';
	SortOrder = 0;
	bCollide = false;
	Size = 32;
	MySurface = nullptr;
	MyTexture = nullptr;
	bIsSprite = false;
	SpriteSizeX = 1;
	SpriteSizeY = 1;
}

AActor::~AActor()
{
	SDL_DestroyTexture(MyTexture);
	SDL_FreeSurface(MySurface);
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	//현재 액터 위치에 모양 출력
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << Shape;

	//SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	//SDL_RenderDrawPoint(GEngine->MyRenderer, X, Y);
	//SDL_RenderFillRect(GEngine->MyRenderer, new SDL_Rect {X * Size, Y * Size, Size, Size });
	
	if (bIsSprite)
	{
	/*	SDL_RenderCopy(GEngine->MyRenderer,
			MyTexture,
			new SDL_Rect{ 0, 0, MySurface->w / SpriteSizeX, MySurface->h / SpriteSizeY },
			new SDL_Rect{ X * Size, Y * Size, Size, Size });*/
	}
	else
	{
		SDL_RenderCopy(GEngine->MyRenderer,
			MyTexture,
			nullptr,
			new SDL_Rect{ X * Size, Y * Size, Size, Size });
	}
}

void AActor::LoadBMP(std::string FileName, SDL_Color ColorKey)
{
	// SSD->RAM
	MySurface = SDL_LoadBMP(FileName.c_str());	// 이미지를 로드해서 MySurface에 저장
	
	SDL_SetColorKey(MySurface, SDL_TRUE, SDL_MapRGBA(MySurface->format, ColorKey.r, ColorKey.g, ColorKey.b, ColorKey.a));	// 투명색 지정

	// RAM->VRAM
	MyTexture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, MySurface);	// MySurface에 있는 이미지를 MyTexture에 저장


}

