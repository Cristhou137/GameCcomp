#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Stats.h"

class Player : public Entity {
public:
    Player(const Stats& stats);
    virtual ~Player();

    virtual void update(sf::RenderWindow& window) override;
    virtual void draw(sf::RenderWindow& window) override;
    virtual void setObjective(Entity* target) override;
    virtual bool objectiveTargeted() const override;
    virtual void updateDirectionIndicator() override;
    virtual void updateMovement(float deltaTime) override; 
    void handleInput(); 

private:
    Stats playerStats;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif 
