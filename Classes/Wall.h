#pragma once

#include "cocos2d.h"

class Wall : public Entity
{
public:
	Wall();
	virtual ~Wall();

	void initialisation(float x, float y);
	CREATE_FUNC(Wall);

private:
	cocos2d::Sprite* WallSprite;
};