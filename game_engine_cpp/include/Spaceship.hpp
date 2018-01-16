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
  void  Render(sf::RenderWindow &window);
private:
  sf::Texture _texture;
  Animation _shipAnim;
  AnimatedSprite  _animSprite;
};

#endif
