#pragma once

#include "BaseScene.h"

class SceneManager
{
public:
	static SceneManager& GetInstance();

	void Run();
	void LoadScene(BaseScene* nextScene);
	bool IsRunning();

private:
	SceneManager();
	~SceneManager();

private:
	BaseScene* scene;
	BaseScene* nextScene;

private:
	bool isRunning;

private:
	static SceneManager instance;
};