#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include <string>
namespace GameEngine {
  class SoundPlayer {
    public:
      void play();
      void pause();
      void stop();
    private:
      std::string src{""};
  };
}

#endif
