#ifndef WALL_H
#define WALL_H

#include "../GameEngine/Hitbox.h"
#include "../GameEngine/GameObject.h"
#include <vector>
class Wall : public GE::GameObject{
public:
    static Wall* create(float,float,float);
    void setup(GE::GameEngine*);
    void update();
private:
    Wall(float,float,float);
    std::vector<GE::Hitbox*> hitboxes;
    GE::Hitbox* hitbox;
    float x;
    float y;
    float length;
};

#endif