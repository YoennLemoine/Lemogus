#pragma once

#include "cocos2d.h"

class Amongsus : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(Amongsus);

    void update(float) override;
    void sussyTwerk(cocos2d::Ref* pSender);
    void sussyVent(cocos2d::Ref* pSender);

private:
    bool twerking;
    bool vent;
    bool XCollide;
    bool YCollide;
    float Xspeed;
    float Yspeed;

    cocos2d::Sprite* sussyprite;
    cocos2d::Sprite* sussybackground;
    cocos2d::Sprite* PlatformSprite;
    cocos2d::Sprite* WallSprite;
};