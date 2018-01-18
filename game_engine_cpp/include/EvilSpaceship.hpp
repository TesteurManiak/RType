#ifndef EVILSPACESHIP_HPP
#define EVILSPACESHIP_HPP

#include "AEntity.hpp"
#include <ctime>

#define HEIGHT 600

class EvilSpaceship : public AEntity
{
public:
  EvilSpaceship();
  virtual ~EvilSpaceship() {};
  void brain(float speed, sf::Time frameTime);
private:
  int _nb;
  int _state; // UP = 1 ; DOWN = -1
};

#endif
