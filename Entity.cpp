#include "Entity.h"

Entity::Entity(float radius, sf::Color color) : level(1), objective(nullptr) {
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setPosition(600, 300);

    hitbox.setRadius(radius);
    hitbox.setOutlineThickness(2);
    hitbox.setOutlineColor(sf::Color::Green);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setPosition(shape.getPosition());

    directionIndicator.setPointCount(3);
    directionIndicator.setRadius(20);
    directionIndicator.setFillColor(sf::Color::Green);
    directionIndicator.setOrigin(20, 20);
    directionIndicator.setRotation(90); 
    directionIndicator.setPosition(shape.getPosition().x + radius, shape.getPosition().y + 2 * radius);
}

Entity::~Entity() {}

void Entity::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(hitbox);
    window.draw(directionIndicator);
}

void Entity::updateHitbox() {
    hitbox.setPosition(shape.getPosition());
}

void Entity::normalize(sf::Vector2f& vector) {
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length != 0) {
        vector.x /= length;
        vector.y /= length;
    }
}
