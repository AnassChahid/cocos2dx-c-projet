#ifndef __Pause_Scene_H__
#define __Pause_SceneE_H__

#include "cocos2d.h"

class PauseScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(PauseScene);
    void Resume(Ref* pSender);
    void GoToMainMenu(Ref* pSender);
    void Retry(Ref* pSender);
   
};

#endif
