#ifndef EVILSPACESHIP_HPP
#define EVILSPACESHIP_HPP

class EvilSpaceship
{
public:
  EvilSpaceship();
  virtual ~EvilSpaceship() {};
  Animation* getAnim();
private:
  sf::Texture _texture;
  Animation _shipAnim;
};

#endif
