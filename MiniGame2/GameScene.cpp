#include "GameScene.h"
#include "Player.h"
#include "Enemy.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

GameScene::GameScene() : 
	screenManager(ScreenManager::GetInstance()), objectManager(ObjectManager::GetInstance()),
	fpsManager(FPSManager::GetInstance()), timeManager(TimeManager::GetInstance()),
	sceneManager(SceneManager::GetInstance()) { }


bool GameScene::Update()
{
	// 로직에 쓰일 deltaTime 갱신
	timeManager.Update();

	// 로직 처리
	objectManager.Update();
	
	// 게임 클리어/오버 체크
	if (objectManager.CheckGameClear())
		sceneManager.LoadScene(new GameClearScene);
	if (objectManager.CheckGameOver())
		sceneManager.LoadScene(new GameOverScene);

	// 로직FPS
	fpsManager.UpdateLogicFPS();

	// 렌더 및 렌더FPS
	if (!fpsManager.renderSkip)
	{
		objectManager.Render();
		screenManager.Flip();
		fpsManager.UpdateRenderFPS();
	}

	// FPS 제한.
	fpsManager.LimitFPS();

	// Keep Update
	return true;
}

void GameScene::OnInit()
{	
	objectManager.CreateObject(new Player(ScreenManager::row / 4 * 3, ScreenManager::col / 2));
	objectManager.CreateObject(new Enemy(ScreenManager::row / 3 - 2, ScreenManager::col / 4 * 1));
	objectManager.CreateObject(new Enemy(ScreenManager::row / 3 - 4, ScreenManager::col / 4 * 2));
	objectManager.CreateObject(new Enemy(ScreenManager::row / 3 + 2, ScreenManager::col / 4 * 3));
}

void GameScene::OnDestroy()
{
	objectManager.Clear();
}