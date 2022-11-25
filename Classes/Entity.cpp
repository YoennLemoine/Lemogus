#include "framework.h"

Entity::Entity()
{
	m_type = 0;
}

Entity::~Entity()
{
}

void Entity::initialisation(int x, int y, int type)
{
	m_type = type;

	switch (m_type)
	{
	case PLAYER:
		Sprite::create("red.png");
		break;
	case WALL:
		Sprite::create("red.png");
		break;
	case FLOOR:
		Sprite::create("red.png");
		break;
	default:
		break;
	}
	
}
