#pragma once
#include"OBJECT.h"
class OBJECT_POOL
{
public:
    OBJECT_POOL();
    void createObject(float x, float y, float vx, float vy, float lifeTime);
    void moveObjects();
    void drawObjects();
private:
    static const int SIZE = 30;
    OBJECT Objects[SIZE];
    OBJECT* FirstAvailableObject;
};

