# Nelda - Escape the labyrinth

Welcome to Nelda, a game where you have to escape a horrible monster. Can you make it in time, or will he get you?


Gameplay

Explore the labyrinth and avoid the enemy.
Reach the goal tile to win the game.
When you win, the game pauses and a victory sound is played.


Controls

W A S D – Move the player
R – Restart after winning or losing
Q - Quit game

Technical Overview

Language: C++
Libraries: SDL3, SDL_image, SDL_ttf
Audio: Background music and sound effects using SDL audio
Structure: Separate game engine and game-specific logic


Resources

All assets are located in the resources/ folder:
images/
sounds/
fonts/
levels/


Build & Run

Make sure SDL3, SDL_image and SDL_ttf are installed.
Build the project using make.
Run the executable from the build directory.

We have change the original make file. make sure to change SRC_FILES to this:

SRC_FILES = src/main.cpp $(wildcard $(SRC_DIR)/**/*.cpp)


Authors

Charlie Roberton
Linus Lindroth
Erik Näslund

Course project for CPROG – Programming Project.