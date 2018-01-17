#ifndef GAMESOUND_HPP
#define GAMESOUND_HPP

#include <SFML/Audio.hpp>
#include <iostream>

class mySound
{
private:
  sf::SoundBuffer buffer;
  sf::Sound   sound;
public:
  mySound();
  virtual ~mySound() {};
  void  loadSound(std::string const path);
  void  playMusic();
  void  stopMusic();
  void  loopMusic(bool state);
};

class gameSound
{
private:
  mySound level_1;
public:
  gameSound();
  virtual ~gameSound() {};
  mySound&  getLvl1();
};

#endif
