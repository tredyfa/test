#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;
USING_NS_CC;

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    ArmatureDataManager::getInstance()->addArmatureFileInfo("zhanshi0.png" , "zhanshi0.plist" , "zhanshi.ExportJson");
    
    Armature *armature = Armature::create("zhanshi");
    armature->setPosition(Point(visibleSize.width * 0.5, visibleSize.height * 0.5));
    // 播放动画
    armature->getAnimation()->play("zhanshi_xingzou");
    this->addChild(armature);

    // add "HelloWorld" splash screen"

    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
