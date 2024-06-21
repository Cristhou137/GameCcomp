#include "Enemy.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

Enemy::Enemy() : target(nullptr) {
    shape.setFillColor(sf::Color::Red);
    hitbox.setOutlineColor(sf::Color::Green);
    directionIndicator.setFillColor(sf::Color::Green);
    setMovementSpeed(100.0f); // Inicialización de ejemplo de estadísticas en unidades por segundo
    Assignment(100, 5, 10, 5, 10, 5, 0.1f, 0.1f, 5, 100.0f, 1.0f, 0.1f); // Inicializar estadísticas
    shape.setPosition(300.0f, 300.0f); // Establecer posición inicial del enemigo
    updateHitbox();
    updateDirectionIndicator();
}

void Enemy::movement(float deltaTime) {
    if (target) {
        sf::Vector2f direction = target->getPosition() - shape.getPosition();
        float distance = std::abs(direction.x) + std::abs(direction.y); // Distancia en píxeles

        if (distance <= 250.0f) { // Radio de distancia requerido
            normalize(direction);
            shape.move(direction * movementSpeed * deltaTime);
            updateHitbox();
            updateDirectionIndicator();
        }
        else {
            target = nullptr; // Perder el objetivo si está fuera de rango
        }
    }
}

void Enemy::setObjective(Entity* target) {
    this->target = target;
    if (target) {
        directionIndicator.setFillColor(sf::Color::Red);
    }
    else {
        directionIndicator.setFillColor(sf::Color::Green);
    }
}

bool Enemy::objectiveTargeted() const {
    return target != nullptr;
}

void Enemy::findClosestTarget(const std::vector<Entity*>& entities) {
    float closestDistance = 250.0f; // Radio de distancia máximo inicial
    Entity* closestEntity = nullptr;

    for (Entity* entity : entities) {
        if (entity != this) {
            sf::Vector2f direction = entity->getPosition() - shape.getPosition();
            float distance = std::abs(direction.x) + std::abs(direction.y); // Distancia en píxeles
            if (distance < closestDistance) {
                closestDistance = distance;
                closestEntity = entity;
            }
        }
    }

    setObjective(closestEntity);
}

void Enemy::reduceMV(Entity* target) {
    // Verificar si hay un objetivo y está lo suficientemente cerca
    if (target && objectiveTargeted()) {
        sf::Vector2f direction = target->getPosition() - shape.getPosition();
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        // Si el objetivo está lo suficientemente cerca
        if (distance <= 120.0f) { // Ajusta la distancia según sea necesario
            // Si la habilidad reduceMV no está en cooldown
            if (getCooldownSeconds() <= 0.0f) {
                // Hacer que la velocidad del objetivo se reduzca en un 60%
                float reductionFactor = 0.6f;
                float currentSpeed = target->getMovementSpeed();
                float newSpeed = currentSpeed * reductionFactor;
                target->setMovementSpeed(newSpeed);

                // Establecer el cooldown de la habilidad en 20 segundos
                setCooldownSeconds(20.0f);
            }
        }
    }

    // Actualizar el cooldown de la habilidad
    if (getCooldownSeconds() > 0.0f) {
        // Si el cooldown es mayor a 0, reducirlo en 1 cada segundo
        setCooldownSeconds(getCooldownSeconds() - 1.0f); // Suponiendo que deltaTime es 1 segundo
    }
}