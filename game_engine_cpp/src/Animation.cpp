#include "../include/Animation.hpp"

Animation::Animation(int x, int y) : m_sizeX(x), m_sizeY(y), m_texture(NULL)
{}

void Animation::addFrame(sf::IntRect rect)
{
  this->m_frames.push_back(rect);
}

void Animation::setSpriteSheet(const sf::Texture & texture)
{
  this->m_texture = &texture;
}

const sf::Texture*  Animation::getSpriteSheet() const
{
  return this->m_texture;
}

std::size_t Animation::getSize() const
{
  return this->m_frames.size();
}

const sf::IntRect & Animation::getFrame(std::size_t n) const
{
  return this->m_frames[n];
}

int Animation::getX() const
{
  return this->m_sizeX;
}

int Animation::getY() const
{
  return this->m_sizeY;
}
