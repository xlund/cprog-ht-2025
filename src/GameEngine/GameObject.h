#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
namespace GE{

    class GameEngine;

    class GameObject
    {
    public:
        virtual void setup(GameEngine*){};
        virtual void update(){};

        protected:
        GameObject();
        GameObject(float,float);
        float x;
        float y;
    };
}

#endif