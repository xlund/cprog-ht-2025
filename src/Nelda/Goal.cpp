#include "Goal.h"

namespace GE {

Goal *Goal::create() { return new Goal(); }

Goal::Goal() {}

void Goal::setup(GE::GameEngine *ge) {


  x = 400.0f;
  y = 300.0f;


  hitbox = new Hitbox(x, y, 40.0f, 40.0f);

  hitbox->setTag("Goal");
}

void Goal::update() {

  if (collected) {
    return; 
  }


}

bool Goal::isCollected() const { return collected; }

} // namespace GE
