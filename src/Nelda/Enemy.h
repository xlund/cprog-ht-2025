#ifndef ENEMY_H
#define ENEMY_H
#include "../GameEngine/GameObject.h"
#include "TempObject.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/Sprite.h"

class Enemy : public GE::GameObject{
public:
    static Enemy* create(TempObject,int,int,int);
    void setup(GE::GameEngine*);
    void update();
private:
    Enemy(TempObject,int,int,int);
    int hp;
    int speed;
    int targetX;
    int targetY;
    TempObject target;
    GE::Hitbox* hitbox;
    GE::Sprite* sprite;
    
    //void wallDetection(GE::Hitbox*);
};

#endif