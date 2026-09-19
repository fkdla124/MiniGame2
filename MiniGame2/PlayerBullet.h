#pragma once

#include "BaseObject.h"

class PlayerBullet : public BaseObject
{
public:
	PlayerBullet(int row, int col);
	virtual ~PlayerBullet() override = default;

	virtual void Update() override;
	virtual void Render() override;

	virtual void OnCollision(BaseObject* object) override;

private:
	int moveTimer;
	int moveSpeed;
	int damage;
};