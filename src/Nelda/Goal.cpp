#include "Goal.h"
#include "Game.h"
#include <iostream>

Goal* Goal::create(Game* game) {
    return new Goal(game);
}

Goal::Goal(Game* game) : game(game) {}

void Goal::setup(GE::GameEngine* engine) {
    hitbox = GE::Hitbox::create(x, y, 64.0f, 64.0f, engine);
    hitbox->setTag("Goal");

    hitbox->setOnEnter([this](GE::Hitbox* other) {
        if (other->getTag() == "player" && !collected) {
            collected = true;
            game->winGame();
        }
    });
}

void Goal::update() {
    hitbox->setPosition(x, y);
}

bool Goal::isCollected() const {
    return collected;
}
