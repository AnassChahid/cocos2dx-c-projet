#include "PauseScene.h"
#include "Lvl1Scene.h"
#include "MainMenu.h"
USING_NS_CC;

Scene* PauseScene::createScene()
{
    auto scene = Scene::create();
    auto layer = PauseScene::create();
    scene->addChild(layer);
    return scene;
    return PauseScene::create();
}

bool PauseScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    // adding pause items retry , main manu , resume
    auto resumeItem =
        MenuItemImage::create("resume.png",
            "bk.png",
            CC_CALLBACK_1(PauseScene::Resume, this));
    auto retryItem =
        MenuItemImage::create("retry.png",
            "bk.png",
            CC_CALLBACK_1(PauseScene::Retry, this));
    auto mainMenuItem =
        MenuItemImage::create("main menu.png",
            "bk.png",
            CC_CALLBACK_1(PauseScene::GoToMainMenu, this));
    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,
        NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 18);
    this->addChild(menu);

   // adding background 
    auto bg1 = Sprite::create("backg2.png");
    bg1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(bg1, -1);
    auto bg2 = Sprite::create("pause.png");
    bg2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(bg2, -1);

   
 
    return true;
}
//  link the paus menu items with their function
    void PauseScene::Resume(cocos2d::Ref* pSender)
{
         Director::getInstance()->popScene();
}
    void PauseScene::GoToMainMenu(cocos2d::Ref* pSender)
{
      auto scene = MainMenu::createScene();
      Director::getInstance()->popScene();
      Director::getInstance()->replaceScene(scene);
  }

    void PauseScene::Retry(cocos2d::Ref * pSender)
    {
        auto scene = Lvl1Scene::createScene();
        Director::getInstance()->popScene();
        Director::getInstance()->replaceScene(scene);
    }

