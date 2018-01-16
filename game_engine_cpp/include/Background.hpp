#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

class Background
{
private:
  sf::Texture _texture;
  sf::Sprite  _sprite;
  float   _y;
  float _speed;
public:
  Background();
  virtual ~Background() {};
  void Update(sf::RenderWindow &window, float elapsedTime);
  void Render(sf::RenderWindow &window);
};

#endif
