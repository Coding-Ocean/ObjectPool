#include"libOne.h"
#include "OBJECT_POOL.h"
OBJECT_POOL::OBJECT_POOL()
    : FirstAvailableObject(nullptr)
{
    OBJECT::Img = loadImage("assets/unchi.png");
 
    //[0]番目を先頭待機中オブジェクトとする
    FirstAvailableObject = &Objects[0];
    //自分と自分の次のオブジェクトをつないでいく
    for (int i = 0; i < SIZE-1; i++) {
        Objects[i].setNext(&Objects[i + 1]);
    }
    //最後はnull
    Objects[SIZE - 1].setNext(nullptr);
}
void OBJECT_POOL::createObject(float x, float y, float vx, float vy, float lifeTime)
{
    if (FirstAvailableObject == nullptr)return;
    //先頭待機中オブジェクトを出陣させる準備
    OBJECT* newObject = FirstAvailableObject;
    //自分の次のオブジェクトを先頭待機中オブジェクトにする
    FirstAvailableObject = newObject->getNext();
    //出陣！
    newObject->init(x, y, vx, vy, lifeTime);
}
void OBJECT_POOL::moveObjects()
{
    for (int i = 0; i < SIZE; i++) {
        //move中に死ぬとtrueを返してくる
        if (Objects[i].move())
        {
            //現在の先頭待機中オブジェクトを自分の次のオブジェクトにする
            Objects[i].setNext(FirstAvailableObject);
            //自分が先頭待機中オブジェクトになる
            FirstAvailableObject = &Objects[i];
        }
    }
}
void OBJECT_POOL::drawObjects()
{
    for (int i = 0; i < SIZE; i++) {
        Objects[i].draw();
    }
}