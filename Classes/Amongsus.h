#pragma once

#include "cocos2d.h"

class Amongsus : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(Amongsus);

    void update(float) override;

private:
    cocos2d::Sprite* sussyprite;
    cocos2d::Sprite* PlatformSprite;
};