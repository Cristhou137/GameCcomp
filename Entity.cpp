#include "Entity.h"

Entity::Entity() : markedForDeath(false) {
    shape.setRadius(20.0f);
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(20.0f, 20.0f);

    hitbox.setSize(sf::Vector2f(40.0f, 40.0f));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Green);
    hitbox.setOutlineThickness(2.0f);
    hitbox.setOrigin(20.0f, 20.0f);

    directionIndicator.setPointCount(3);
    directionIndicator.setPoint(0, sf::Vector2f(0, 0));
    directionIndicator.setPoint(1, sf::Vector2f(-10, 20));
    directionIndicator.setPoint(2, sf::Vector2f(10, 20));
    directionIndicator.setFillColor(sf::Color::Green);
    directionIndicator.setOrigin(0, 10);
}

Entity::~Entity() {}

sf::Vector2f Entity::getPosition() const {
    return shape.getPosition();
}

void Entity::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(hitbox);
    window.draw(directionIndicator);
}

void Entity::updateHitbox() {
    hitbox.setPosition(shape.getPosition());
}

void Entity::updateDirectionIndicator() {
    directionIndicator.setPosition(shape.getPosition());
}

void Entity::normalize(sf::Vector2f& vector) {
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length != 0)
        vector /= length;
}

void Entity::setHealth(int value) {
    health = value;
    if (health <= 0) {
        Death();  // Llamar a Death si la salud llega a cero o menos
    }
}

int Entity::getHealth() const {
    return health;
}

void Entity::setHealthRegen(int value) {
    healthRegen = value;
}

int Entity::getHealthRegen() const {
    return healthRegen;
}

void Entity::setAttackDamage(int value) {
    attackDamage = value;
}

int Entity::getAttackDamage() const {
    return attackDamage;
}

void Entity::setArmor(int value) {
    armor = value;
}

int Entity::getArmor() const {
    return armor;
}

void Entity::setMagicPower(int value) {
    magicPower = value;
}

int Entity::getMagicPower() const {
    return magicPower;
}

void Entity::setMagicResistance(int value) {
    magicResistance = value;
}

int Entity::getMagicResistance() const {
    return magicResistance;
}

void Entity::setEvasionChance(float value) {
    evasionChance = value;
}

float Entity::getEvasionChance() const {
    return evasionChance;
}

void Entity::setCriticalChance(float value) {
    criticalChance = value;
}

float Entity::getCriticalChance() const {
    return criticalChance;
}

void Entity::setLifeSteal(int value) {
    lifeSteal = value;
}

int Entity::getLifeSteal() const {
    return lifeSteal;
}

void Entity::setMovementSpeed(float value) {
    movementSpeed = value;
}

float Entity::getMovementSpeed() const {
    return movementSpeed;
}

void Entity::setAttackSpeed(float value) {
    attackSpeed = value;
}

float Entity::getAttackSpeed() const {
    return attackSpeed;
}

void Entity::setCooldownReduction(float value) {
    cooldownReduction = value;
}

float Entity::getCooldownReduction() const {
    return cooldownReduction;
}

void Entity::setPosition(const sf::Vector2f& position) {
    shape.setPosition(position);
    hitbox.setPosition(position);
    directionIndicator.setPosition(position);
}

void Entity::Assignment(int health, int healthRegen, int attackDamage, int armor,
    int magicPower, int magicResistance, float evasionChance, float criticalChance,
    int lifeSteal, float movementSpeed, float attackSpeed, float cooldownReduction) {
    setHealth(health);
    setHealthRegen(healthRegen);
    setAttackDamage(attackDamage);
    setArmor(armor);
    setMagicPower(magicPower);
    setMagicResistance(magicResistance);
    setEvasionChance(evasionChance);
    setCriticalChance(criticalChance);
    setLifeSteal(lifeSteal);
    setMovementSpeed(movementSpeed);
    setAttackSpeed(attackSpeed);
    setCooldownReduction(cooldownReduction);
}

void Entity::Death() {
    markedForDeath = true;  // Marcar para destrucción
}

bool Entity::isMarkedForDeath() const {
    return markedForDeath;
}
