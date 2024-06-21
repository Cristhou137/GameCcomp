#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include <vector>

int main() {
    // Crear objetos del jugador y enemigo
    Entity* player = new Player();
    Entity* enemy = new Enemy();

    // Vector para almacenar todos los objetos del juego
    std::vector<Entity*> entities = { player, enemy };

    // Crear la ventana del juego
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game");

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
        dynamic_cast<Enemy*>(enemy)->findClosestTarget(entities);

        // Actualizar el movimiento de los enemigos
        enemy->movement(deltaTime);

        // Ejecutar la habilidad reduceMV del enemigo
        dynamic_cast<Enemy*>(enemy)->reduceMV(player);

        // Limpiar la ventana
        window.clear();

        // Dibujar todos los objetos del juego
        for (Entity* entity : entities) {
            entity->draw(window);
        }

        // Mostrar la ventana
        window.display();
    }

    // Liberar memoria
    delete player;
    delete enemy;

    return 0;
}
