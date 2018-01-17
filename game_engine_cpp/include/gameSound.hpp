#ifndef GAMESOUND_HPP
#define GAMESOUND_HPP

#include <SFML/Audio.hpp>

class gameSound
{
private:
  sf::SoundBuffer level_1;
  sf::Sound   soundLevel1;
public:
  gameSound();
  virtual ~gameSound() {};
  void  playLevel1();
};

#endif
