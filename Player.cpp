#include "Player.h"
#include <iostream>

Player::Player(const Stats& stats)
    : Entity(50, sf::Color::Blue), playerStats(stats) {
    playerStats.setMovementSpeed(1.0f);
}

Player::~Player() {}

void Player::update(sf::RenderWindow& window) {
    Entity::updateHitbox();
    updateDirectionIndicator();
}

void Player::draw(sf::RenderWindow& window) {
    Entity::draw(window);
}

void Player::setObjective(Entity* target) {
    objective = target;
}

bool Player::objectiveTargeted() const {
    return objective != nullptr;
}

void Player::updateDirectionIndicator() {
    if (objective) {
        directionIndicator.setFillColor(sf::Color::Red);
    }
    else {
        directionIndicator.setFillColor(sf::Color::Green);
    }
    directionIndicator.setPosition(shape.getPosition().x + shape.getRadius(), shape.getPosition().y + shape.getRadius());
}

void Player::updateMovement(float deltaTime) {
    float movementSpeed = playerStats.getAdjustedMovementSpeed(deltaTime);
    sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= movementSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += movementSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= movementSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += movementSpeed;

    shape.move(movement);
    updateHitbox();
    updateDirectionIndicator();
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) moveUp();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) moveDown();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) moveLeft();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) moveRight();
}

void Player::moveUp() {
    sf::Vector2f direction(0.0f, -playerStats.getMovementSpeed());
    shape.move(direction);
    updateHitbox();
    updateDirectionIndicator();
}

void Player::moveDown() {
    sf::Vector2f direction(0.0f, playerStats.getMovementSpeed());
    shape.move(direction);
    updateHitbox();
    updateDirectionIndicator();
}

void Player::moveLeft() {
    sf::Vector2f direction(-playerStats.getMovementSpeed(), 0.0f);
    shape.move(direction);
    updateHitbox();
    updateDirectionIndicator();
}

void Player::moveRight() {
    sf::Vector2f direction(playerStats.getMovementSpeed(), 0.0f);
    shape.move(direction);
    updateHitbox();
    updateDirectionIndicator();
}
