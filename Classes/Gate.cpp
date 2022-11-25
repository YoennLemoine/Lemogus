#include "framework.h"

Gate::Gate()
{
	max_Entity = 12;
}

Gate::~Gate()
{

}

void Gate::initialisation(float x, float y)
{
	m_type = PLAYER;

	Spawn = Sprite::create("trapdoor.png");
	Spawn->retain();
	Spawn->setPosition(x, y);
	addChild(Spawn, 0);
}

void Gate::update() 
{
	float time = timeGetTime();

	if (max_Entity >= 0)
	{
		Character* sussyboi = Character::create();
		sussyboi->setPosition(600, 400);
		addChild(sussyboi);
		max_Entity--;
		sussybaka.push_back(sussyboi);
	}

}

Character* Gate::HitTest(int x, int y)
{
	for (int i = 0; i < sussybaka.size(); i++)
	{
		Character* c = sussybaka[i];
		if (true)
		{
			return c;
		}
	}
	return nullptr;
}
