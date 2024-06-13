#include "Hero.h"

Hero::Hero(const Stats& stats)
    : Player(stats) {
}

void Hero::update(sf::RenderWindow& window) {
    Player::update(window);
}

void Hero::draw(sf::RenderWindow& window) {
    Player::draw(window);
}

void Hero::setObjective(Entity* target) {
    Player::setObjective(target);
}

bool Hero::objectiveTargeted() const {
    return Player::objectiveTargeted();
}

void Hero::updateDirectionIndicator() {
    Player::updateDirectionIndicator();
}
