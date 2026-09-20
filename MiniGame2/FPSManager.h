#pragma once

#include <windows.h>
#include <stdint.h>


class FPSManager
{
public:
	static FPSManager& GetInstance();
	void LimitFPS();
	void UpdateLogicFPS();
	void UpdateRenderFPS();

public:
	inline static unsigned int currentLogicFPS = 0; // 현재 LogicFPS
	inline static unsigned int currentRenderFPS = 0; // 현재 RenderFPS
	inline static bool renderSkip = false; // 다음 프레임 RenderSkip 여부.
	inline static int fps = 100; // 목표 fps (변경가능)

private:
	FPSManager();
	~FPSManager() = default;
	FPSManager(const FPSManager&) = delete;
	FPSManager& operator=(const FPSManager&) = delete;

private:
	int64_t tscPerFrame; // 목표 fps를 기반으로 계산된 프레임마다 주어진 tsc (QPC freq)

private:
	LARGE_INTEGER freq; // QueryPerformanceFreq()
	LARGE_INTEGER frameReferenceTsc; // 매 프레임 시작점 기준 tsc

private:
	LARGE_INTEGER logicFPSReferenceTsc; // LogicFPS 카운팅용 기준 tsc (1초마다 갱신)
	LARGE_INTEGER renderFPSReferenceTsc; // RenderFPS 카운팅용 기준 tsc (1초마다 갱신)

private:
	static FPSManager instance;
};