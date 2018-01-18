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
  std::srand(std::time(NULL));
  sf::Vector2f  position(810, HEIGHT / 2);
  this->_animatedSprite.setPosition(position);
  this->_currentAnimation = &(this->_shipAnim);
  this->_nb = 0;
  this->_state = 1;
  this->_position = position;
}


void EvilSpaceship::brain(float speed, sf::Time frameTime)
{
  sf::Vector2f  movement(0.f, 0.f);
  if (this->_nb > 50)
  {
    this->_nb = 0;
    this->_state = -this->_state;
  }
  if (this->_state == 1)
  {
    movement.y -= speed;
    movement.x -= speed;
    this->_nb += 1;
  }
  else
  {
    movement.y += speed;
    movement.x -= speed;
    this->_nb += 1;
  }
  this->_position += movement;
  this->_animatedSprite.move(movement * frameTime.asSeconds());
  this->_animatedSprite.update(frameTime);
}
