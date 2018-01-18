#include "../include/Background.hpp"
#include "../include/Spaceship.hpp"
#include "../include/gameSound.hpp"
#include "../include/EvilSpaceship.hpp"
#include <iostream>

#define WIDTH 800
#define HEIGHT 600

int main()
{
    sf::Vector2i screenDimensions(WIDTH, HEIGHT);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "R-Type");
    window.setFramerateLimit(60);
    sf::Clock frameClock;
    float speed = 200.f;

    Background  fond;
    Spaceship ship(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
    EvilSpaceship badguy(sf::Vector2f(850, HEIGHT / 2));

    gameSound test;
    test.getLvl1().loop(true);
    test.getLvl1().play();

    while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
          window.close();
      }
      sf::Time frameTime = frameClock.restart();

      sf::Vector2f movement(0.f, 0.f);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movement.y -= speed;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        movement.y += speed;
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement.x -= speed;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement.x += speed;

      ship.display(movement, frameTime);
      badguy.brain(100.f, frameTime);

      window.clear();
      fond.Render(window);
      window.draw(ship.getAnimSprite());
      window.draw(badguy.getAnimSprite());
      window.display();
      if (ship.collisionWith(badguy) == true)
        window.close();
    }
    return 0;
}
