#ifndef WALL_H
#define WALL_H

#include "../GameEngine/Hitbox.h"
#include "../GameEngine/GameObject.h"
#include <vector>
#include "../GameEngine/Sprite.h"
class Wall : public GE::GameObject{
public:
    ~Wall();
    static Wall* create(float,float,float,GE::GameEngine*);
    void setup(GE::GameEngine*);
    void update();
private:
    Wall(float,float,float, GE::GameEngine*);
    std::vector<GE::Hitbox*> hitboxes;
    float length;
    GE::Sprite* sprite;
};

#endif