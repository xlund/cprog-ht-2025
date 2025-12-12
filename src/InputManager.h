#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL3/SDL.h>
#include <string>

namespace GE {
  namespace IM{
      bool isKeyDown(std::string);
      bool isKeyPressed(char);
      bool isKeyReleased(char);
      void fetchKeys();
  }

}


#endif
