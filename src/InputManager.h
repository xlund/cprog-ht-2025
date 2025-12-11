#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL3/SDL.h>
#include <string>

namespace GE {
  namespace IM{
      bool isKeyDown(char);
      bool isKeyPressed(char);
      bool isSpecialKeyPressed(std::string);
      bool isKeyReleased(char);
      void fetchKeys();

  }

}


#endif
