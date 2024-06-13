#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "Menu.h"

class MenuController {
public:
    MenuController(Menu& menu);
    void handleEvent(sf::Event event);

private:
    Menu& menu;
};

#endif
#pragma once
