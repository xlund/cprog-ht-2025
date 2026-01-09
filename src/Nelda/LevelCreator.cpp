#include "LevelCreator.h"
#include "../GameEngine/GameEngine.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "../include/Constants.h"

LevelCreator::LevelCreator(std::string path, float spacing) : path(path), spacing(spacing){}

void LevelCreator::setGameObject(char c, std::function<GE::GameObject*()> creator){
    objectMap[c] = creator;    
}

void LevelCreator::make(GE::GameEngine &ge){
    std::fstream file(path);
    if(!file.is_open()){
        throw std::invalid_argument("Level-Fil existerar ej");
    }
    std::string line;
    int y(0);
    while(getline(file,line)){
        int x(0);
        for(char c : line){
            auto mapRow = objectMap.find(c);
            if(mapRow != objectMap.end()){
                GE::GameObject* go = mapRow->second();
                go->setPos(x*spacing,y*spacing);
                ge.addGameObject(go);
            }
            ++x;
            
        }
        ++y;
    }

}