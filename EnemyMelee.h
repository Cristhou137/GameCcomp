#ifndef ENEMYMELEE_H
#define ENEMYMELEE_H

#include "Enemy.h"

class EnemyMelee : public Enemy {
public:
    EnemyMelee();

    void movement(float deltaTime) override;
    void attack();
    void findClosestTarget(const std::vector<Entity*>& entities) override;

    static std::vector<EnemyMelee*> generateEnemies(int count);

};

#endif // ENEMYMELEE_H
