#ifndef __Game_Over_H__
#define __Game_Over_H__

#include "cocos2d.h"

class GameOver : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameOver);
    void GoToMainMenu(Ref* pSender);
};

#endif
