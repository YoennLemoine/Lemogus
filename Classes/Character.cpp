#include "framework.h"


USING_NS_CC;

Character::Character()
{
}

Character::~Character()
{
}

bool Character::init()
{
    m_type = PLAYER;

    sussyprite = Sprite::create("red.png");
    //sussyprite->retain();
    //sussyprite->setPosition(500.0f, getBoundingBox().getMidY());
    sussyprite->setScale(0.3);
    addChild(sussyprite, 0);

    Xspeed = 250.0f;
    Yspeed = 100.0f;
    YCollide = false;
    XCollide = false;

    return false;
}

void Character::update(float deltaTime)
{
    auto position = sussyprite->getPosition();
    position.x -= Xspeed * deltaTime;
    position.y -= Yspeed * deltaTime;
    if (position.x < 0 - (sussyprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sussyprite->getBoundingBox().size.width / 2;
    sussyprite->setPosition(position);

    Platform* platform = new Platform;
    Wall* wall = new Wall;

    Rect m_CharacterBounds = sussyprite->getBoundingBox();
    Rect m_PlatformBounds = platform->getBoundingBox();
    Rect m_WallBounds = wall->getBoundingBox();

    if (m_CharacterBounds.intersectsRect(m_PlatformBounds)) {
        if (YCollide)
        {
            ;
        }
        else
        {
            YCollide = true;

        }
    }
    else
    {
        if (YCollide)
        {
            YCollide = false;

        }
        else
        {
            ;
        }
    }

    if (YCollide) {
        Yspeed = 0.0f;
    }
    else
    {
        Yspeed = 50.0f;
    }
    if (m_CharacterBounds.intersectsRect(m_WallBounds)) {
        Xspeed = -Xspeed;
    }
}
