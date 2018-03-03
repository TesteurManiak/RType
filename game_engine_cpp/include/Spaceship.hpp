#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "AEntity.hpp"
#include "EvilSpaceship.hpp"

class Spaceship : public AEntity
{
public:
  Spaceship(sf::Vector2f position);
  virtual ~Spaceship() {};
  virtual bool collisionWith(std::vector<EvilSpaceship> list);
};

#endif
