#include "framework.h"


USING_NS_CC;

Character::Character()
{
    init();
}

Character::~Character()
{
}

bool Character::init()
{
    m_type = PLAYER;

    //sussyprite = Sprite::create("red.png");
    //retain();
    //setPosition(500.0f, getBoundingBox().getMidY());
    //sussyprite->setScale(0.3);
    //addChild(sussyprite, 0);
    setTexture("red.png");
    setScale(0.3);

    Xspeed = 25.0f;
    Yspeed = 10.0f;
    YCollide = false;
    XCollide = false;

    scheduleUpdate();

    return true;
}

void Character::update(float deltaTime)
{
    //  auto position = sussyprite->getPosition();
    auto position = getPosition();
    position.x += Xspeed * deltaTime;
    position.y += Yspeed * deltaTime;
    //if (position.x < 0 - (sussyprite->getBoundingBox().size.width / 2))
    //    position.x = this->getBoundingBox().getMaxX() + sussyprite->getBoundingBox().size.width / 2;
    //sussyprite->setPosition(position);
    setPosition(position);

    Rect m_CharacterBounds = getBoundingBox();

    for (int i = 0; i < m_pParent->Wallsus.size(); i++)
    {
        Wall* pWall = m_pParent->Wallsus[i];
        Rect m_WallBounds = pWall->getBoundingBox();
        if (m_CharacterBounds.intersectsRect(m_WallBounds)) {
            Xspeed = -Xspeed;
            break;
        }
    }

    for (int i = 0; i < m_pParent->Platformsus.size(); i++)
    {
        Platform* pPlatform = m_pParent->Platformsus[i];
        Rect m_PlatformBounds = pPlatform->getBoundingBox();
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
    }


    return;

}
   // Platform* platform = new Platform;
  //  Wall* wall = new Wall;

    //MRect m_CharacterBounds = getBoundingBox();
    //Rect m_PlatformBounds = platform->getBoundingBox();
    //Rect m_WallBounds = wall->getBoundingBox();

    /*if (m_CharacterBounds.intersectsRect(m_PlatformBounds)) {
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
}*/
