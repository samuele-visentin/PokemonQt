#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "backend/status/status.h"
#include "backend/type.h"

class Attack;

class Pokemon {
private:
    //static const std::string _name;
    //static const Type _type;

    int _level;
    int _maxHealth;
    int _health;
    int _attack;
    int _defense;
    int _specialAttack;
    int _specialDefense;
    int _speed;
    Status* _status;
    std::vector<Attack>attacks;

public:
    Pokemon(const std::string& name, const Type& type, int level, int health, int attack, int defense, int specialAttack, int specialDefense, int speed, const std::vector<Attack>& vec);
    Pokemon(const Pokemon& p);
    Pokemon& operator=(const Pokemon& p);
    virtual ~Pokemon();
    std::string getName() const;
    Type getType() const;
    int getLevel() const;
    int getMaxHealth() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getSpecialAttack() const;
    int getSpecialDefense() const;
    int getSpeed() const;

    void setStatus(Status* status);
    void removeStatus();
    bool hasStatus() const;

    void setHealth(int health);
    void takeDamage(int damage);

    void attack(Pokemon& defender, int attackIndex);
};

#endif // POKEMON_H
