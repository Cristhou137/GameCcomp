#ifndef ENEMYBOSS_H
#define ENEMYBOSS_H

#include "Enemy.h"

class EnemyBoss : public Enemy {
public:
    EnemyBoss();

    void movement(float deltaTime) override;
    void attack();
    void findClosestTarget(const std::vector<Entity*>& entities) override;

    static std::vector<EnemyBoss*> generateEnemies(int count);

};

#endif // ENEMYBOSS_H
