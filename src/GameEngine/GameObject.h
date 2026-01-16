#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
namespace GE {

class GameEngine;

class GameObject {
public:
  virtual ~GameObject() = default;
  virtual void setup(GameEngine *){};
  virtual void update(){};
  void setPos(float, float);
  void getPos(float &, float &);

protected:
  GameObject(GameEngine*);
  GameObject(GameEngine*,float, float);
  GameObject(const GameObject&) = delete;
  GameObject& operator=(const GameObject&)=delete;
  GameEngine* gameEngine;
  float x;
  float y;
};
} // namespace GE

#endif
