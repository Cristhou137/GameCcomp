#include <SFML/Graphics.hpp>
#include "Hero.h"

int main() {
    Entity* player = new Hero();

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game");

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        static_cast<Player*>(player)->handleInput();

        player->updateMovement(deltaTime.asSeconds());


        window.clear();
        player->draw(window);
        window.display();
    }

    delete player;

    return 0;
}
