#include "Goal.h"
#include "../GameEngine/Rectangle.h"
#include "Game.h"
#include <iostream>

Goal *Goal::create(Game *game) { return new Goal(game); }

Goal::Goal(Game *game) : game(game) {
}

void Goal::setup(GE::GameEngine *engine) {

  hitbox = GE::Hitbox::create(x, y, 64.0f, 64.0f, engine);
  rect_ = GE::Rectangle::create(x, y, 64, 64, 255, 215, 0, 255, engine);
  

  hitbox->setTag("goal");

}

void Goal::update() { hitbox->setPosition(x, y); }

bool Goal::isCollected() const { return collected; }
