#pragma once

#include "BaseScene.h"
#include "ScreenManager.h"
#include "ObjectManager.h"
#include "FPSManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene() override = default;

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