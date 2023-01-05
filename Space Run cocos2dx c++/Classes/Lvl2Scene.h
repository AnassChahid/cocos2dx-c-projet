#ifndef __Lvl_2_Scene_H__
#define __Lvl_2_SceneE_H__

#include "cocos2d.h"

class Lvl2Scene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Lvl2Scene);
    void GoToPauseScene(Ref* pSender);

};

#endif
