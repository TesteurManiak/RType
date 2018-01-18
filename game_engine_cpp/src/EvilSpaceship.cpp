#include "../include/EvilSpaceship.hpp"

EvilSpaceship::EvilSpaceship()
{
  if (!this->_texture.loadFromFile("ressources/sprites/ennemy_spaceship.png"))
  {
    std::cerr << "Error : can't load sprite" << std::endl;
    exit(-1);
  }
  this->_texture.setSmooth(false);
  this->_shipAnim.setSpriteSheet(this->_texture);
  this->_shipAnim.addFrame(sf::IntRect(0, 0, 21, 36));
  this->_shipAnim.addFrame(sf::IntRect(21, 0, 21, 36));
  this->_shipAnim.addFrame(sf::IntRect(42, 0, 21, 36));
  this->_shipAnim.addFrame(sf::IntRect(63, 0, 21, 36));
  this->_shipAnim.addFrame(sf::IntRect(84, 0, 21, 36));
  this->_shipAnim.addFrame(sf::IntRect(105, 0, 21, 36));
  this->_shipAnim.addFrame(sf::IntRect(126, 0, 21, 36));
  this->_shipAnim.addFrame(sf::IntRect(147, 0, 21, 36));
  this->_animatedSprite.setPosition(sf::Vector2f(700, HEIGHT / 2));
  this->_currentAnimation = &(this->_shipAnim);
}
