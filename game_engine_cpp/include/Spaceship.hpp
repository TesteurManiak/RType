#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "AEntity.hpp"

class Spaceship : public AEntity
{
public:
  Spaceship(sf::Vector2i screenDimensions);
  virtual ~Spaceship() {};
};

#endif
