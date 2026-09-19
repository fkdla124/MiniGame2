#include "ConsoleManager.h"
#include "ScreenManager.h"

ConsoleManager ConsoleManager::instance;

ConsoleManager::ConsoleManager()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

ConsoleManager::~ConsoleManager()
{
	CloseHandle(hConsole);
}

ConsoleManager& ConsoleManager::GetInstance()
{
	return instance;
}

void ConsoleManager::MoveCursor(SHORT x, SHORT y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(hConsole, coord);
}