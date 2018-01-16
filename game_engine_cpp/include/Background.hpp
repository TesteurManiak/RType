#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Background
{
private:
  sf::Texture _texture;
  sf::Sprite  _sprite;
public:
  Background();
  virtual ~Background() {};
  void Render(sf::RenderWindow &window);
};

#endif
