#include "Amongsus.h"

USING_NS_CC;

Scene* Amongsus::createScene()
{
    auto scene = Scene::create();
    auto layer = Amongsus::create();
    scene->addChild(layer);

    return scene;
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
    sussyprite = Sprite::create("red.png");
    sussyprite->setPosition(getBoundingBox().getMidX(), getBoundingBox().getMidY());
    addChild(sussyprite, 0);

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