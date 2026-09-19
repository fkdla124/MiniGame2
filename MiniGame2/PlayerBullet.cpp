#include "PlayerBullet.h"
#include "FPSManager.h"
#include "ScreenManager.h"
#include "SceneManager.h"
#include "GameClearScene.h"
#include "Enemy.h"

PlayerBullet::PlayerBullet(int row, int col)
	: BaseObject(row, col, ObjectType::PlayerBullet), moveTimer(0), moveSpeed(25), damage(1) {}

void PlayerBullet::Update()
{
	// timer update
	moveTimer++;
	
	// move
	if (moveTimer >= (FPSManager::fps / moveSpeed))
	{
		if (row - 1 < 0)
		{
			destroy = true;
		}
		else
		{
			row--;
		}

		moveTimer = 0;
	}
}

void PlayerBullet::Render()
{
	ScreenManager& screenManager = ScreenManager::GetInstance();
	screenManager.DrawSprite(row, col, '|');
}

void PlayerBullet::OnCollision(BaseObject* object)
{
	ObjectType objectType = object->GetObjectType();

	switch (objectType)
	{
		case ObjectType::Enemy:
			destroy = true;
			static_cast<Enemy*>(object)->TakeDamage(damage);
			break;
	}

	if (ObjectManager::GetInstance().CheckGameClear())
	{
		SceneManager::GetInstance().LoadScene(new GameClearScene);
	}
}