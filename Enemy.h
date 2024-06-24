#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Player.h"
#include <vector>

class Enemy : public Entity {
public:
    Enemy();
    virtual void movement(float deltaTime) override;
    virtual void setObjective(Entity* target) override;
    virtual bool objectiveTargeted() const override;

    virtual void findClosestTarget(const std::vector<Entity*>& entities); // Declaración de findClosestTarget
    void reduceMV(Entity* target); // Declaración de reduceMV

    static std::vector<Enemy*> generateEnemies(int count, const sf::Vector2f& origin);
    void setPosition(const sf::Vector2f& position);

protected:
    Entity* target;
    float movementSpeed;
};

#endif // ENEMY_H
