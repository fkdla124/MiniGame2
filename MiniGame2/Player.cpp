#include <windows.h>
#include "Player.h"
#include "ScreenManager.h"
#include "ObjectManager.h"
#include "FPSManager.h"
#include "PlayerBullet.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "GameOverScene.h"

Player::Player(int row, int col)
	: BaseObject(row, col, ObjectType::Player),
	hp(5), 
	moveTimer(0), 
	moveSpeed(20), 
	shotTimer(0.0f), 
	shotCooldown(0.1f) {}

void Player::Update()
{
	// timer
	moveTimer++;
	shotTimer += TimeManager::deltaTime;

	// move
	if (moveTimer >= (FPSManager::fps / moveSpeed))
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			col = max(col - 1, 0);
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			col = min(col + 1, ScreenManager::col - 2);
		}
		if (GetAsyncKeyState(VK_UP))
		{
			row = max(row - 1, 0);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			row = min(row + 1, ScreenManager::row - 1);
		}

		moveTimer = 0;
	}

	// shot
	if (GetAsyncKeyState('Z'))
	{
		if (shotTimer >= shotCooldown)
		{
			ObjectManager& objectManager = ObjectManager::GetInstance();
			if (row - 1 >= 0)
				objectManager.CreateObject(new PlayerBullet(row - 1, col));
			shotTimer = 0.0f;
		}
	}
}

void Player::Render()
{
	ScreenManager::GetInstance().DrawSprite(row, col, 'P');
}

void Player::OnCollision(BaseObject* object)
{

}

void Player::TakeDamage(int damage)
{
	hp -= damage;

	if (hp <= 0)
	{
		destroy = true;
		SceneManager::GetInstance().LoadScene(new GameOverScene);
	}
}

int Player::GetHP()
{
	return hp;
}