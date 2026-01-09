#ifndef GOAL_H
#define GOAL_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"

namespace GE {

class Goal : public GameObject {
public:
    Goal();

    void setup() override;
    void update() override;

    bool isCollected() const;

private:
    float x {0.0f};
    float y {0.0f};

    bool collected {false};

    Hitbox* hitbox {nullptr};
};

}

#endif
