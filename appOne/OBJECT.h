#pragma once
class OBJECT
{
public:
    void init(float x, float y, float vx, float vy, float leftFrame);
    bool move();
    void draw();
    OBJECT* getNext() {
        return State.next;
    }
    //セットするのは自分の次のオブジェクト
    void setNext(OBJECT* next) {
        State.next = next;
    }
private:
    friend class OBJECT_POOL;
    OBJECT();
    static int Img;
    float LifeTime;
    //unionでちょっとだけメモリの節約
    union {
        struct {
            float x, y, vx, vy;
        }live;
        OBJECT* next;
    }State;
};

