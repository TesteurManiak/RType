#include "../include/Spaceship.hpp"

Spaceship::Spaceship(sf::Vector2i screenDimensions)
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
  this->_animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));
  this->_currentAnimation = &(this->_shipAnim);
  sf::Vector2f  position(screenDimensions / 2);
  this->_position = position;
}
