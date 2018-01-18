#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Spaceship
{
public:
  Spaceship(sf::Vector2i screenDimensions);
  virtual ~Spaceship() {};
  Animation*  getAnimation();
  Animation*  getCurrentAnim();
  AnimatedSprite& getAnimSprite();
private:
  sf::Texture _texture;
  Animation   _shipAnim;
  Animation*  _currentAnimation;
  AnimatedSprite  _animatedSprite;
};

#endif
