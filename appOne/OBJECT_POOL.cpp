#include"libOne.h"
#include "OBJECT_POOL.h"
OBJECT_POOL::OBJECT_POOL()
    : FirstAvailableObject(nullptr)
{
    OBJECT::Img = loadImage("assets/unchi.png");
 
    //[0]�Ԗڂ�擪�ҋ@���I�u�W�F�N�g�Ƃ���
    FirstAvailableObject = &Objects[0];
    //�����Ǝ����̎��̃I�u�W�F�N�g���Ȃ��ł���
    for (int i = 0; i < SIZE-1; i++) {
        Objects[i].setNext(&Objects[i + 1]);
    }
    //�Ō��null
    Objects[SIZE - 1].setNext(nullptr);
}
void OBJECT_POOL::createObject(float x, float y, float vx, float vy, float lifeTime)
{
    if (FirstAvailableObject == nullptr)return;
    //�擪�ҋ@���I�u�W�F�N�g���o�w�����鏀��
    OBJECT* newObject = FirstAvailableObject;
    //�����̎��̃I�u�W�F�N�g��擪�ҋ@���I�u�W�F�N�g�ɂ���
    FirstAvailableObject = newObject->getNext();
    //�o�w�I
    newObject->init(x, y, vx, vy, lifeTime);
}
void OBJECT_POOL::moveObjects()
{
    for (int i = 0; i < SIZE; i++) {
        //move���Ɏ��ʂ�true��Ԃ��Ă���
        if (Objects[i].move())
        {
            //���݂̐擪�ҋ@���I�u�W�F�N�g�������̎��̃I�u�W�F�N�g�ɂ���
            Objects[i].setNext(FirstAvailableObject);
            //�������擪�ҋ@���I�u�W�F�N�g�ɂȂ�
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