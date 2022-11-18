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

    sprite = Sprite::create("red.png");
    sprite->setPosition(getBoundingBox().getMidX(), getBoundingBox().getMidY());
    addChild(sprite, 0);

    scheduleUpdate();

    return true;
}

void Amongsus::update(float delta) {
    auto position = sprite->getPosition();
    position.x -= 250 * delta;
    if (position.x < 0 - (sprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width / 2;
    sprite->setPosition(position);
}