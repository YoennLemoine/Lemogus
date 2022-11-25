#include "framework.h"

Gate::Gate()
{
	max_Entity = 12;
	lastSpawn = 0.0f;
}

Gate::~Gate()
{

}

void Gate::initialisation(float x, float y)
{
	m_type = PLAYER;

	setTexture("trapdoor.png");
	retain();
	setPosition(x, y);
	setScale(0.1);
	//addChild(this, 0);
	lastSpawn = timeGetTime();

	scheduleUpdate();
}

void Gate::update(float dt) 
{
	float time = timeGetTime();

	//if (max_Entity >= 0 && lastSpawn + 3000.f < timeGetTime())
	if (max_Entity >= 0 && timeGetTime()-lastSpawn>1000 )
	{
		lastSpawn = timeGetTime();

		Character* sussyboi = Character::create();
		sussyboi->m_pParent = m_pParent;
		sussyboi->setPosition(600, 500);
		m_pParent->addChild(sussyboi, 0);
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
