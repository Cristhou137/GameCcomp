#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player() : target(nullptr) {
    shape.setFillColor(sf::Color::Blue);
    hitbox.setOutlineColor(sf::Color::Green);
    directionIndicator.setFillColor(sf::Color::Green);
    setMovementSpeed(250.0f); // Inicialización de ejemplo de estadísticas en unidades por segundo
    Assignment(100, 5, 10, 5, 10, 5, 0.1f, 0.1f, 5, 250.0f, 1.0f, 0.1f); // Inicializar estadísticas
    shape.setPosition(0.0f, 300.0f); // Establecer posición inicial del enemigo
    updateHitbox();
    updateDirectionIndicator();
}

void Player::movement(float deltaTime) {
    sf::Vector2f direction(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction.y -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction.y += 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction.x -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction.x += 1.0f;

    normalize(direction);
    shape.move(direction * movementSpeed * deltaTime);
    updateHitbox();
    updateDirectionIndicator();
}

void Player::setObjective(Entity* target) {
    this->target = target;
    if (target) {
        directionIndicator.setFillColor(sf::Color::Red);
    }
    else {
        directionIndicator.setFillColor(sf::Color::Green);
    }
}

bool Player::objectiveTargeted() const {
    return target != nullptr;
}
