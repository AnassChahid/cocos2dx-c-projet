#include "Lvl2Scene.h"
#include "PauseScene.h"
#include"Lvl3Scene.h"
#include"GameOver.h"


USING_NS_CC;

Scene* Lvl2Scene::createScene()
{
    // adding physics world
    auto scene = Scene::createWithPhysics();
    auto layer = Lvl2Scene::create();
    scene->addChild(layer);
    return scene;
    return Lvl2Scene::create();
}



bool Lvl2Scene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    // cc_callback fonction to call pause menu
    auto pauseItem =
        MenuItemImage::create("pauseb.png", "pauseb.png",
            CC_CALLBACK_1(Lvl2Scene::GoToPauseScene, this));
    pauseItem->setPosition(Point(pauseItem->getContentSize().width -
        (pauseItem->getContentSize().width / 4) + origin.x,
        visibleSize.height - pauseItem->getContentSize().height +
        (pauseItem->getContentSize().width / 4) + origin.y));
    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    // adding the background for the game
    auto backgroundSprite = Sprite::create("backg2.png");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) +
        origin.x, (visibleSize.height / 2) + origin.y + 40));
    this->addChild(backgroundSprite, -1);

    auto backgroundSprite1 = Sprite::create("backg1.png");
    backgroundSprite1->setPosition(Point((visibleSize.width / 2) + origin.x , (visibleSize.height / 2) + origin.y - 130));
    this->addChild(backgroundSprite1, -1);
    auto backgroundSprite11 = Sprite::create("backg1.png");
    backgroundSprite11->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y +150));
    this->addChild(backgroundSprite11, -1);

    auto rock = Sprite::create("backgg3.png");
    rock->setPosition(300, 120);
    this->addChild(rock, -1);
    


    // wall physics to make the sprite stay in the box 
    auto wall = Node::create();
    auto wallBody = PhysicsBody::createEdgeBox(visibleSize,
        PhysicsMaterial(1.0f, 1.0f, 1.0f));
    wall->setPhysicsBody(wallBody);
    wall->setPosition(Vec2(visibleSize.width / 2 + origin.x - 20,
        visibleSize.height / 2 + origin.y + 50));
    addChild(wall);

   
    // creat sprite and adding physics body to it
    auto sprite = Sprite::create("player.png");
    sprite->setPosition(16, 110);
    auto physicsBody = PhysicsBody::createCircle(sprite->getContentSize().width / 2);
    physicsBody->setDynamic(true);
    sprite->setPhysicsBody(physicsBody);
    this->addChild(sprite);

    // function to detect collison between sprites
    auto contactListener =
        EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [](PhysicsContact& contact) {
        CCLOG("contact begin");
        auto shapeA = contact.getShapeA();
        auto bodyA = shapeA->getBody();
        auto shapeB = contact.getShapeB();
        auto bodyB = shapeB->getBody();
        return true;
    };

    // moving the sprite using keeybord 
    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
        int offsetX = 0, offsetY = 0;
        float x,y;
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            offsetX = -30;
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            offsetX = 30;
            x = event->getCurrentTarget()->getPositionX();
            y = event->getCurrentTarget()->getPositionY();

            if ( x>=420){
                // transition between level 2 and level 3
                auto scene = Lvl3Scene::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
            }
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            offsetY = -30;
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
        case EventKeyboard::KeyCode::KEY_SPACE:
            offsetY = +30;
            break;
        }
        auto moveTo = MoveTo::create(0.3, Vec2(event->getCurrentTarget()->getPositionX() + offsetX, event->getCurrentTarget()->getPositionY() + offsetY));
        event->getCurrentTarget()->runAction(moveTo);

    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);
    return true;

}
void Lvl2Scene ::GoToPauseScene(cocos2d::Ref* pSender)
{
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(scene);
}


