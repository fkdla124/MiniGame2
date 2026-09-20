#include "SceneManager.h"

int main()
{
	SceneManager& sceneManager = SceneManager::GetInstance();
	while (sceneManager.IsRunning())
	{
		sceneManager.Run();
	}

	return 0;
}