#include "ObjectManager.h"
#include "SceneManager.h"
#include "GameClearScene.h"
#include "GameOverScene.h"
#include "Player.h"

ObjectManager ObjectManager::instance;

ObjectManager& ObjectManager::GetInstance()
{
	return instance;
}

void ObjectManager::CreateObject(BaseObject* object)
{
	objectList.push_back(object);
}

void ObjectManager::DestroyObject(BaseObject* object)
{
	objectList.remove(object);
	delete object;
}

void ObjectManager::Clear()
{
	for (auto it = objectList.begin(); it != objectList.end(); ++it)
	{
		delete (*it);
	}
	objectList.clear();
}

void ObjectManager::Update()
{
	objectCount = (int)objectList.size();

	// 오브젝트 로직 Update
	for (auto it = objectList.begin(); it != objectList.end(); ++it)
	{
		(*it)->Update();
	}

	// 오브젝트 충돌, 파괴 마킹
	for (auto it = objectList.begin(); it != objectList.end(); ++it)
	{
		for (auto targetIt = objectList.begin(); targetIt != objectList.end(); ++targetIt)
		{
			if (it == targetIt)
				continue;

			if (((*it)->GetRow() == (*targetIt)->GetRow()) && ((*it)->GetCol() == (*targetIt)->GetCol()))
			{
				(*it)->OnCollision((*targetIt));
			}
		}
	}

	// 오브젝트 파괴
	for (auto it = objectList.begin(); it != objectList.end();)
	{
		if ((*it)->Destroyable())
		{
			it = objectList.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void ObjectManager::Render()
{
	for (auto it = objectList.begin(); it != objectList.end(); ++it)
	{
		(*it)->Render();
	}
}

ObjectManager::~ObjectManager()
{
	for (auto it = objectList.begin(); it != objectList.end(); ++it)
	{
		delete (*it);
	}
}

bool ObjectManager::CheckGameClear()
{
	for (auto it = objectList.begin(); it != objectList.end(); ++it)
	{
		if ((*it)->GetObjectType() == ObjectType::Enemy && (*it)->Destroyable() == false)
			return false;
	}

	return true;
}

bool ObjectManager::CheckGameOver()
{
	for (auto it = objectList.begin(); it != objectList.end(); ++it)
	{
		if ((*it)->GetObjectType() == ObjectType::Player && (*it)->Destroyable() == false)
			return false;
	}

	return true;
}

int ObjectManager::GetPlayerHP()
{
	for (auto it = objectList.begin(); it != objectList.end(); ++it)
	{
		if ((*it)->GetObjectType() == ObjectType::Player)
			return static_cast<Player*>(*it)->GetHP();
	}

	return 0;
}