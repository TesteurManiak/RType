 #include "../include/AEntity.hpp"

 Animation*  AEntity::getAnimation()
 {
   return &(this->_shipAnim);
 }

 Animation*  AEntity::getCurrentAnim()
 {
   return this->_currentAnimation;
 }

 AnimatedSprite AEntity::getAnimSprite() const
 {
   return this->_animatedSprite;
 }

 sf::Vector2f AEntity::getMovement() const
 {
   return this->_movement;
 }

sf::Vector2f AEntity::getPosition() const
{
  return this->_position;
}

sf::Vector2f  AEntity::getSize() const
{
  return this->_size;
}

sf::FloatRect AEntity::getBounds() const
{
  return sf::FloatRect(this->_position, this->_size);
}

bool AEntity::collisionWith(AEntity& obj)
{
  return getBounds().intersects(obj.getBounds());
}

void  AEntity::display(sf::Vector2f movement, sf::Time frameTime)
{
  this->_animatedSprite.play(*(this->_currentAnimation));
  this->_animatedSprite.move(movement * frameTime.asSeconds());
  this->_animatedSprite.update(frameTime);
  this->_position = this->_animatedSprite.getPosition();
}
