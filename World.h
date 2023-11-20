#pragma once
#include <vector>
#include "Actor.h"

class UWorld
{
public:
	UWorld();
	virtual	~UWorld();

	void SpawnActor(AActor* NewActor);

	void Tick(int KeyCode);

	void Render();

	void SortRenderOrder();

	const std::vector<AActor*>& GetAllActors()
	{
		return Actors;
	}

protected:
	std::vector<AActor*> Actors;
};

