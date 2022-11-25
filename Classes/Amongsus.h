#pragma once

#ifndef __AMONGSUS_H__
#define __AMONGSUS_H__

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

    std::vector<Wall*> Wallsus;
    std::vector<Platform*> Platformsus;

private:
    bool twerking;
    bool vent;

    cocos2d::Sprite* sussyprite;
    cocos2d::Sprite* sussybackground;


    Wall* m_pWall;
    Platform* m_pPlatform;
    Gate* m_pGate;
};

#endif