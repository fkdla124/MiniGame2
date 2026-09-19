#pragma once

#include "BaseScene.h"
#include "ScreenManager.h"
#include "ObjectManager.h"
#include "FPSManager.h"
#include "TimeManager.h"

class GameScene : public BaseScene
{
public:
	GameScene();
	virtual ~GameScene() override;

	virtual bool Update() override;

private:
	ScreenManager& screenManager;
	ObjectManager& objectManager;
	FPSManager& fpsManager;
	TimeManager& timeManager;
};