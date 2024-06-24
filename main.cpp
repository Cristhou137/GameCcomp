#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EnemyMelee.h"
#include "EnemyRange.h"
#include "EnemyBoss.h"
#include <vector>
#include <algorithm> // Para std::remove_if

int main() {
    // Crear objetos del jugador y enemigos
    Player* player = new Player();

    // Generar enemigos
    std::vector<EnemyMelee*> meleeEnemies = EnemyMelee::generateEnemies(3);
    std::vector<EnemyRange*> rangeEnemies = EnemyRange::generateEnemies(2);
    std::vector<EnemyBoss*> bossEnemies = EnemyBoss::generateEnemies(1);

    // Posición de los enemigos
    sf::Vector2f meleePos(500.0f, 300.0f);
    sf::Vector2f rangePos(600.0f, 300.0f);
    sf::Vector2f bossPos(700.0f, 300.0f);

    for (auto& enemy : meleeEnemies) {
        enemy->setPosition(meleePos);
        meleePos.x += 50.0f;
    }

    for (auto& enemy : rangeEnemies) {
        enemy->setPosition(rangePos);
        rangePos.x += 50.0f;
    }

    for (auto& enemy : bossEnemies) {
        enemy->setPosition(bossPos);
        bossPos.x += 50.0f;
    }

    // Vector para almacenar todos los objetos del juego
    std::vector<Entity*> entities;
    entities.push_back(player);
    entities.insert(entities.end(), meleeEnemies.begin(), meleeEnemies.end());
    entities.insert(entities.end(), rangeEnemies.begin(), rangeEnemies.end());
    entities.insert(entities.end(), bossEnemies.begin(), bossEnemies.end());

    // Crear la ventana del juego
    sf::RenderWindow window(sf::VideoMode(1366, 768), "RPG Game");

    // Reloj para medir el tiempo entre fotogramas
    sf::Clock clock;

    // Bucle principal del juego
    while (window.isOpen()) {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calcular el tiempo transcurrido desde el último fotograma
        float deltaTime = clock.restart().asSeconds();

        // Actualizar el movimiento del jugador
        player->movement(deltaTime);

        // Actualizar el objetivo de los enemigos
        for (Entity* entity : entities) {
            if (Enemy* enemy = dynamic_cast<Enemy*>(entity)) {
                enemy->findClosestTarget(entities);
            }
        }

        // Actualizar el movimiento de los enemigos
        for (Entity* entity : entities) {
            if (Enemy* enemy = dynamic_cast<Enemy*>(entity)) {
                enemy->movement(deltaTime);
            }
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar todos los objetos del juego
        for (Entity* entity : entities) {
            entity->draw(window);
        }

        // Mostrar la ventana
        window.display();

        // Eliminar los objetos que han sido marcados para destrucción
        entities.erase(std::remove_if(entities.begin(), entities.end(), [](Entity* entity) {
            if (entity->isMarkedForDeath()) {
                delete entity;
                return true;
            }
            return false;
            }), entities.end());
    }

    // Liberar memoria restante
    for (Entity* entity : entities) {
        delete entity;
    }

    // Liberar memoria de los enemigos
    for (EnemyMelee* enemy : meleeEnemies) {
        delete enemy;
    }

    for (EnemyRange* enemy : rangeEnemies) {
        delete enemy;
    }

    for (EnemyBoss* enemy : bossEnemies) {
        delete enemy;
    }

    return 0;
}
