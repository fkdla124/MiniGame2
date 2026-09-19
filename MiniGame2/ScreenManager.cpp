#include <memory.h>
#include <iostream>
#include "ScreenManager.h"
#include "ObjectManager.h"
#include "ConsoleManager.h"
#include "FPSManager.h"

ScreenManager ScreenManager::instance;

ScreenManager& ScreenManager::GetInstance()
{
	return instance;
}

void ScreenManager::Flip()
{
	// 출력
	ConsoleManager::GetInstance().MoveCursor(0, 0);

	for (int i = 0; i < col + 1; i++)
	{
		std::cout << "=";
	}
	std::cout << std::endl;

	for (int i = 0; i < row; i++)
	{
		std::cout << "|";
		std::cout << screen[i];
		std::cout << "|" << std::endl;
	}

	for (int i = 0; i < col + 1; i++)
	{
		std::cout << "=";
	}
	std::cout << std::endl;

	printf("LogicFPS : %-5d\n", FPSManager::currentLogicFPS);
	printf("RenderFPS : %-5d\n", FPSManager::currentRenderFPS);
	printf("ObjectCount : %-5d\n", ObjectManager::objectCount);
	printf("HP:%d\n", ObjectManager::GetInstance().GetPlayerHP());
	

	// 화면 초기화.
	memset(screen, ' ', sizeof(screen));
	for (int i = 0; i < row; i++)
	{
		screen[i][col - 1] = '\0';
	}
}

void ScreenManager::DrawSprite(int row, int col, char sprite)
{
	if (row < 0 || row >= this->row || col < 0 || col >= (this->col - 1))
		return;

	screen[row][col] = sprite;
}

void ScreenManager::DrawStr(int row, int col, const char* str)
{
	if (row < 0 || row >= this->row || col < 0 || col >= (this->col - 1))
		return;

	while (*str != '\0')
	{
		screen[row][col] = *str;
		str++;
		col++;

		if (col >= (this->col - 1))
			break;
	}
}