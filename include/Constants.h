#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants {

constexpr int gScreenWidth{640};
constexpr int gScreenHeight{640};

const std::string gResPath{"./resources/"};

const std::string bg_str{gResPath + "images/bg.jpg"};
const std::string sample_sprite_sheet{gResPath +
                                      "images/cute-mushroom-idle.png"};
const std::string sample_sprite_2{gResPath + "images/red-shroom"};

const std::string STANDARD_FONT{gResPath + "fonts/GoogleSansFlex.ttf"};
const std::string fancy_font{gResPath + "fonts/fancy_font.ttf"};

const std::string player_sprite{gResPath + "images/Charachter.png"};

const std::string sample_str{gResPath + "sounds/sample.wav"};
const std::string cool_link{gResPath + "images/sprite-link.jpg"};
const std::string level_file{"./src/level.txt"};
const std::string enemy_image{gResPath + "images/Enemy.png"};
const std::string wall_image{gResPath + "images/Wall.png"};

const std::string labyrinth_level_path{gResPath + "levels/labyrinth.txt"};

const int clockSpeed{1000};

} // namespace constants

#endif
