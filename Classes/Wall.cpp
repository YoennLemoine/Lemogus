#include "framework.h"

USING_NS_CC;

Wall::Wall()
{

}

Wall::~Wall()
{

}

void Wall::initialisation(float x, float y)
{
    m_type = WALL;

    WallSprite = Sprite::create("sussysprite.png");
    WallSprite->retain();
    addChild(WallSprite, 0);
}
