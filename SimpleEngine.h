#pragma once
#include <vector>
#include <string>
class UWorld;
class AActor;

class SimpleEngine
{
	private:
	SimpleEngine();
	public:
	virtual ~SimpleEngine();
	void Init();

	void Run();

	void Term();

	void Stop();

	void LoadLevel(std::string Filename);

	inline UWorld* GetWorld() const { return World; }

	static SimpleEngine* GetInstance() 
	{
		if (Instance == nullptr)
		{
			Instance = new SimpleEngine();
		}
		return Instance; 
	}
	static int KeyCode;

protected:
	UWorld* World;
	bool IsRunning;
	
	int Input();
	void Tick(int KeyCode);
	void Render();

	static SimpleEngine* Instance;
};

#define GENGINE SimpleEngine::GetInstance()
