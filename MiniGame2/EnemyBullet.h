#pragma once

#include "BaseObject.h"

class EnemyBullet : public BaseObject
{
public:
	EnemyBullet(int row, int col);
	virtual ~EnemyBullet() override = default;

	virtual void Update() override;
	virtual void Render() override;

	void OnCollision(BaseObject* object) override;

private:
	int damage;
	int moveTimer;
	int moveSpeed;
};