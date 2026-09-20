#pragma once

#include "BaseScene.h"
#include "ScreenManager.h"
#include "FPSManager.h"
#include "ObjectManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

class GameClearScene: public BaseScene
{
public:
	GameClearScene();
	~GameClearScene() override = default;

	void OnInit() override;
	void OnDestroy() override;

	bool Update() override;

private:
	ScreenManager& screenManager;
	ObjectManager& objectManager;
	FPSManager& fpsManager;
	TimeManager& timeManager;
	SceneManager& sceneManager;
};