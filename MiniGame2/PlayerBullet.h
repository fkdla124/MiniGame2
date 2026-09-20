#pragma once

#include "BaseObject.h"

class PlayerBullet : public BaseObject
{
public:
	PlayerBullet(int row, int col);
	~PlayerBullet() override = default;

	void Update() override;
	void Render() override;
	void OnCollision(BaseObject* object) override;

private:
	int moveTimer;
	int moveSpeed;
	int damage;
};