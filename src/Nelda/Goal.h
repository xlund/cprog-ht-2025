#ifndef GOAL_H
#define GOAL_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/GameEngine.h"

class Goal : public GE::GameObject {
public:
    static Goal* create();

    ~Goal();

    void setup(GE::GameEngine*) override;
    void update() override;

    bool isCollected() const;

private:
    Goal();

    bool collected{false};
    GE::Hitbox* hitbox{nullptr};
};

#endif
