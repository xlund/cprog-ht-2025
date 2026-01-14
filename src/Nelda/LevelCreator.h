#ifndef LEVELCREATOR_H
#define LEVELCREATOR_H

#include <string>
#include <map>
#include <functional>
#include "../GameEngine/GameObject.h"
#include "../GameEngine/GameEngine.h"

class LevelCreator{
    public:
    LevelCreator(std::string path, float spacing);
    LevelCreator(const LevelCreator&);
    void setGameObject(char, std::function<GE::GameObject*()>);
    void make(GE::GameEngine&);

    private:
    std::string path;
    float spacing;
    std::map<char, std::function<GE::GameObject*()>> objectMap;
};


#endif