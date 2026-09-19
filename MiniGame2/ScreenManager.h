#pragma once

#include "ObjectManager.h"

class ScreenManager
{
public:
	static ScreenManager& GetInstance();
	void Flip();

	void DrawSprite(int row, int col, char sprite);
	void DrawStr(int row, int col, const char* str);

private:
	ScreenManager() = default;
	~ScreenManager() = default;
	ScreenManager(const ScreenManager&) = delete;
	ScreenManager& operator=(const ScreenManager&) = delete;

public:
	static constexpr int row = 24;
	static constexpr int col = 81;

private:
	char screen[row][col];

private:
	static ScreenManager instance;
};