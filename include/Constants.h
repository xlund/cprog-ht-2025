#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants {

// Screen
constexpr int gScreenWidth{640};
constexpr int gScreenHeight{480};

// Base resource path
const std::string gResPath{"./resources/"};

// Images
const std::string bg_str{gResPath + "images/bg.jpg"};
const std::string sample_sprite_sheet{
    gResPath + "images/cute-mushroom-idle.png"};
const std::string sample_sprite_2{
    gResPath + "images/red-shroom"};


const std::string player_sprite{
    gResPath + "images/Charachter.png"};

// Other resources
const std::string sample_str{gResPath + "sounds/sample.wav"};
const std::string cool_link{gResPath + "images/sprite-link.jpg"};
const std::string STANDARD_FONT{gResPath + "fonts/GoogleSansFlex.ttf"};
const std::string level_file{"./src/level.txt"};

const int clockSpeed{1000};

} // namespace constants

#endif
