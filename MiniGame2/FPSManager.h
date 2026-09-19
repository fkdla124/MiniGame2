#pragma once

#include <windows.h>
#include <stdint.h>


class FPSManager
{
public:
	static FPSManager& GetInstance();

	inline static unsigned int currentLogicFPS = 0; // 현재 LogicFPS
	inline static unsigned int currentRenderFPS = 0; // 현재 RenderFPS
	inline static bool renderSkip = false; // 다음 프레임 RenderSkip 여부.
	inline static int fps = 100; // 목표 fps

	// int64_t GetTscPerFrame();
	void LimitFPS();
	void UpdateLogicFPS();
	void UpdateRenderFPS();

private:
	FPSManager();
	~FPSManager() = default;
	FPSManager(const FPSManager&) = delete;
	FPSManager& operator=(const FPSManager&) = delete;

	static FPSManager instance;

	int64_t tscPerFrame; // 목표 fps를 기반으로 계산된 프레임마다 주어진 tsc (QPC freq)

	LARGE_INTEGER freq; // QueryPerformanceFreq()

	LARGE_INTEGER frameReferenceTsc; // 매 프레임 시작점 tsc

	LARGE_INTEGER logicFPSReferenceTsc; // LogicFPS 카운팅용 기준 tsc (1초마다 갱신)
	LARGE_INTEGER renderFPSReferenceTsc; // RenderFPS 카운팅용 기준 tsc (1초마다 갱신)
};