#include "Platforms.h"

USING_NS_CC;

Scene* Platforms::createScenePlatform()
{
    auto scene = Scene::create();
    auto layer = Platforms::create();
    scene->addChild(layer);

    return scene;
}

bool Platforms::initplat()
{
    if (!Layer::init())
    {
        return false;
    }

    

    scheduleUpdate();

    return true;
}

void Platforms::updateplatforms(float delta) {
    auto position = PlatformSprite->getPosition();
    position.x = 250;
    position.y = 400;
    //if (position.x < 0 - (PlatformSprite->getBoundingBox().size.width / 2))
    //    position.x = this->getBoundingBox().getMaxX() + PlatformSprite->getBoundingBox().size.width / 2;
    //PlatformSprite->setPosition(position);
}