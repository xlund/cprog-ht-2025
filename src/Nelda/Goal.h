#ifndef GOAL_H
#define GOAL_H

#include "../GameEngine/GameObject.h"
#include "../GameEngine/Hitbox.h"

class Game;   // forward declaration

class Goal : public GE::GameObject {
public:
    static Goal* create(Game* game);

    ~Goal() {}

    void setup(GE::GameEngine*) override;
    void update() override;

    bool isCollected() const;

private:
    Goal(Game* game);

    Game* game;
    bool collected{false};
    GE::Hitbox* hitbox{nullptr};
};

#endif
