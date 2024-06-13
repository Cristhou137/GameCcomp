#include "MenuController.h"

MenuController::MenuController(Menu& menu) : menu(menu) {}

void MenuController::handleEvent(sf::Event event) {
    menu.handleEvent(event);
}
