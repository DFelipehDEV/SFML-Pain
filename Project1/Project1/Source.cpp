#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(480, 270), "SFML works!");
    sf::View view0(sf::FloatRect(0, 0, 480, 270));
    sf::Clock clock;
    Player player;

    window.setFramerateLimit(60);
    window.setView(view0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time time = clock.getElapsedTime();
        player.update();
        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}