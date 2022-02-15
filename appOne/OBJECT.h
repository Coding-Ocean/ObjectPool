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
    //�Z�b�g����͎̂����̎��̃I�u�W�F�N�g
    void setNext(OBJECT* next) {
        State.next = next;
    }
private:
    friend class OBJECT_POOL;
    OBJECT();
    static int Img;
    float LifeTime;
    //union�ł�����Ƃ����������̐ߖ�
    union {
        struct {
            float x, y, vx, vy;
        }live;
        OBJECT* next;
    }State;
};

