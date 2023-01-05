#ifndef __Lvl_1_Scene_H__
#define __Lvl_1_SceneE_H__

#include "cocos2d.h"

class Lvl1Scene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Lvl1Scene);


    void GoToPauseScene(Ref* pSender);
    
   

};

#endif
