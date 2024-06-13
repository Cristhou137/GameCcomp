#include "Menu.h"
#include "Settings.h"
#include <iostream>

Menu::Menu() {
    if (!font.loadFromFile("assets/04B_31_.ttf")) {
        // Manejo de error si no se pudo cargar la fuente
    }

    mainMenu();
}

Menu::~Menu() {
    // Destructor, no hace nada especial por ahora
}

void Menu::display(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    window.draw(title);
    for (std::size_t i = 0; i < options.size(); ++i) {
        window.draw(boundingBoxes[i]); // Dibujar el cuadro delimitador
        window.draw(options[i]);
    }

    window.display();
}

void Menu::format(sf::Text& text, float x, float y, int characterSize) {
    text.setFont(font);
    text.setCharacterSize(characterSize);
    text.setFillColor(sf::Color::White);
    text.setPosition(x - 0.5f * text.getGlobalBounds().width, y);
}

void Menu::handleEvent(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            MenuOption selectedOption = getMenuOption(mousePos);
            switch (selectedOption) {
            case MenuOption::OnePlayer:
                // Realizar acción para la opción "1 Player"
                break;
            case MenuOption::TwoPlayers:
                // Realizar acción para la opción "Two Players"
                break;
            case MenuOption::Options:
                // Realizar acción para la opción "Options"
                clearDisplay();
                setTitle("Options");
                addOption("Width");
                addOption("Height");
                break;
            case MenuOption::Extras:
                // Realizar acción para la opción "Extras"
                break;
            case MenuOption::Exit:
                // Realizar acción para la opción "Exit"
                break;
            default:
                break;

            }
        }
    }
}

void Menu::mainMenu() {
    setTitle("Menu");

    float centerY = Settings::SCREEN_HEIGHT * 0.5f;
    float optionHeight = font.getLineSpacing(20);
    float startY = centerY - 0.5f * (5 * optionHeight + 4 * 50); // Calcular posición vertical de las opciones

    addOption("1 Player");
    addOption("Two Players");
    addOption("Options");
    addOption("Extras");
    addOption("Exit");

}

void Menu::back() {
}


void Menu::setTitle(const std::string& titleText) {
    title.setString(titleText);
    format(title, Settings::SCREEN_WIDTH * 0.5f, 100, 30);
}

void Menu::addOption(const std::string& optionText) {
    sf::Text option(optionText, font, 20);
    format(option, Settings::SCREEN_WIDTH * 0.5f, options.empty() ? 200 : options.back().getPosition().y + font.getLineSpacing(20) + 50, 20);

    // Crear un cuadro delimitador transparente alrededor de la opción
    sf::RectangleShape boundingBox(sf::Vector2f(option.getGlobalBounds().width + 20, option.getGlobalBounds().height + 10));
    boundingBox.setFillColor(sf::Color(255, 255, 255, 50)); // Transparente
    boundingBox.setPosition(option.getPosition().x - 10, option.getPosition().y);

    options.push_back(option);
    boundingBoxes.push_back(boundingBox); // Guardar el cuadro delimitador en el mismo orden que las opciones
}

void Menu::clearDisplay() {
    setTitle("");
    options.clear();
}

MenuOption Menu::getMenuOption(const sf::Vector2f& mousePos) {
    for (std::size_t i = 0; i < options.size(); ++i) {
        if (options[i].getGlobalBounds().contains(mousePos)) {
            return static_cast<MenuOption>(i + 1); // +1 porque MenuOption::None tiene valor 0
        }
    }
    return MenuOption::None;
}