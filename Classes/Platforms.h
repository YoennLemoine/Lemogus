#pragma once

#include "cocos2d.h"

class Platforms : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScenePlatform();
	virtual bool initplat();
	CREATE_FUNC(Platforms);

	void Platforms::updateplatforms(float delta);

private:
	cocos2d::Sprite* PlatformSprite;
};

