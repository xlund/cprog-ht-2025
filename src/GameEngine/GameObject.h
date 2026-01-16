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
  bool isDeleteable();
  void setToDelete();

protected:
  GameObject();
  GameObject(float, float);
  GameObject(const GameObject&) = delete;
  GameObject& operator=(const GameObject&)=delete;
  float x;
  float y;
  bool deleteable{false};
};
} // namespace GE

#endif
