#pragma once

class BaseScene
{
public:
	BaseScene() = default;
	virtual ~BaseScene() = default;

	virtual void OnInit() = 0;
	virtual void OnDestroy() = 0;

	virtual bool Update() = 0;
};
