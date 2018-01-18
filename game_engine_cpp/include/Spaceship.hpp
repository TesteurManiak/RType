#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "AEntity.hpp"

class Spaceship : public AEntity
{
public:
  Spaceship(sf::Vector2f position);
  virtual ~Spaceship() {};
};

#endif
