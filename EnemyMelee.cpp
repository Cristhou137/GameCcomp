#include "EnemyMelee.h"

EnemyMelee::EnemyMelee() {
    shape.setFillColor(sf::Color::Red);
    hitbox.setOutlineColor(sf::Color::Green);
    directionIndicator.setFillColor(sf::Color::Green);
    setMovementSpeed(150.0f); // Inicialización de ejemplo de estadísticas en unidades por segundo
    Assignment(200, 10, 20, 10, 5, 5, 0.2f, 0.2f, 10, 150.0f, 1.0f, 0.1f); // Inicializar estadísticas
    shape.setPosition(300.0f, 300.0f); // Establecer posición inicial del enemigo
    updateHitbox();
    updateDirectionIndicator();
}

void EnemyMelee::movement(float deltaTime) {
    Enemy::movement(deltaTime);
}

void EnemyMelee::findClosestTarget(const std::vector<Entity*>& entities) {
    Entity* closestPlayer = nullptr;
    float closestDistance = std::numeric_limits<float>::max();

    for (Entity* entity : entities) {
        if (Player* player = dynamic_cast<Player*>(entity)) {
            float distance = std::sqrt(std::pow(player->getPosition().x - getPosition().x, 2) +
                std::pow(player->getPosition().y - getPosition().y, 2));
            if (distance < closestDistance && distance < 300.0f) { // Distancia de detección para los enemigos de melee
                closestDistance = distance;
                closestPlayer = player;
            }
        }
    }

    setObjective(closestPlayer);
}

void EnemyMelee::attack() {
    // Implementar ataque cuerpo a cuerpo
}

std::vector<EnemyMelee*> EnemyMelee::generateEnemies(int count) {
    std::vector<EnemyMelee*> enemies;
    for (int i = 0; i < count; ++i) {
        enemies.push_back(new EnemyMelee());
    }
    return enemies;
}