#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include <vector>
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/GameObject.h"
#include "LevelCreator.h"
class LevelChanger : public GE::GameObject{
public:
    static LevelChanger* create(float w, float h, const LevelCreator&);
    void setup(GE::GameEngine *);
    void update();
private:
    LevelChanger(float w,float h,const LevelCreator&);
    GE::Hitbox* hitbox;
    GE::GameEngine* gameEngin;
    LevelCreator levelCreator;
};

#endif