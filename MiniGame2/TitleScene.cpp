#include "GameOverScene.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "ExitScene.h"

TitleScene::TitleScene() :
	screenManager(ScreenManager::GetInstance()), objectManager(ObjectManager::GetInstance()),
	fpsManager(FPSManager::GetInstance()), timeManager(TimeManager::GetInstance()),
	sceneManager(SceneManager::GetInstance()) {}

bool TitleScene::Update()
{
	// 로직에 쓰일 deltaTime 갱신
	timeManager.Update();

	// 로직 및 로직FPS 처리.
	if (GetAsyncKeyState('1') & 0x00000001 && GetAsyncKeyState('1') & 0x80000000)
	{
		sceneManager.LoadScene(new GameScene);
	}
	if (GetAsyncKeyState('Q') & 0x00000001 && GetAsyncKeyState('Q') & 0x80000000)
	{
		sceneManager.LoadScene(new ExitScene);
	}
	objectManager.Update();
	fpsManager.UpdateLogicFPS();

	// 렌더 및 렌더FPS
	if (!fpsManager.renderSkip)
	{
		objectManager.Render();
		screenManager.DrawStr(ScreenManager::row / 3, ScreenManager::col / 2 - (static_cast<int>(strlen("== Mini Shooting Game ==")) / 2), "== Mini Shooting Game ==");
		screenManager.DrawStr(ScreenManager::row / 3 + 2, ScreenManager::col / 2 - (static_cast<int>(strlen("Start Game : 1") / 2)), "Start Game : 1");
		screenManager.DrawStr(ScreenManager::row / 3 + 4, ScreenManager::col / 2 - (static_cast<int>(strlen("Quit : q")) / 2), "Quit : q");
		screenManager.Flip();
		fpsManager.UpdateRenderFPS();
	}

	// FPS 제한.
	fpsManager.LimitFPS();

	// Keep Update
	return true;
}