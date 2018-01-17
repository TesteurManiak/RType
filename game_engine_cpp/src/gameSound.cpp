#include "../include/gameSound.hpp"

gameSound::gameSound()
{
  if (!this->level_1.loadFromFile("ressources/musics/R_Type_Medley.wav"))
    exit(-1);
  this->soundLevel1.setBuffer(this->level_1);
}

void  gameSound::playLevel1()
{
  this->soundLevel1.play();
}
