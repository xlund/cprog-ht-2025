#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include "../GameEngine/GameEngine.h"
#include "../GameEngine/Text.h"
#include "../GameEngine/Button.h"
#include "../GameEngine/GameObject.h"
class StartScreen : public GE::GameObject{
    public:
        static StartScreen* create();
        void setup(GE::GameEngine *);
    private:
        StartScreen();
        bool buttonPressed{false};
        GE::Text* text;
        GE::Button* button;


};



#endif