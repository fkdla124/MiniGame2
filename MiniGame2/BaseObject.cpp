#include "BaseObject.h"

BaseObject::BaseObject(int row, int col, ObjectType type) : row(row), col(col), type(type), destroy(false) { }

ObjectType BaseObject::GetObjectType()
{
	return type;
}

bool BaseObject::Destroyable()
{
	return destroy;
}

int BaseObject::GetRow()
{
	return row;
}

int BaseObject::GetCol()
{
	return col;
}