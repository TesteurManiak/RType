#include "../include/AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDTH 800
#define HEIGHT 600

int main()
{
    sf::Vector2i screenDimensions(WIDTH, HEIGHT);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Game Engine");
    window.setFramerateLimit(60);
    sf::Texture texture;

    if (!texture.loadFromFile("ressources/sprites/main_ship.gif"))
    {
      std::cerr << "Error : can't load sprite" << std::endl;
      return -1;
    }

    Animation shipAnimation(33, 17);
    shipAnimation.setSpriteSheet(texture);
    shipAnimation.addFrame(sf::IntRect(0, 0, 33, 17));
    shipAnimation.addFrame(sf::IntRect(33, 0, 33, 17));
    shipAnimation.addFrame(sf::IntRect(66, 0, 33, 17));
    shipAnimation.addFrame(sf::IntRect(99, 0, 33, 17));

    Animation *currentAnimation = &shipAnimation;
    AnimatedSprite  animatedSprite(sf::seconds(0.2), true, false);
    animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));

    sf::Clock frameClock;
    float speed = 80.f;
    bool  noKeyWasPressed = true;

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
        {
            movement.y -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            movement.y += speed;
            noKeyWasPressed = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            movement.x -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            movement.x += speed;
            noKeyWasPressed = false;
        }
        animatedSprite.play(*currentAnimation);
        animatedSprite.move(movement * frameTime.asSeconds());

        if (noKeyWasPressed)
        {
            animatedSprite.stop();
        }
        noKeyWasPressed = true;
        animatedSprite.update(frameTime);

        window.clear();
        window.draw(animatedSprite);
        window.display();
    }
    return 0;
}
