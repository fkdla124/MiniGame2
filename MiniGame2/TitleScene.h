#pragma once

#include "BaseScene.h"
#include "ScreenManager.h"
#include "FPSManager.h"
#include "ObjectManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

class TitleScene : public BaseScene
{
public:
	TitleScene();
	~TitleScene() override = default;

	bool Update() override;

private:
	ScreenManager& screenManager;
	ObjectManager& objectManager;
	FPSManager& fpsManager;
	TimeManager& timeManager;
	SceneManager& sceneManager;
};