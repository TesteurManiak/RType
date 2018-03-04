#include "../include/Background.hpp"
#include "../include/Spaceship.hpp"
#include "../include/gameSound.hpp"
#include "../include/EvilSpaceship.hpp"

#define WIDTH 800
#define HEIGHT 600
#define CYCLE 100

int main()
{
    sf::Vector2i screenDimensions(WIDTH, HEIGHT);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "R-Type");
    window.setFramerateLimit(60);
    int m_time = 0;
    sf::Clock frameClock;
    float speed = 200.f;

    // Creating Background
    Background  fond;
    Spaceship ship(sf::Vector2f(WIDTH / 2, HEIGHT / 2));

    // Ennemies with different pattern
    EvilSpaceship badguy(sf::Vector2f(850, HEIGHT / 2));
    EvilSpaceship badguy2(sf::Vector2f(800, HEIGHT / 2 - 50));
    EvilSpaceship badguy3(sf::Vector2f(750, HEIGHT / 2 - 100));

    // Music
    gameSound test;
    test.getLvl1().loop(true);
    test.getLvl1().play();

    // List with all the ennemies
    std::vector<EvilSpaceship> ennemies;
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

      // Movement manager for the player
      sf::Vector2f movement(0.f, 0.f);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movement.y -= speed;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        movement.y += speed;
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement.x -= speed;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement.x += speed;

      // Collision manager with the border of the screen
	    if (ship.getPosition().x < 0.f)
		    movement.x += speed;
	    if (ship.getPosition().y < 0.f)
		    movement.y += speed;
	    if (ship.getPosition().x + ship.getSize().x > screenDimensions.x)
		    movement.x -= speed;
	    if (ship.getPosition().y + ship.getSize().y > screenDimensions.y)
		    movement.y -= speed;

	  ship.display(movement, frameTime);

    // Ennemy generator, create an ennemy after each cycle of 100
    if (m_time % CYCLE == 0)
    {
      EvilSpaceship *ennemyGenerator = new EvilSpaceship(sf::Vector2f(850, HEIGHT / 2));
      ennemies.push_back(*ennemyGenerator);
      m_time = 0;
    }

    // Manage movement for the enemies units using their brain function
    for (int i = 0; i < ennemies.size(); i++)
      ennemies[i].brain(100.f, frameTime);

    // Delete out of screen's units
    for (int i = 0; i < ennemies.size(); i++)
    {
      if (ennemies[i].getPosition().x < 0.f)
        ennemies.erase(ennemies.begin() + i);
    }

    window.clear();
    fond.Render(window);
    window.draw(ship.getAnimSprite());

    for (int i = 0; i < ennemies.size(); i++)
      window.draw(ennemies[i].getAnimSprite());

    window.display();
    if (ship.collisionWith(ennemies) == true)
      window.close();
      m_time++;
    }
    return 0;
}
