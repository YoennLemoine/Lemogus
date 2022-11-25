#include "framework.h"
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

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto clickItem = MenuItemImage::create("uwu.jpg", "sussymongus.jpg", CC_CALLBACK_1(Amongsus::sussyTwerk, this));
    auto clickItem1 = MenuItemImage::create("vent.jpg", "susvent.jpg", CC_CALLBACK_1(Amongsus::sussyVent, this));

    clickItem->setPosition(Vec2(origin.x + visibleSize.width - clickItem->getContentSize().width / 2, origin.y + clickItem->getContentSize().height / 2));
    clickItem1->setPosition(Vec2(origin.x + visibleSize.width - clickItem->getContentSize().width - 115, origin.y + clickItem->getContentSize().height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(clickItem, NULL);
    auto vent = Menu::create(clickItem1, NULL);

    menu->setPosition(Vec2::ZERO);
    vent->setPosition(Vec2::ZERO);

    this->addChild(menu, 1);
    this->addChild(vent, 1);

    sussybackground = Sprite::create("sussybackground.png");
    sussybackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    sussybackground->setScale(1.4);
    addChild(sussybackground, 0);

    //sussyprite = 

    //sussyprite = Sprite::create("red.png");
    //sussyprite->setPosition(500.0f, getBoundingBox().getMidY());
    //sussyprite->setScale(0.3);
    //addChild(sussyprite, 0);

    fstream MapFile;
    MapFile.open("../Resources/Map.txt", ios::in);
    int line = 0;
    string tp;

    while (getline(MapFile, tp)) {
        for (int i = 0; i < tp.size(); i++)
        {
            if (tp[i] == 'W') {
                m_pWall = Wall::create();
                m_pWall->initialisation(i * 130.0f, line * 222.0f);
                Wallsus.push_back(m_pWall);
                addChild(m_pWall, 0);
            }
            if (tp[i] == 'P') {
                m_pPlatform = Platform::create();
                m_pPlatform->initialisation(3, 5);
                Platformsus.push_back(m_pPlatform);
                addChild(m_pPlatform, 0);
            }
            if (tp[i] == 'S') {
                m_pGate = Gate::create();
                //m_pGate->update();
                m_pGate->m_pParent = this;
                m_pGate->initialisation(i * 32.0f + 32.0f / 2.0f, 800 - (line * 18.0f));
                //m_pGate->setScale(0.5f);
                addChild(m_pGate, 0);
            }
        }
        line++;
    }
    MapFile.close();
    

    scheduleUpdate();

    return true;
}

void Amongsus::sussyTwerk(cocos2d::Ref* pSender)
{

    //sussyprite->setTexture("uwu.jpg");
    twerking = true;
}

void Amongsus::sussyVent(cocos2d::Ref* pSender)
{

}

void Amongsus::update(float delta) {

    if (twerking == true)
    {
        //Xspeed = 0.0f;
    }

    // if mouse clicked
    if (false)
    {
        Character* pChar = m_pGate->HitTest(4, 5);
        if (pChar)
        {
            pChar->setTexture("");
        }
    }
}
