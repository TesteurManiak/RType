#ifndef AENTITY_HPP
#define AENTITY_HPP

#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class AEntity
{
public:
  virtual ~AEntity() {};
  Animation*  getAnimation();
  Animation*  getCurrentAnim();
  AnimatedSprite getAnimSprite() const;
  sf::Vector2f getMovement() const;
  sf::Vector2f getPosition() const;
  sf::Vector2f getSize() const;
  sf::FloatRect getBounds() const;
  bool collisionWith(AEntity& obj);
  void  display(sf::Vector2f movement, sf::Time frameTime);
protected:
  sf::Texture _texture;
  Animation   _shipAnim;
  Animation*  _currentAnimation;
  AnimatedSprite  _animatedSprite;
  sf::Vector2f _movement;
  sf::Vector2f _position;
  sf::Vector2f _size;
};

#endif
