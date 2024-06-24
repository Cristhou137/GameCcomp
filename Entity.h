#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity();
    virtual ~Entity();

    virtual void movement(float deltaTime) = 0;
    virtual void setObjective(Entity* target) = 0;
    virtual bool objectiveTargeted() const = 0;
    virtual void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;

    void setPosition(const sf::Vector2f& position);

    void setHealth(int value);
    int getHealth() const;

    void setHealthRegen(int value);
    int getHealthRegen() const;

    void setAttackDamage(int value);
    int getAttackDamage() const;

    void setArmor(int value);
    int getArmor() const;

    void setMagicPower(int value);
    int getMagicPower() const;

    void setMagicResistance(int value);
    int getMagicResistance() const;

    void setEvasionChance(float value);
    float getEvasionChance() const;

    void setCriticalChance(float value);
    float getCriticalChance() const;

    void setLifeSteal(int value);
    int getLifeSteal() const;

    void setMovementSpeed(float value);
    float getMovementSpeed() const;

    void setAttackSpeed(float value);
    float getAttackSpeed() const;

    void setCooldownReduction(float value);
    float getCooldownReduction() const;

    void Assignment(int health, int healthRegen, int attackDamage, int armor,
        int magicPower, int magicResistance, float evasionChance, float criticalChance,
        int lifeSteal, float movementSpeed, float attackSpeed, float cooldownReduction);

    void Death();  // Añadir la función Death
    bool isMarkedForDeath() const;  // Método para comprobar si está marcado para destrucción

protected: // Cambiar de private a protected
    sf::CircleShape shape;
    sf::RectangleShape hitbox;
    sf::ConvexShape directionIndicator;

    void updateHitbox();
    void updateDirectionIndicator();
    void normalize(sf::Vector2f& vector);

    int health;
    int healthRegen;
    int attackDamage;
    int armor;
    int magicPower;
    int magicResistance;
    float evasionChance;
    float criticalChance;
    int lifeSteal;
    float movementSpeed;
    float attackSpeed;
    float cooldownReduction;

    bool markedForDeath;  // Añadir un flag para marcar la destrucción
};

#endif // ENTITY_H
