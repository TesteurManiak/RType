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
  sf::Vector2f& getPosition();
  void  display(sf::Vector2f movement, sf::Time frameTime);
protected:
  sf::Texture _texture;
  Animation   _shipAnim;
  Animation*  _currentAnimation;
  AnimatedSprite  _animatedSprite;
  sf::Vector2f _movement;
  sf::Vector2f _position;
};

#endif
