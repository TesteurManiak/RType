 #include "../include/AEntity.hpp"

 Animation*  AEntity::getAnimation()
 {
   return &(this->_shipAnim);
 }

 Animation*  AEntity::getCurrentAnim()
 {
   return this->_currentAnimation;
 }

 AnimatedSprite& AEntity::getAnimSprite()
 {
   return this->_animatedSprite;
 }

 sf::Vector2f& AEntity::getMovement()
 {
   return this->_movement;
 }

sf::Vector2f& AEntity::getPosition()
{
  return this->_position;
}
