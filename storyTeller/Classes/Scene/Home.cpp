//
//  Home.cpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#include "Home.hpp"
#include "Game.hpp"

Scene* Home::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Home::create();
    scene->addChild(layer);
    return  scene;
}

bool Home::init()
{
    menuSerect = MenuSerect::HOME;
    
    if(!Layer::init()){return  false;}
    
    
    SetBgImage();
    SetUiImage();
    
    return true;
}

void Home::update(float deltaTime)
{
    
}

void Home::SetBgImage()
{
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeImagePath.txt");
    std::ifstream inFile(filePath);
    assert(inFile);

    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;

    inFile >> imageValue;
    Sprite* bgSprite[imageValue];
    for(int i = 0; i < imageValue; i++)
    {
        inFile >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;

        bgSprite[i] = Sprite::create(_imagePath);
        bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
        bgSprite[i]->setScale(size.x, size.y);
        this->addChild(bgSprite[i]);
    }
    
}

void Home::SetUiImage()
{
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeUIImage.txt");
    std::ifstream inFile(filePath);
    assert(inFile);

    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;

    inFile >> imageValue;

    
    ui::Button* button[imageValue];
    
    for(int i = 0; i < imageValue; i++)
    {
        inFile >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;

        button[i] = ui::Button::create(_imagePath);
        button[i]->setPosition(Vec2(pos.x, pos.y));
        button[i]->setScale(size.x, size.y);
        this->addChild(button[i]);
    }
    button[1]->addTouchEventListener(CC_CALLBACK_2(Home::touchEvent, this));
}

void Home::SetQuestMenu()
{
    auto sprite = Sprite::create("ImageFile/kawabe.png");
    sprite->setPosition(1000, 600);
    sprite->setScale(0.5, 0.5);
    this->addChild(sprite);
}

void Home::touchEvent(Ref *pSender, ui::Widget::TouchEventType type)
{
    
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            
            SetQuestMenu();
            
            break;

        default:
            break;
    }
}
