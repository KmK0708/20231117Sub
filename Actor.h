#pragma once
class AActor
{
public:
		AActor();
		virtual ~AActor();
		// 액터의 기능 정의
		// int X, Y;
		// BeginPlay();
		virtual void BeginPlay() = 0;
		// Tick();
		virtual void Tick() = 0;
		// Render();
		virtual void Render() = 0;
		// 함수에 = 0 붙이면 순수 가상함수가 됨
		// 순수 가상함수는 구현부가 없음
		// 순수 가상함수를 하나라도 가지고 있는 클래스는
		// 추상 클래스가 됨
		// 추상 클래스는 객체를 만들 수 없음

};

