#include <iostream>
#include "Actor.h"
#include "SimpleEngine.h"
#include "SDL.h"

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <iostream>

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

using namespace std;

#pragma region 연산자오버로딩

class KJY
{
public:
	KJY(int NewMoney) { Money = NewMoney; }
	virtual ~KJY() {}
	int Money;

	// 오퍼레이터 오버로딩 (연산자 오버로딩)
	bool operator > (const KJY& RHS) const
	{
		return this-> Money > RHS.Money;
	}
	bool operator < (const KJY& RHS) const
	{
		return this->Money < RHS.Money;
	}
};

int compare(const KJY& LHS, const KJY& RHS)
{
	if (LHS.Money > RHS.Money)
	{
		return true;
	}
	else
	{
		return false;
	}

}
#pragma endregion


int SDL_main(int argc, char* argv[])
{
#pragma region sort를 이용한 정렬방식

	//vector<KJY> KJYs;
	//KJYs.push_back(KJY(20));
	//KJYs.push_back(KJY(110));
	//KJYs.push_back(KJY(70));
	//KJYs.push_back(KJY(30));

	// 정렬
	//sort(KJYs.begin(), KJYs.end(), less<KJY>());

	// Compare 함수를 만들어서 정렬
	//sort(KJYs.begin(), KJYs.end(), compare);

	// 람다 함수를 이용한 정렬
	//sort(KJYs.begin(), KJYs.end(), [](const KJY& LHS, const KJY& RHS)
	//{
	//	return LHS.Money > RHS.Money;
	//});

	//for (const auto& Data : KJYs)
	//{
	//	cout << Data.Money << endl;
	//}
	//cout << (KJYs[1] > KJYs[2]) << endl;
#pragma endregion

	SimpleEngine* SEngine = SimpleEngine::GetInstance();
	

	SEngine->LoadLevel("Data/level01.smap");
	SEngine->Run();

	delete SEngine;


	return 0;
}