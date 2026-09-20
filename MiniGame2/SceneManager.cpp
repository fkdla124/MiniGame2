#include "SceneManager.h"
#include "TitleScene.h"

#include <windows.h>
#pragma comment(lib, "winmm.lib")

SceneManager SceneManager::instance;

SceneManager& SceneManager::GetInstance()
{
	return instance;
}

SceneManager::SceneManager() : nextScene(nullptr), isRunning(true)
{
	timeBeginPeriod(1);

	scene = new TitleScene;
	scene->OnInit();
}

SceneManager::~SceneManager()
{
	delete scene;

	timeEndPeriod(1);
}

void SceneManager::Run()
{
	// ExitScene에서 false 반환후 게임종료를 위해
	bool keepUpdate = scene->Update();
	
	if (keepUpdate == false)
		isRunning = false;

	if (nextScene)
	{
		scene->OnDestroy();
		delete scene;

		scene = nextScene;
		scene->OnInit();

		nextScene = nullptr;
	}
}

void SceneManager::LoadScene(BaseScene* nextScene)
{
	this->nextScene = nextScene;
}

bool SceneManager::IsRunning()
{
	return isRunning;
}