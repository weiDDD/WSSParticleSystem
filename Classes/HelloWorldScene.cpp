#include "HelloWorldScene.h"
#include "ParticleEmitter.h"
#include "cocostudio\CCSGUIReader.h"
#include "FileCenter.h"



USING_NS_CC;
using namespace cocostudio;

HelloWorld::HelloWorld() {
	uiView = nullptr;
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	
	particle = nullptr;
	particleSystem = nullptr;

	this->scheduleUpdate();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(false);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);  //将事件添加到this这个层中
	this->setTouchEnabled(true);


    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
 //   auto closeItem = MenuItemImage::create(
 //                                          "CloseNormal.png",
 //                                          "CloseSelected.png",
 //                                          CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
 //   
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
 //                               origin.y + closeItem->getContentSize().height/2));

 //   // create menu, it's an autorelease object
 //   auto menu = Menu::create(closeItem, NULL);
 //   menu->setPosition(Vec2::ZERO);
 //   this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    //
    //// position the label on the center of the screen
    //label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - label->getContentSize().height));

    //// add the label as a child to this layer
    //this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    //// position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //// add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    
	
	/*auto uiLayer = ParticleUiView::getInstance();
	uiLayer->init();
	this->addChild(uiLayer);*/

	//自己的粒子测试
	/*ParticleManager* myPar = ParticleManager::create();
	myPar->init();
	myPar->setRunningLayer(this);
	myPar->readDataFromJson("json/bg.par");
	myPar->setPosition(Point(600,300));
	addChild(myPar);*/

	/*testLayer = Layer::create();
	this->addChild(testLayer);*/


	// cocos2dx 自带的粒子系统测试
	/*particleSystem = CCParticleFireworks::create();
	particleSystem->setTexture(CCTextureCache::sharedTextureCache()->addImage("coord_point21.png"));
	particleSystem->setTotalParticles(2000);
	testLayer->addChild(particleSystem);*/


	// 自己改版的粒子系统测试
	/*particle = ParticleEmitter::create();
	particle->setTotalParticles(6000);
	particle->setTexture(CCTextureCache::sharedTextureCache()->addImage("texture/shandian1.png"));
	particle->setTestData();
	particle->setPosition(visibleSize.width / 2, visibleSize.height/2);
	testLayer->addChild(particle);

	ParticleEmitter::setRunningLayer(this);

	this->runAction( CCSequence::create( CCDelayTime::create(3) , CCCallFunc::create( this, callfunc_selector(HelloWorld::callTest)), NULL));*/

	// ui界面创建
	uiView = ParticleUiView::create(); 
	this->addChild(uiView);
	
	/*for (int i = 0; i < 50; ++i) {
		auto singlePar = ParticleEmitter::create();
		singlePar->readJsonData(FileCenter::getInstance()->readJsonData("json/test2.par"));
		singlePar->setPosition(Vec2(100 + 10 * i, 500));
		this->addChild(singlePar);
	}*/
	/*auto singlePar2 = ParticleEmitter::create();
	singlePar2->readJsonData(FileCenter::getInstance()->readJsonData("json/test1.par"));
	singlePar2->setPosition(Vec2(800, 500));
	this->addChild(singlePar2);*/

	/*skewSprite = Sprite::create("bg2.png");
	skewSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(skewSprite);*/

    return true;
}

void HelloWorld::callTest() {
	
	particle->removeFromParent();
	particle = nullptr;

	this->runAction(CCRepeatForever::create(CCSequence::create(CCDelayTime::create(0.02), CCCallFunc::create(this, callfunc_selector(HelloWorld::callTest2)), NULL)));

	/*testLayer->removeFromParent();
	particle = nullptr;*/
}

void HelloWorld::callTest2() {
	
	
}

void HelloWorld::update(float dt){

	//////粒子效果测试
	
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

///////触摸事件
bool HelloWorld::onTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {

	return true;
}
void HelloWorld::onTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
	Vec2 location = pTouch->getLocation();
	/*if (particle)
		particle->setPosition(location);*/

	if (particle)
		particle->setPosition(location);
	
}
void HelloWorld::onTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {

}


