#include "libOne.h"
#include "OBJECT.h"
int OBJECT::Img = 0;
OBJECT::OBJECT()
    : LifeTime(0)
{
}
void OBJECT::init(float x, float y, float vx, float vy, float lifeTime) 
{
    State.live.x = x;
    State.live.y = y;
    State.live.vx = vx;
    State.live.vy = vy;
    LifeTime = lifeTime;
}
bool OBJECT::move() 
{
    if (LifeTime <= 0)return false;
    State.live.x += State.live.vx * delta;
    State.live.y += State.live.vy * delta;
    LifeTime -= delta;
    return (LifeTime <= 0);
}
void OBJECT::draw() 
{
    if (LifeTime <= 0)return;
    rectMode(CENTER);
    image(Img, State.live.x, State.live.y);
}


