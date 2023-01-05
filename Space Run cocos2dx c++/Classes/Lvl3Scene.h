#ifndef __Lvl_3_Scene_H__
#define __Lvl_3_SceneE_H__

#include "cocos2d.h"

class Lvl3Scene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Lvl3Scene);
    void GoToPauseScene(Ref* pSender);

};

#endif
