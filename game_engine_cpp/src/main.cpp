#include "../include/Background.hpp"
#include "../include/Spaceship.hpp"
#include "../include/gameSound.hpp"
#include "../include/EvilSpaceship.hpp"

#define WIDTH 800
#define HEIGHT 600

int main()
{
    sf::Vector2i screenDimensions(WIDTH, HEIGHT);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "R-Type");
    window.setFramerateLimit(60);
    sf::Clock frameClock;
    float speed = 200.f;
    std::vector<EvilSpaceship> ennemies;

    Background  fond;
    Spaceship ship(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
    EvilSpaceship badguy(sf::Vector2f(850, HEIGHT / 2));
    EvilSpaceship badguy2(sf::Vector2f(800, HEIGHT / 2 - 50));
    EvilSpaceship badguy3(sf::Vector2f(750, HEIGHT / 2 - 100));

    gameSound test;
    test.getLvl1().loop(true);
    test.getLvl1().play();

    ennemies.push_back(badguy);
    ennemies.push_back(badguy2);
    ennemies.push_back(badguy3);

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

	  if (ship.getPosition().x < 0.f)
		  movement.x += speed;
	  if (ship.getPosition().y < 0.f)
		  movement.y += speed;
	  if (ship.getPosition().x > screenDimensions.x)
		  movement.x -= speed;
	  if (ship.getPosition().y > screenDimensions.y)
		  movement.y -= speed;

	  ship.display(movement, frameTime);

    for (int i = 0; i < ennemies.size(); i++)
      ennemies[i].brain(100.f, frameTime);

    window.clear();
    fond.Render(window);
    window.draw(ship.getAnimSprite());

    for (int i = 0; i < ennemies.size(); i++)
      window.draw(ennemies[i].getAnimSprite());

    window.display();
    if (ship.collisionWith(ennemies) == true)
      window.close();
    }
    return 0;
}
