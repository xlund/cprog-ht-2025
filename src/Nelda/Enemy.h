#ifndef ENEMY_H
#define ENEMY_H
#include "../GameEngine/GameObject.h"
#include "TempObject.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Hitbox.h"

class Enemy : public GE::GameObject{
public:
    Enemy(TempObject,int,int);
    void setup(GE::GameEngine*);
    void update();
private:
    int hp;
    int speed;
    int x;
    int y;
    int targetX;
    int targetY;
    TempObject target;
    GE::Hitbox* hitbox;
};

#endif