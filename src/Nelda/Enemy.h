#ifndef ENEMY_H
#define ENEMY_H
#include "../GameEngine/GameObject.h"
#include "TempObject.h"

class Enemy : public GE::GameObject{
public:
    Enemy(TempObject);
    void setup();
    void update();
private:
    int hp;
    int speed;
    int x;
    int y;
    int targetX;
    int targetY;
    TempObject target;
};

#endif