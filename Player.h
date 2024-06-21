#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    Player();

    void movement(float deltaTime) override;
    void setObjective(Entity* target) override;
    bool objectiveTargeted() const override;

private:
    Entity* target;
};

#endif // PLAYER_H
