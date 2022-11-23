#include "framework.h"

Gate::Gate()
{
	max_Entity = 12;
}

Gate::~Gate()
{

}

bool Gate::init()
{
	return true;
}

void Gate::update(std::vector<Amongsus> sussybaka)
{
	//float time = deltaTime;

	if (max_Entity >= 0)
	{
		Amongsus* sussyboi = new Amongsus;
		sussyboi->setPosition(600, 400);
		max_Entity--;
	}

}