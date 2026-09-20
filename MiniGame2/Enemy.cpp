#include <cmath>
#include "Enemy.h"
#include "ScreenManager.h"
#include "FPSManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "EnemyBullet.h"

Enemy::Enemy(int row, int col) 
	: BaseObject(row, col, ObjectType::Enemy), 
	hp(3), 
	spawnCol(col), 
	moveDirection(1), 
	moveTimer(0), 
	moveSpeed(3), 
	shotTimer(0.0f), 
	shotCooldown(0.5f) { }

void Enemy::Update()
{
	// timer update
	moveTimer++;
	shotTimer += TimeManager::deltaTime;

	// move
	if (moveTimer >= (FPSManager::fps / moveSpeed))
	{
		col = min(col + moveDirection, ScreenManager::col - 2);

		if (abs(spawnCol - col) == 2)
			moveDirection = -moveDirection;

		moveTimer = 0;
	}

	// shot
	if (shotTimer >= shotCooldown)
	{
		ObjectManager& objectManager = ObjectManager::GetInstance();
		if (row + 1 < ScreenManager::row)
			objectManager.CreateObject(new EnemyBullet(row + 1, col));
		shotTimer = 0.0f;
	}
}

void Enemy::Render()
{
	ScreenManager::GetInstance().DrawSprite(row, col, 'E');
}

void Enemy::OnCollision(BaseObject* object)
{

}

void Enemy::TakeDamage(int damage)
{
	hp -= damage;

	if (hp <= 0)
		destroy = true;
}