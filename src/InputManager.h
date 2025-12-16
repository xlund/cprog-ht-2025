#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL3/SDL.h>
#include <string>

namespace GE {
  namespace IM{
      void fetchKeys();

      bool isKeyDown(std::string);
      bool isKeyPressed(std::string);
      bool isKeyReleased(std::string);

      void getMousePosition(float &,float &);
      bool isLeftMouseDown();
      bool isRightMouseDown();
      bool isLeftMousePressed();
      bool isRightMousePressed();
      bool isLeftMouseReleased();
      bool isRightMouseReleased(); 
  }

}


#endif
