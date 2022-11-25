#pragma once

#include "cocos2d.h"

class Gate : public Entity
{
public:

	Gate();
	virtual	~Gate();
	void initialisation(float x, float y);
	void update();
	CREATE_FUNC(Gate);

	Character* HitTest(int x, int y);

private:
	int max_Entity;
	float lastSpawn;

	cocos2d::Sprite* Spawn;
	std::vector<Character*> sussybaka;
};