#ifndef HERO_H
#define HERO_H

#include "Player.h"

class Hero : public Player {
public:
    Hero(const Stats& stats = Stats(100, 5, 20, 10, 15, 12, 0.1f, 0.05f, 2, 9.0f, 1.5f, 10.0f));

    virtual void update(sf::RenderWindow& window) override;
    virtual void draw(sf::RenderWindow& window) override;
    virtual void setObjective(Entity* target) override;
    virtual bool objectiveTargeted() const override;
    virtual void updateDirectionIndicator() override;
};

#endif // HERO_H
