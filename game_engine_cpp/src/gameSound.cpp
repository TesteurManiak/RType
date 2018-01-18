#include "../include/gameSound.hpp"

mySound::mySound()
{}

void mySound::loadSound(std::string const path)
{
  if (!this->buffer.loadFromFile(path))
    exit(-1);
  this->sound.setBuffer(this->buffer);
}

void  mySound::play()
{
  this->sound.play();
}

void  mySound::stop()
{
  this->sound.stop();
}

void  mySound::loop(bool state)
{
  this->sound.setLoop(state);
}

gameSound::gameSound()
{
  this->level_1.loadSound("ressources/musics/R_Type_Medley.wav");
}

mySound&   gameSound::getLvl1()
{
  return this->level_1;
}
