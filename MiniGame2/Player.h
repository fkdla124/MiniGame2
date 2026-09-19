#pragma once

#include "BaseObject.h"

class Player : public BaseObject
{
public:
	Player(int row, int col);
	~Player() = default;

	void Update() override;
	void Render() override;

	void OnCollision(BaseObject* object) override;

	void TakeDamage(int damage);

	int GetHP();

private:
	int hp;

	int moveTimer;
	int moveSpeed;

	float shotTimer;
	float shotCooldown;
};