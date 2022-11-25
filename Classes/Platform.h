#pragma once

#include "cocos2d.h"

class Platform : public Entity
{
public:
	Platform();
	virtual ~Platform();

	void initialisation(float x, float y);
	CREATE_FUNC(Platform);

private:

	cocos2d::Sprite* PlatformSprite;
};