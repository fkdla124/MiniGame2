#pragma once

#include <windows.h>
#include <stdint.h>

class TimeManager
{
public:
	static TimeManager& GetInstance();

	void Update();

	inline static float deltaTime = 0.0f;

private:
	TimeManager();
	~TimeManager() = default;
	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;

private:
	LARGE_INTEGER gameReferenceTsc;
	LARGE_INTEGER freq;

private:
	static TimeManager instance;
};