#include "../include/Spaceship.hpp"

Spaceship::Spaceship(sf::Vector2f position)
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
  this->_animatedSprite.setPosition(position);
  this->_currentAnimation = &(this->_shipAnim);
  this->_position = this->_animatedSprite.getPosition();
  this->_size = sf::Vector2f(33, 17);
}

bool Spaceship::collisionWith(std::vector<EvilSpaceship> list)
{
  for (int i = 0; i < list.size(); i++)
  {
    if (getBounds().intersects(list[i].getBounds()) == true)
      return true;
  }
  return false;
}
