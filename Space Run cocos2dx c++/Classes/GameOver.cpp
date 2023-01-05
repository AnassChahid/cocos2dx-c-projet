#include "GameOver.h"
#include"MainMenu.h"
#include"Lvl1Scene.h"


USING_NS_CC;

Scene* GameOver::createScene()
{
    auto scene = Scene::create();
    auto layer = GameOver::create();
    scene->addChild(layer);
    return scene;
    return GameOver::create();
}



bool GameOver::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    // adding backgrounds
    auto backgroundSprite = Sprite::create("backg2.png");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y ));
    this->addChild(backgroundSprite, -1);

    auto over = Sprite::create("over.png");
    over->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(over, -1);
    // create a fonction to take me back to main menu by clicking on 
    auto mainMenuItem =
        MenuItemImage::create("main menu.png",
            "bk.png",
            CC_CALLBACK_1(GameOver::GoToMainMenu, this));
    auto menu = Menu::create( mainMenuItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 14);
    this->addChild(menu);
    return true;
}
void GameOver::GoToMainMenu(cocos2d::Ref* pSender)
{
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(scene);
}



