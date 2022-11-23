#include "Amongsus.h"

USING_NS_CC;

Scene* Amongsus::createScene()
{
    auto scenesus = Scene::create();
    auto layer = Amongsus::create();
    scenesus->addChild(layer);

    return scenesus;
}

bool Amongsus::init()
{
    if (!Layer::init())
    {
        return false;
    }

    //test spritesheet
    //auto spritecache = SpriteFrameCache::getInstance();
    //spritecache->addSpriteFramesWithFile("sussysprite.png");
    //sprite->getSpriteFrame();

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    sussyprite = Sprite::create("red.png");
    sussyprite->setPosition(getBoundingBox().getMidX(), getBoundingBox().getMidY());
    addChild(sussyprite, 0);

    PlatformSprite = Sprite::create("sussysprite.png");
    PlatformSprite->setPosition(400, 100);
    addChild(PlatformSprite, 0);

    scheduleUpdate();

    return true;
}

void Amongsus::update(float delta) {
    auto position = sussyprite->getPosition();
    position.x -= 250 * delta;
    if (position.x < 0 - (sussyprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sussyprite->getBoundingBox().size.width / 2;
    sussyprite->setPosition(position);
}