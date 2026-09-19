#pragma once

#include "ObjectType.h"

class BaseObject
{
public:
	BaseObject(int row, int col, ObjectType type);
	virtual ~BaseObject() = default;

	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void OnCollision(BaseObject* object) = 0;

	int GetRow();
	int GetCol();
	ObjectType GetObjectType();
	bool Destroyable();

protected:
	int row;
	int col;
	ObjectType type;
	bool destroy;
};