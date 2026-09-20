#pragma once

#include "BaseObject.h"

class Enemy : public BaseObject
{
public:
	Enemy(int row, int col);
	~Enemy() override = default;

	void Update() override;
	void Render() override;
	void OnCollision(BaseObject* object) override;

	void TakeDamage(int damage);

private:
	int hp;

	int spawnCol;
	int moveDirection;

	int moveTimer;
	int moveSpeed;

	float shotTimer;
	float shotCooldown;
};