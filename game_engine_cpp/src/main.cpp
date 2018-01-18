#include "../include/Background.hpp"
#include "../include/Spaceship.hpp"
#include "../include/gameSound.hpp"
#include <iostream>

#define WIDTH 800
#define HEIGHT 600

int main()
{
    sf::Vector2i screenDimensions(WIDTH, HEIGHT);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "R-Type");
    window.setFramerateLimit(60);
    sf::Clock frameClock;
    float speed = 80.f;
    Background  fond;

    Spaceship ship;
    Animation *currentAnimation = ship.getAnim();
    AnimatedSprite  animatedSprite(sf::seconds(0.2), true, false);
    animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));

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
        animatedSprite.play(*currentAnimation);
        animatedSprite.move(movement * frameTime.asSeconds());
        animatedSprite.update(frameTime);

        window.clear();
        fond.Render(window);
        window.draw(animatedSprite);
        window.display();
    }
    return 0;
}
