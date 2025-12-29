#ifndef WALL_H
#define WALL_H

#include "../GameEngine/Hitbox.h"
#include "../GameEngine/GameObject.h"
class Wall : public GE::GameObject{
public:
    Wall(int,int);
    void setup(GE::GameEngine*);
    void update();
private:
    GE::Hitbox* hitbox;
    int x;
    int y;
};

#endif