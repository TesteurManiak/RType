#ifndef AENTITY_HPP
#define AENTITY_HPP

#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class AEntity
{
public:
  virtual ~AEntity() {};
  Animation*  getAnimation();
  Animation*  getCurrentAnim();
  AnimatedSprite& getAnimSprite();
  sf::Vector2f& getMovement();
protected:
  sf::Texture _texture;
  Animation   _shipAnim;
  Animation*  _currentAnimation;
  AnimatedSprite  _animatedSprite;
  sf::Vector2f _movement;
};

#endif
