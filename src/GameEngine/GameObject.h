#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
namespace GE {

class GameEngine;

class GameObject {
public:
  ~GameObject() = default;
  virtual void setup(GameEngine *){};
  virtual void update(){};
  void setPos(float, float);
  void getPos(float &, float &);

protected:
  GameObject();
  GameObject(float, float);
  float x;
  float y;
};
} // namespace GE

#endif
