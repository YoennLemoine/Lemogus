#pragma once

#include "cocos2d.h"

class Amongsus;
class Character : public Entity
{
public:
	Character();
	virtual	~Character();
	virtual bool init();
	void update(float deltaTime);
	//void setTexture
	CREATE_FUNC(Character);

	Amongsus* m_pParent;

private:
	bool XCollide;
	bool YCollide;
	float Xspeed;
	float Yspeed;
};