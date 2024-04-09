#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>

enum class MenuOption {
    None,
    OnePlayer,
    TwoPlayers,
    Options,
    Extras,
    Exit,
    Back
};

class Menu {
public:
    Menu();
    ~Menu();

    void display(sf::RenderWindow& window);
    void handleEvent(sf::Event event);
    void setTitle(const std::string& titleText);
    void addOption(const std::string& optionText);
    void clearDisplay();
    void back();

private:
    void format(sf::Text& text, float x, float y, int characterSize);
    void mainMenu();
    MenuOption getMenuOption(const sf::Vector2f& mousePos); // Función corregida

    sf::Font font;
    sf::Text title;
    std::vector<sf::Text> options;
    std::vector<sf::RectangleShape> boundingBoxes; // Rectángulos delimitadores para las opciones
};

#endif