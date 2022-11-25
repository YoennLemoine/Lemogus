#include "framework.h"

USING_NS_CC;

Platform::Platform()
{

}

Platform::~Platform()
{

}

void Platform::initialisation(float x, float y)
{
    m_type = FLOOR;

    PlatformSprite = Sprite::create("sussysprite.png");
    PlatformSprite->retain();
    addChild(PlatformSprite, 0);
}

