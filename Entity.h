#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity(float radius, sf::Color color);
    virtual ~Entity();

    virtual void update(sf::RenderWindow& window) = 0;
    virtual void draw(sf::RenderWindow& window);
    virtual void setObjective(Entity* target) = 0;
    virtual bool objectiveTargeted() const = 0;
    virtual void updateDirectionIndicator() = 0;
    virtual void updateMovement(float deltaTime) = 0; 

protected:
    sf::CircleShape shape;
    sf::CircleShape hitbox;
    sf::CircleShape directionIndicator;

    int level;
    Entity* objective;

    void updateHitbox();
    void normalize(sf::Vector2f& vector);
};

#endif
