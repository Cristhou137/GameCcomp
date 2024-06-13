#include "Stats.h"

Stats::Stats(int health, int healthRegen, int attackDamage, int armor, int magicPower, int magicResistance,
    float evasionChance, float critChance, int lifeSteal, float movementSpeed, float attackSpeed, float cooldownReduction)
    : health(health), healthRegen(healthRegen), attackDamage(attackDamage), armor(armor),
    magicPower(magicPower), magicResistance(magicResistance), evasionChance(evasionChance),
    critChance(critChance), lifeSteal(lifeSteal), movementSpeed(movementSpeed), attackSpeed(attackSpeed),
    cooldownReduction(cooldownReduction) {}

int Stats::getHealth() const { return health; }
int Stats::getHealthRegen() const { return healthRegen; }
int Stats::getAttackDamage() const { return attackDamage; }
int Stats::getArmor() const { return armor; }
int Stats::getMagicPower() const { return magicPower; }
int Stats::getMagicResistance() const { return magicResistance; }
float Stats::getEvasionChance() const { return evasionChance; }
float Stats::getCritChance() const { return critChance; }
int Stats::getLifeSteal() const { return lifeSteal; }
float Stats::getMovementSpeed() const { return movementSpeed; }
float Stats::getAttackSpeed() const { return attackSpeed; }
float Stats::getCooldownReduction() const { return cooldownReduction; }
float Stats::getAdjustedMovementSpeed(float deltaTime) const {
    return movementSpeed * deltaTime;
}

// Setters
void Stats::setHealth(int health) { this->health = health; }
void Stats::setHealthRegen(int healthRegen) { this->healthRegen = healthRegen; }
void Stats::setAttackDamage(int attackDamage) { this->attackDamage = attackDamage; }
void Stats::setArmor(int armor) { this->armor = armor; }
void Stats::setMagicPower(int magicPower) { this->magicPower = magicPower; }
void Stats::setMagicResistance(int magicResistance) { this->magicResistance = magicResistance; }
void Stats::setEvasionChance(float evasionChance) { this->evasionChance = evasionChance; }
void Stats::setCritChance(float critChance) { this->critChance = critChance; }
void Stats::setLifeSteal(int lifeSteal) { this->lifeSteal = lifeSteal; }
void Stats::setMovementSpeed(float movementSpeed) { this->movementSpeed = movementSpeed; }
void Stats::setAttackSpeed(float attackSpeed) { this->attackSpeed = attackSpeed; }
void Stats::setCooldownReduction(float cooldownReduction) { this->cooldownReduction = cooldownReduction; }

// Métodos específicos
void Stats::applyDamage(int damage) {
    health -= calculateDamageReduction(damage);
}

void Stats::applyMagicDamage(int damage) {
    health -= calculateMagicReduction(damage);
}

int Stats::calculateDamageReduction(int damage) const {
    return damage - armor; 
}

int Stats::calculateMagicReduction(int damage) const {
    return damage - magicResistance; 
}

void Stats::applyLifeSteal(int damageDealt) {
    health += damageDealt * lifeSteal / 100;
}

float Stats::getCooldownReductionFactor() const {
    return 1.0f - cooldownReduction / 100.0f;
}
