#include "StartScreen.h"
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Button.h"
#include "../GameEngine/InputManager.h"
#include "../include/Constants.h"
StartScreen::StartScreen(){
    

}


bool StartScreen::show(GE::GameEngine* ge){
    text = GE::Text::create("Nelda",constants::fancy_font,140,constants::gScreenWidth/2 -140,60,ge);
    text->draw();
    text->setColor(255,255,255,255);

    startButton = GE::Button::create("Start",constants::gScreenWidth/2 -60,constants::gScreenHeight/2-40,160,70,ge);
    startButton->setFontSize(70);
    startButton->setHeight(70);
    startButton->setFont(constants::fancy_font);
    startButton->setOnClick([this](){

        this->startButtonPressed=true;
    });

    quitButton = GE::Button::create("Quit",constants::gScreenWidth/2 -60,constants::gScreenHeight/2+50,160,70,ge);
    quitButton->setFontSize(70);
    quitButton->setHeight(70);
    quitButton->setFont(constants::fancy_font);
    quitButton->setOnClick([this](){

        this->quitButtonPressed=true;
    });


    while(!startButtonPressed){
        GE::InputManager::fetchKeys();
        text->update();
        startButton->update();
        quitButton->update();
        ge->updateScreen();
        if(GE::InputManager::isKeyPressed("q")||quitButtonPressed){
            break;
        }

    }

    delete text;
    delete startButton;
    return startButtonPressed;
}