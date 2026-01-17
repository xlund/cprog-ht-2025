#include "StartScreen.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Button.h"
#include "../GameEngine/InputManager.h"
#include "../include/Constants.h"
StartScreen::StartScreen(){
    

}

StartScreen* StartScreen::create(){
    return new StartScreen();
}

void StartScreen::setup(GE::GameEngine* ge){
    

    button = GE::Button::create("Start",constants::gScreenWidth/2 -60,constants::gScreenHeight/2-40,10000,10000,ge);
    button->setFontSize(70);
    button->setHeight(70);
    button->setFont(constants::fancy_font);
    button->setOnClick([this](){
        this->buttonPressed=true;
    });


    while(!buttonPressed){
        GE::InputManager::fetchKeys();
        button->update();
        ge->updateScreen();
    }

    delete button;
    setToDelete();
}