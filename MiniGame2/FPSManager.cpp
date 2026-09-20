#include <stdint.h>
#include <thread>
#include <chrono>

#include "FPSManager.h"

FPSManager FPSManager::instance;

FPSManager& FPSManager::GetInstance()
{
	return instance;
}

#pragma warning(disable:26495) // 생성자 멤버 미초기화 경고 제거.
FPSManager::FPSManager()
{
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&frameReferenceTsc);
	QueryPerformanceCounter(&logicFPSReferenceTsc);
	QueryPerformanceCounter(&renderFPSReferenceTsc);

	// 목표 FPS에 맞는 프레임당 주어진 TSC 계산.
	tscPerFrame = static_cast<int64_t>((static_cast<double>(1000) / fps) * (freq.QuadPart / 1000));
}
#pragma warning(default:26495)

void FPSManager::LimitFPS()
{
	LARGE_INTEGER currTsc;
	QueryPerformanceCounter(&currTsc);

	int64_t deltaTsc;
	deltaTsc = currTsc.QuadPart - frameReferenceTsc.QuadPart;

	// 고정 timestep
	frameReferenceTsc.QuadPart += tscPerFrame;

	if (deltaTsc >= tscPerFrame * 2)
		renderSkip = true;
	else
		renderSkip = false;

	if (tscPerFrame - deltaTsc > 0)
		std::this_thread::sleep_for(std::chrono::nanoseconds((tscPerFrame - deltaTsc) * (1000000000 / freq.QuadPart)));
}

void FPSManager::UpdateLogicFPS()
{
	static int logicFPSCount = 0;
	
	logicFPSCount++;

	LARGE_INTEGER currTsc;
	QueryPerformanceCounter(&currTsc);

	int64_t deltaTsc;
	deltaTsc = currTsc.QuadPart - logicFPSReferenceTsc.QuadPart;

	if (deltaTsc >= 1 * freq.QuadPart)
	{
		logicFPSReferenceTsc.QuadPart += 1 * freq.QuadPart;
		currentLogicFPS = logicFPSCount;
		logicFPSCount = 0;
	}
}

void FPSManager::UpdateRenderFPS()
{
	static int renderFPSCount = 0;

	renderFPSCount++;

	LARGE_INTEGER currTsc;
	QueryPerformanceCounter(&currTsc);

	int64_t deltaTsc;
	deltaTsc = currTsc.QuadPart - renderFPSReferenceTsc.QuadPart;

	if (deltaTsc >= 1 * freq.QuadPart)
	{
		renderFPSReferenceTsc.QuadPart += 1 * freq.QuadPart;
		currentRenderFPS = renderFPSCount;
		renderFPSCount = 0;
	}
}