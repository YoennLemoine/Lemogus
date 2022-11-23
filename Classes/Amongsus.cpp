#include "Amongsus.h"
#include <fstream>
#include <string>
using namespace std;

USING_NS_CC;

Scene* Amongsus::createScene()
{
    auto scenesus = Scene::create();
    auto layer = Amongsus::create();
    scenesus->addChild(layer);

    return scenesus;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool Amongsus::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    twerking = false;
    Xspeed = 250.0f;
    Yspeed = 100.0f;
    YCollide = false;
    XCollide = false;

    fstream MapFile;
    MapFile.open("map.txt", ios::in);
    int line;
    string tp;

    while (getline(MapFile, tp)) {
        for (int i = 0; i < tp.size(); i++)
        {
            if (tp[i] == 'W') {
                WallSprite = Sprite::create("sussysprite.png");
                WallSprite->setPosition(0.0f, 250.0f);
                addChild(WallSprite, 0);
            }
            if (tp[i] == 'P') {
                PlatformSprite = Sprite::create("sussysprite.png");
                PlatformSprite->setPosition(400, 100);
                addChild(PlatformSprite, 0);
            }
            if (tp[i] == 'S') {
                sussyprite = Sprite::create("red.png");
                sussyprite->setPosition(500.0f, getBoundingBox().getMidY());
                sussyprite->setScale(0.3);
                addChild(sussyprite, 0);
            }
        }
        line++;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto clickItem = MenuItemImage::create("uwu.jpg", "sussymongus.jpg", CC_CALLBACK_1(Amongsus::sussyTwerk, this));
    auto clickItem1 = MenuItemImage::create("vent.jpg", "susvent.jpg", CC_CALLBACK_1(Amongsus::sussyTwerk, this));

    if (clickItem == nullptr ||
        clickItem->getContentSize().width <= 0 ||
        clickItem->getContentSize().height <= 0)
    {
        problemLoading("'uwu.png' and 'sussymongus.jpg'");
    }
    else
    {
        float x = origin.x + visibleSize.width - clickItem->getContentSize().width / 2;
        float y = origin.y + clickItem->getContentSize().height / 2;
        clickItem->setPosition(Vec2(x, y));
    }
    // create menu, it's an autorelease object
    auto menu = Menu::create(clickItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    //test spritesheet
    //auto spritecache = SpriteFrameCache::getInstance();
    //spritecache->addSpriteFramesWithFile("sussysprite.png");
    //sprite->getSpriteFrame();
    sussybackground = Sprite::create("sussybackground.png");
    sussybackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    sussybackground->setScale(1.4);
    addChild(sussybackground, 0);

    scheduleUpdate();

    return true;
}

void Amongsus::sussyTwerk(cocos2d::Ref* pSender)
{
    sussyprite->setTexture("uwu.jpg");
    twerking = true;
}

void Amongsus::sussyVent(cocos2d::Ref* pSender)
{

}

void Amongsus::update(float delta) {
    auto position = sussyprite->getPosition();
    position.x -= Xspeed * delta;
    position.y -= Yspeed * delta;
    if (position.x < 0 - (sussyprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sussyprite->getBoundingBox().size.width / 2;
    sussyprite->setPosition(position);

    if (twerking == true)
    {
        Xspeed = 0.0f;
    }

    Rect m_CharacterBounds = sussyprite->getBoundingBox();
    Rect m_PlatformBounds = PlatformSprite->getBoundingBox();
    Rect m_WallBounds = WallSprite->getBoundingBox();

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
