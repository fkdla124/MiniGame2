#pragma once

#include "ObjectManager.h"

class ScreenManager
{
public:
	static ScreenManager& GetInstance();
	void Flip();

	void DrawSprite(int row, int col, char sprite);
	void DrawStr(int row, int col, const char* str);

public:
	static constexpr int row = 24;
	static constexpr int col = 81;

private:
	ScreenManager() = default;
	~ScreenManager() = default;
	ScreenManager(const ScreenManager&) = delete;
	ScreenManager& operator=(const ScreenManager&) = delete;

private:
	char screen[row][col];

private:
	static ScreenManager instance;
};