#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <cstdlib> 
#include <ctime>

class Enemy : public Entity {
public:
    Enemy();

    void movement(float deltaTime) override;
    void setObjective(Entity* target) override;
    bool objectiveTargeted() const override;

    void findClosestTarget(const std::vector<Entity*>& entities);

    void reduceMV(Entity* target);

private:
    Entity* target;
};

#endif // ENEMY_H
