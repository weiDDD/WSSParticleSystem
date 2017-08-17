#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ParticleEmitter.h"
#include "ParticleUiView.h"

class HelloWorld : public cocos2d::Layer
{
public:
	HelloWorld();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	virtual void update(float dt);

	//virtual void onExit();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	///////触摸事件
	virtual bool onTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void onTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void onTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);

	pp::ParticleEmitter* particle;
	CCParticleSystem* particleSystem;

	void callTest();
	void callTest2();
	std::vector<int> test;

	//Layer* testLayer;
	//Sprite* skewSprite;
	//Sprite* skewSprite2;


	ParticleUiView* uiView;
};

#endif // __HELLOWORLD_SCENE_H__
