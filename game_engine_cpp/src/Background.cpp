#include "../include/Background.hpp"

Background::Background()
{
  this->_speed = 30.f;
  if (!this->texture.loadFromFile("ressources/background/clear-pixel-landscape.jpg"))
  {
    std::cerr << "Error : can't load sprite" << std::endl;
    exit(-1);
  }
  this->texture.setSmooth(false);
  this->_sprite.setTexture(texture);
  this->_y = this->_sprite.getPosition().y;
}

void Background::Update(sf::RenderWindow &window, float elapsedTime)
{
        windowbg1diff = bg1Y - window.getSize().y;
        if (bg1Y >= 600)
          bg1Y = - 590;
        else
          bg1Y += bgSpeed * elapsedTime;
        bg1Sprite.setPosition(0, bg1Y);
}

void Background::Render(sf::RenderWindow &window)
{
        window.draw(bg1Sprite);
}
