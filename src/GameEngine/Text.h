#ifndef TEXT_H
#define TEXT_H

#include "Component.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

namespace GE {

class Button;

class Text : public GE::Component {
public:
    static Text* create(std::string, int, int,GE::GameEngine*);
    static Text* create(std::string, std::string, int, int, int,GE::GameEngine*);

    ~Text();

    Text(const Text&) = delete;
    Text& operator=(const Text&) = delete;
    Text(Text&&) = delete;
    Text& operator=(Text&&) = delete;

    void setString(const std::string&);
    std::string getString() const;
    void setColor(unsigned char, unsigned char, unsigned char, unsigned char);
    void setFont(const std::string&);
    void setFontSize(int);
    void setWidth(int);
    void setHeight(int);
    void draw();
    void hide();
    void erase();
    void update();

private:
    friend class Button;

    Text(std::string, int, int,GE::GameEngine*);
    Text(std::string, std::string, int, int, int,GE::GameEngine*);

    std::string str;
    TTF_Font* font{};
    std::string fontPath;
    int fontSize{};
    SDL_Color color{0, 0, 0, 0};
    bool isSeen{false};
    int width{};
    int height{};
};

}

#endif
