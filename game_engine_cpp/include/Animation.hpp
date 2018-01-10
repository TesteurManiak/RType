#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation
{
public:
  Animation(int x, int y);
  virtual ~Animation() {};
  void addFrame(sf::IntRect rect);
  void setSpriteSheet(const sf::Texture & texture);
  const sf::Texture* getSpriteSheet() const;
  std::size_t getSize() const;
  const sf::IntRect & getFrame(std::size_t n) const;
  int getX() const;
  int getY() const;

protected:
  std::vector<sf::IntRect> m_frames;
  const sf::Texture* m_texture;
  int m_sizeX;
  int m_sizeY;
};

#endif
