#ifndef __Main_Menu_H__
#define __Main_Menu_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainMenu);
    void GoToLvl1Scene(Ref* pSender);
  
};

#endif
