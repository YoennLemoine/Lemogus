#pragma once

#include "cocos2d.h"

class Entity : public cocos2d::Sprite
{
public:
	enum
	{
		WALL,
		FLOOR,
		PLAYER,
	};
	Entity();
	virtual	~Entity();
	void initialisation(int x, int y, int type);
	CREATE_FUNC(Entity);
	int m_type;

private:

};