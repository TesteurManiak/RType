#include "../include/Background.hpp"

Background::Background()
{
  if (!this->_texture.loadFromFile("./ressources/background/clean-pixel-landscape.jpg"))
  {
    std::cerr << "Error : can't load sprite" << std::endl;
    exit(-1);
  }
  this->_texture.setSmooth(false);
  this->_sprite.setTexture(this->_texture);
}

void Background::Render(sf::RenderWindow &window)
{
        window.draw(this->_sprite);
}
