#include "../include/gameSound.hpp"

mySound::mySound()
{}

void mySound::loadSound(std::string const path)
{
  if (!this->buffer.loadFromFile(path))
    exit(-1);
  this->sound.setBuffer(this->buffer);
}

void  mySound::playMusic()
{
  this->sound.play();
}

void  mySound::stopMusic()
{
  this->sound.stop();
}

void  mySound::loopMusic(bool state)
{
  this->sound.setLoop(state);
}

gameSound::gameSound()
{
  this->level_1.loadSound("ressources/musics/R_Type_Medley.wav");
}

mySound&   gameSound::getLvl1() const
{
  return this->level_1;
}
