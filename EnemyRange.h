#ifndef ENEMYRANGE_H
#define ENEMYRANGE_H

#include "Enemy.h"

class EnemyRange : public Enemy {
public:
    EnemyRange();

    void movement(float deltaTime) override;
    void attack();
    void findClosestTarget(const std::vector<Entity*>& entities) override;

    static std::vector<EnemyRange*> generateEnemies(int count);

};

#endif // ENEMYRANGE_H
