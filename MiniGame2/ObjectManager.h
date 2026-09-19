#pragma once

#include "List.h"
#include "BaseObject.h"

class ObjectManager
{
public:
	static ObjectManager& GetInstance();

	void CreateObject(BaseObject* object);
	void DestroyObject(BaseObject* object);
	bool CheckGameClear();
	bool CheckGameOver();
	int GetPlayerHP();
	void Clear();

	void Update();
	void Render();

	// debug
	inline static int objectCount = 0;

private:
	ObjectManager() = default;
	~ObjectManager();
	ObjectManager(const ObjectManager&) = delete;
	ObjectManager& operator=(const ObjectManager&) = delete;

private:
	List<BaseObject*> objectList;

private:
	static ObjectManager instance;
};