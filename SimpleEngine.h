#pragma once
class UWorld;


class SimpleEngine
{
	public:
	SimpleEngine();
	virtual ~SimpleEngine();
	void Init();
	void Run();
	void Term();

	void Stop();

	inline UWorld* GetWorld() const { return World; }

protected:
	UWorld* World;
	bool IsRunning;
};

