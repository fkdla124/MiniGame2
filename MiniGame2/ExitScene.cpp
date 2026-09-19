#include "GameOverScene.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "ExitScene.h"
#include <conio.h>

ExitScene::ExitScene() :
	screenManager(ScreenManager::GetInstance()), objectManager(ObjectManager::GetInstance()),
	fpsManager(FPSManager::GetInstance()), timeManager(TimeManager::GetInstance()),
	sceneManager(SceneManager::GetInstance()) {}

bool ExitScene::Update()
{
	// 로직에 쓰일 deltaTime 갱신
	timeManager.Update();

	// 로직 및 로직FPS 처리.
	objectManager.Update();
	fpsManager.UpdateLogicFPS();

	// 렌더 및 렌더FPS
	if (!fpsManager.renderSkip)
	{
		objectManager.Render();
		screenManager.DrawStr(ScreenManager::row / 3, ScreenManager::col / 4, "             \"/\"");
		screenManager.DrawStr(ScreenManager::row / 3 + 1, ScreenManager::col / 4, "             /");
		screenManager.DrawStr(ScreenManager::row / 3 + 2, ScreenManager::col / 4, "       (^_^)/ ");
		screenManager.DrawStr(ScreenManager::row / 3 + 3, ScreenManager::col / 4, "         /|    Good bye~~");
		screenManager.DrawStr(ScreenManager::row / 3 + 4, ScreenManager::col / 4, "        / |");
		screenManager.DrawStr(ScreenManager::row / 3 + 5, ScreenManager::col / 4, "          |    Press any key to exit...");
		screenManager.DrawStr(ScreenManager::row / 3 + 6, ScreenManager::col / 4, "         / |");
		screenManager.DrawStr(ScreenManager::row / 3 + 7, ScreenManager::col / 4, "        /  |");
		screenManager.DrawStr(ScreenManager::row / 3 + 8, ScreenManager::col / 4, "       /   |");
		screenManager.Flip();
		fpsManager.UpdateRenderFPS();
	}

	// FPS 제한.
	fpsManager.LimitFPS();

	// 한 프레임만 수행 후 종료를 기다리기
	while (_kbhit())
		int c = _getch();

	if (_getch())
		return false;



	// 리턴 경고 제거용 실행되지 않는 곳.
	return true;
}