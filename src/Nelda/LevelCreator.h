#ifndef LEVELCREATOR_H
#define LEVELCREATOR_H

#include <string>
#include <map>
#include <functional>
#include "../GameEngine/GameObject.h"

class LevelCreator{
    public:
    LevelCreator(std::string path, double spacing);
    void setGameObject(char, std::function<GE::GameObject*()>);
    void make();

    private:
    std::string path;
    double spacing;
    std::map<char, std::function<GE::GameObject*()>> objectMap;
};


#endif