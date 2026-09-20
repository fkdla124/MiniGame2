#include "EnemyBullet.h"
#include "FPSManager.h"
#include "ScreenManager.h"
#include "SceneManager.h"
#include "GameOverScene.h"
#include "Player.h"

EnemyBullet::EnemyBullet(int row, int col)
	: BaseObject(row, col, ObjectType::EnemyBullet), 
	damage(1), 
	moveTimer(0), 
	moveSpeed(15) {}

void EnemyBullet::Update()
{
	// timer update
	moveTimer++;

	// move
	if (moveTimer >= (FPSManager::fps / moveSpeed))
	{
		if (row + 1 >= ScreenManager::row)
		{
			destroy = true;
		}
		else
		{
			row++;
		}

		moveTimer = 0;
	}
}

void EnemyBullet::Render()
{
	ScreenManager& screenManager = ScreenManager::GetInstance();
	screenManager.DrawSprite(row, col, '*');
}

void EnemyBullet::OnCollision(BaseObject* object)
{
	ObjectType objectType = object->GetObjectType();

	switch (objectType)
	{
		case ObjectType::Player:
			destroy = true;
			static_cast<Player*>(object)->TakeDamage(damage);
			break;
	}
}