//
//  Test.hpp
//  storyTeller
//
//  Created by vantan on 2016/08/18.
//
//

#ifndef Test_hpp
#define Test_hpp

#include "../../cocos2d/cocos/audio/include/SimpleAudioEngine.h"
#include <CocosGUI.h>
#include <cocos2d.h>
USING_NS_CC;

class Test : public cocos2d::Layer
{
private:
    
    cocos2d::ui::Button* testButton = cocos2d::ui::Button::create("ImageFile/UIHome.png");
    Vec3 cameraPos = Vec3::ZERO;
    cocos2d::ui::Button* button[6];
    bool _pause;
    
public:
    
    Camera* camera;
    Sprite3D* sprite = Sprite3D::create("FbxFile/test_tgaalpha2tex_stage01_sort.c3b");;
    Size winSize = Director::getInstance()->getVisibleSize();
    
    Sprite* rect;
    MoveTo* action;
    
    static Scene* CreateScene();
    bool init();
    void update(float deltaTime);
    void Transform();
    CREATE_FUNC(Test)
    
};

#endif /* Test_hpp */
