#ifndef EVILSPACESHIP_HPP
#define EVILSPACESHIP_HPP

#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define HEIGHT 600

class EvilSpaceship
{
public:
  EvilSpaceship();
  virtual ~EvilSpaceship() {};
  Animation*  getAnimation();
  Animation*  getCurrentAnim();
  AnimatedSprite& getAnimSprite();
private:
  sf::Texture _texture;
  Animation   _shipAnim;
  Animation*  _currentAnimation;
  AnimatedSprite  _animatedSprite;
  sf::Vector2f movement;
};

#endif
