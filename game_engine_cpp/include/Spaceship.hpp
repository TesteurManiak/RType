#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Spaceship
{
public:
  Spaceship();
  virtual ~Spaceship() {};
  Animation* getAnim();
private:
  sf::Texture _texture;
  Animation _shipAnim;
};

#endif
