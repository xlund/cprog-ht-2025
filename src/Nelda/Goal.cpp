#include "Goal.h"

Goal* Goal::create(GE::GameEngine* ge) {
    return new Goal(ge);
}

Goal::Goal(GE::GameEngine* ge): GameObject(ge){}

Goal::~Goal() {
  delete hitbox;
  gameEngine->removeGameObject(this);
}

void Goal::setup(GE::GameEngine* ge) {
    x = 400.0f;
    y = 300.0f;

  // Skapa hitbox (syns ej, men används för kollision)
  hitbox = GE::Hitbox::create(x, y, 40.0f, 40.0f,ge);

  hitbox->setTag("Goal");
}

void Goal::update() {
    if (collected) return;
}

bool Goal::isCollected() const {
    return collected;
}
