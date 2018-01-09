#include "../include/GameEngine.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "R-Type");
    sf::Uint8* pixels = new sf::Uint8[WIDTH * HEIGHT * 4];
    sf::Sprite  sprite;
    sf::Texture texture;

    if (!texture.loadFromFile("ressources/sprites/main_ship.gif"))
    {
      std::cerr << "Error : can't load sprite" << std::endl;
      return 84;
    }
    sprite.setTexture(texture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
