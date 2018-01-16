#include "../include/Spaceship.hpp"

Spaceship::Spaceship()
{
  if (!this->_texture.loadFromFile("ressources/sprites/spaceship.png"))
  {
    std::cerr << "Error : can't load sprite" << std::endl;
    exit(-1);
  }
  this->_texture.setSmooth(false);
  this->_shipAnim.setSpriteSheet(this->_texture);
  this->_shipAnim.addFrame(sf::IntRect(0, 0, 33, 17));
  this->_shipAnim.addFrame(sf::IntRect(33, 0, 33, 17));
  this->_shipAnim.addFrame(sf::IntRect(66, 0, 33, 17));
  this->_shipAnim.addFrame(sf::IntRect(99, 0, 33, 17));
}

void Spaceship::Render(sf::RenderWindow &window)
{
  window.draw(this->_animSprite);
}
