#include "SceneManager.h"
#include "TitleScene.h"

#include <windows.h>
#pragma comment(lib, "winmm.lib")

SceneManager SceneManager::instance;

SceneManager& SceneManager::GetInstance()
{
	return instance;
}

SceneManager::SceneManager() : nextScene(nullptr)
{
	timeBeginPeriod(1);

	scene = new TitleScene;

	isRunning = true;
}

SceneManager::~SceneManager()
{
	delete scene;
}

void SceneManager::Run()
{
	bool keepUpdate = scene->Update();
	
	if (keepUpdate == false)
		isRunning = false;

	if (nextScene)
	{
		delete scene;
		scene = nextScene;
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