#include "TimeManager.h"
#include "FPSManager.h"

TimeManager TimeManager::instance;

TimeManager& TimeManager::GetInstance()
{
	return instance;
}

TimeManager::TimeManager()
{
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&gameReferenceTsc);
}

// 매 프레임 deltaTime 업데이트
void TimeManager::Update()
{
	LARGE_INTEGER currTsc;
	QueryPerformanceCounter(&currTsc);

	int64_t deltaTsc = currTsc.QuadPart - gameReferenceTsc.QuadPart;
	deltaTime = static_cast<float>(deltaTsc) / freq.QuadPart;

	gameReferenceTsc.QuadPart = currTsc.QuadPart;
}