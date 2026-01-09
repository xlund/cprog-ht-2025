#include "LevelCreator.h"
#include <string>

LevelCreator::LevelCreator(std::string path, double spacing) : path(path), spacing(spacing){}
void LevelCreator::setGameObject(char c, std::function<GE::GameObject*()> creator){
    objectMap[c] = creator;    
}
void LevelCreator::make(){

}