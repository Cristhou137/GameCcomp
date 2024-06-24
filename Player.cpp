#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player() : target(nullptr) {
    shape.setFillColor(sf::Color::Blue);
    hitbox.setOutlineColor(sf::Color::Green);
    directionIndicator.setFillColor(sf::Color::Green);
    setMovementSpeed(250.0f); 
    Assignment(100, 5, 10, 5, 10, 5, 0.1f, 0.1f, 5, 250.0f, 1.0f, 0.1f); 
    shape.setPosition(0.0f, 300.0f);
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

void Player::setPosition(const sf::Vector2f& position) {
    Entity::setPosition(position);
}