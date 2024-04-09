#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MenuController.h"
#include "Settings.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(Settings::SCREEN_WIDTH, Settings::SCREEN_HEIGHT), "Menu Example");
    Menu menu;
    MenuController menuController(menu);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                menuController.handleEvent(event);
            }
        }

        menu.display(window);
    }

    return 0;
}
