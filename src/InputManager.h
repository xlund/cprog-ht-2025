#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL3/SDL.h>
#include <string>

namespace GE {
  namespace IM{
      bool isKeyDown(std::string);
      bool isKeyPressed(std::string);
      bool isKeyReleased(std::string);
      void fetchKeys();
  }

}


#endif
