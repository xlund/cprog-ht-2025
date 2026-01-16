#ifndef BUTTON_H
#define BUTTON_H

#include "Component.h"
#include "GameEngine.h"
#include "Hitbox.h"
#include "Text.h"
#include <functional>
#include <string>
namespace GE {
class Button : public Text {
public:
  ~Button();

  Button *create(std::string, int, int, int, int, GE::GameEngine *);
  void setOnClick(std::function<void()>);
  void update();
  void render();

private:
  Button(std::string, int, int, int, int, GE::GameEngine *);
  Button(const Button &) = delete;
  Button &operator=(const Button &) = delete;
  GE::Hitbox *hitbox;
  std::function<void()> onClick;
};
} // namespace GE

#endif
