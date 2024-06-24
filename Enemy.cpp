#include "Enemy.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

Enemy::Enemy() : target(nullptr) {
    shape.setFillColor(sf::Color::Red);
    movementSpeed = 100.0f; // Velocidad de movimiento de ejemplo
}

void Enemy::movement(float deltaTime) {
    if (target) {
        sf::Vector2f direction = target->getPosition() - shape.getPosition();
        normalize(direction);
        shape.move(direction * movementSpeed * deltaTime);
        updateHitbox();
        updateDirectionIndicator();
    }
}

void Enemy::setObjective(Entity* target) {
    this->target = target;
}

bool Enemy::objectiveTargeted() const {
    return target != nullptr;
}

void Enemy::findClosestTarget(const std::vector<Entity*>& entities) {
    Entity* closestPlayer = nullptr;
    float closestDistance = std::numeric_limits<float>::max();

    for (Entity* entity : entities) {
        if (Player* player = dynamic_cast<Player*>(entity)) {
            float distance = std::sqrt(std::pow(player->getPosition().x - getPosition().x, 2) +
                std::pow(player->getPosition().y - getPosition().y, 2));
            if (distance < closestDistance) {
                closestDistance = distance;
                closestPlayer = player;
            }
        }
    }

    setObjective(closestPlayer);
}

void Enemy::reduceMV(Entity* target) {
    if (target && objectiveTargeted()) {
        float distance = std::sqrt(std::pow(target->getPosition().x - getPosition().x, 2) +
            std::pow(target->getPosition().y - getPosition().y, 2));
        if (distance <= 120.0f) {
            int chance = std::rand() % 8; // Probabilidad de 1/8
            if (chance == 0) {
                float reductionFactor = 0.6f;
                float currentSpeed = target->getMovementSpeed();
                float newSpeed = currentSpeed * reductionFactor;
                target->setMovementSpeed(newSpeed);
            }
        }
    }
}

std::vector<Enemy*> Enemy::generateEnemies(int count, const sf::Vector2f& origin) {
    std::vector<Enemy*> enemies;
    for (int i = 0; i < count; ++i) {
        Enemy* enemy = new Enemy();
        enemy->shape.setPosition(origin);
        enemies.push_back(enemy);
    }
    return enemies;
}

void Enemy::setPosition(const sf::Vector2f& position) {
    Entity::setPosition(position);
}