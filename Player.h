#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    Player();

    void movement(float deltaTime) override;
    void setObjective(Entity* target) override;
    bool objectiveTargeted() const override;

    void setPosition(const sf::Vector2f& position);

private:
    Entity* target;
};

#endif // PLAYER_H
