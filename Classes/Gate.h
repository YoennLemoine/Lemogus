#pragma once

#include "cocos2d.h"

class Amongsus;

class Gate : public Entity
{
public:

	Gate();
	virtual	~Gate();
	void initialisation(float x, float y);
	void update(float dt);
	CREATE_FUNC(Gate);

	Character* HitTest(int x, int y);

	std::vector<Character*> sussybaka;

	Amongsus* m_pParent;
private:
	int max_Entity;
	DWORD lastSpawn;

	//cocos2d::Sprite* Spawn;
};