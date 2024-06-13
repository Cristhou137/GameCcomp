#ifndef STATS_H
#define STATS_H

class Stats {
public:
    Stats(int health, int healthRegen, int attackDamage, int armor, int magicPower, int magicResistance,
        float evasionChance, float critChance, int lifeSteal, float movementSpeed, float attackSpeed, float cooldownReduction);

    int getHealth() const;
    int getHealthRegen() const;
    int getAttackDamage() const;
    int getArmor() const;
    int getMagicPower() const;
    int getMagicResistance() const;
    float getEvasionChance() const;
    float getCritChance() const;
    int getLifeSteal() const;
    float getMovementSpeed() const;
    float getAttackSpeed() const;
    float getCooldownReduction() const;
    float getAdjustedMovementSpeed(float deltaTime) const; 

    void setHealth(int health);
    void setHealthRegen(int healthRegen);
    void setAttackDamage(int attackDamage);
    void setArmor(int armor);
    void setMagicPower(int magicPower);
    void setMagicResistance(int magicResistance);
    void setEvasionChance(float evasionChance);
    void setCritChance(float critChance);
    void setLifeSteal(int lifeSteal);
    void setMovementSpeed(float movementSpeed);
    void setAttackSpeed(float attackSpeed);
    void setCooldownReduction(float cooldownReduction);

    void applyDamage(int damage);
    void applyMagicDamage(int damage);
    int calculateDamageReduction(int damage) const;
    int calculateMagicReduction(int damage) const;
    void applyLifeSteal(int damageDealt);
    float getCooldownReductionFactor() const;

private:
    int health;
    int healthRegen;
    int attackDamage;
    int armor;
    int magicPower;
    int magicResistance;
    float evasionChance;
    float critChance;
    int lifeSteal;
    float movementSpeed;
    float attackSpeed;
    float cooldownReduction;
};

#endif