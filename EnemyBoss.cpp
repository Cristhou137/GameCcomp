#include "EnemyBoss.h"
#include <cmath>

EnemyBoss::EnemyBoss() {
    shape.setFillColor(sf::Color::Magenta);
    hitbox.setOutlineColor(sf::Color::Green);
    directionIndicator.setFillColor(sf::Color::Green);
    setMovementSpeed(60.0f); // Inicialización de ejemplo de estadísticas en unidades por segundo
    Assignment(150, 8, 15, 8, 10, 10, 0.1f, 0.1f, 5, 60.0f, 1.0f, 0.1f); // Inicializar estadísticas
    shape.setPosition(400.0f, 400.0f); // Establecer posición inicial del enemigo
    updateHitbox();
    updateDirectionIndicator();
}

void EnemyBoss::movement(float deltaTime) {
    Enemy::movement(deltaTime);
}

void EnemyBoss::findClosestTarget(const std::vector<Entity*>& entities) {
    Entity* closestPlayer = nullptr;
    float closestDistance = std::numeric_limits<float>::max();

    for (Entity* entity : entities) {
        if (Player* player = dynamic_cast<Player*>(entity)) {
            float distance = std::sqrt(std::pow(player->getPosition().x - getPosition().x, 2) +
                std::pow(player->getPosition().y - getPosition().y, 2));
            if (distance < closestDistance && distance < 200.0f) { // Distancia de detección para el jefe enemigo
                closestDistance = distance;
                closestPlayer = player;
            }
        }
    }

    setObjective(closestPlayer);
}

void EnemyBoss::attack() {
    if (target) {
        // Aquí puedes agregar lógica para el ataque del jefe enemigo
    }
}


std::vector<EnemyBoss*> EnemyBoss::generateEnemies(int count) {
    std::vector<EnemyBoss*> enemies;
    for (int i = 0; i < count; ++i) {
        enemies.push_back(new EnemyBoss());
    }
    return enemies;
}

