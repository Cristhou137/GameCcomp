#include "EnemyRange.h"

EnemyRange::EnemyRange() {
    shape.setFillColor(sf::Color::Yellow);
    hitbox.setOutlineColor(sf::Color::Green);
    directionIndicator.setFillColor(sf::Color::Green);
    setMovementSpeed(100.0f); // Inicialización de ejemplo de estadísticas en unidades por segundo
    Assignment(150, 8, 15, 8, 10, 10, 0.1f, 0.1f, 5, 100.0f, 1.0f, 0.1f); // Inicializar estadísticas
    shape.setPosition(400.0f, 400.0f); // Establecer posición inicial del enemigo
    updateHitbox();
    updateDirectionIndicator();
}

void EnemyRange::movement(float deltaTime) {
    Enemy::movement(deltaTime);
}

void EnemyRange::findClosestTarget(const std::vector<Entity*>& entities) {
    Entity* closestPlayer = nullptr;
    float closestDistance = std::numeric_limits<float>::max();

    for (Entity* entity : entities) {
        if (Player* player = dynamic_cast<Player*>(entity)) {
            float distance = std::sqrt(std::pow(player->getPosition().x - getPosition().x, 2) +
                std::pow(player->getPosition().y - getPosition().y, 2));
            if (distance < closestDistance && distance < 400.0f) { // Distancia de detección para los enemigos a distancia
                closestDistance = distance;
                closestPlayer = player;
            }
        }
    }

    setObjective(closestPlayer);
}

void EnemyRange::attack() {
    // Implementar ataque a distancia
}

std::vector<EnemyRange*> EnemyRange::generateEnemies(int count) {
    std::vector<EnemyRange*> enemies;
    for (int i = 0; i < count; ++i) {
        enemies.push_back(new EnemyRange());
    }
    return enemies;
}