#pragma once

#include "cocos2d.h"

class Character : public Entity
{
public:
	Character();
	virtual	~Character();
	virtual bool init();
	void update(float deltaTime);
	//void setTexture
	CREATE_FUNC(Character);

private:
	bool XCollide;
	bool YCollide;
	float Xspeed;
	float Yspeed;

	cocos2d::Sprite* sussyprite;
};