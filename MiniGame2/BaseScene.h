#pragma once

class BaseScene
{
public:
	BaseScene() = default;
	virtual ~BaseScene() = default;

	virtual bool Update() = 0;
};
