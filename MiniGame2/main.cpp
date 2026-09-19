#include "SceneManager.h"
#include "ConsoleManager.h"
#include "ScreenManager.h"

int main()
{
	SceneManager& sceneManager = SceneManager::GetInstance();
	while (sceneManager.IsRunning())
	{
		sceneManager.Run();
	}

	return 0;
}