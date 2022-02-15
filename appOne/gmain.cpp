#include"libOne.h"
#include"OBJECT_POOL.h"
void gmain() {
    window(1920,1080,full);
    hideCursor();
    OBJECT_POOL op;
    int cnt=0;
    initDeltaTime();
    while (notQuit) {
        setDeltaTime();
        if (isTrigger(KEY_SPACE)) {
            float px = 100.0f * cnt;
            float py = 50.0f;
            float vx = 0.0f;
            float vy = 600.0f;
            float lifeTime = 1.8f;
            op.createObject(px, py, vx, vy, lifeTime);
            ++cnt %= 20;
        }
        op.moveObjects();
        clear(200, 200, 0);
        op.drawObjects();
    }
}
