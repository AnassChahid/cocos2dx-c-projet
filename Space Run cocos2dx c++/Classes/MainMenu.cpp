#include "MainMenu.h"
#include "Lvl1Scene.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenu::create();
    scene->addChild(layer);
    return scene;
    return MainMenu::create();
}



bool MainMenu::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
   
  
    auto playItem =
        MenuItemImage::create("play.png", "play.png",
            //fonction pour switcher au lvl1 scene
            CC_CALLBACK_1(MainMenu::GoToLvl1Scene, this));  
    auto menu = Menu::create(playItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height /2 + origin.y + 10);
    this->addChild(menu);
    // adding background sprites
    auto bg1 = Sprite::create("backg2.png");
    bg1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(bg1, -1);
    auto bg2 = Sprite::create("bgmenu2.png");
    bg2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y +10));
    this->addChild(bg2, -1);
    // adding a theme song to the game
    int id = AudioEngine::play2d("music.mp3");
    return true;}

void MainMenu::GoToLvl1Scene(Ref* pSender)
{
    auto scene = Lvl1Scene::createScene();
    Director::getInstance()->replaceScene(scene);
}


