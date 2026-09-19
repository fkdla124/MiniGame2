#pragma once

#include <windows.h>

class ConsoleManager
{
public:
	static ConsoleManager& GetInstance();

	void MoveCursor(SHORT x, SHORT y);

private:
	ConsoleManager();
	~ConsoleManager();
	ConsoleManager(const ConsoleManager&) = delete;
	ConsoleManager& operator=(const ConsoleManager&) = delete;

private:
	HANDLE hConsole;

private:
	static ConsoleManager instance;
};