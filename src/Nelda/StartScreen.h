#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Text.h"
#include "../GameEngine/Button.h"
#include "../GameEngine/GameObject.h"
class StartScreen{
    public:
        StartScreen();
        bool show(GE::GameEngine *);
    private:
        bool startButtonPressed{false};
        bool quitButtonPressed{false};
        GE::Text* text;
        GE::Button* startButton;
        GE::Button* quitButton;


};



#endif