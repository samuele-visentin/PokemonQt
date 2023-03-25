#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "list.h"
#include "status.h"
#include "type.h"

class Pokemon {
private:
    std::string _name;
    Type _type;
    int _level;
    int _maxHealth;
    int _health;
    int _attack;
    int _defense;
    int _specialAttack;
    int _specialDefense;
    int _speed;
    Status* _status;

public:
    Pokemon(const std::string& name, const Type& type, int level, int health, int attack, int defense, int specialAttack, int specialDefense, int speed);
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

    void applyStatus(Status* status);
    void removeStatus();
    bool hasStatus() const;

    void setHealth(int health);

    virtual void attack(Pokemon& other) = 0 ;
};

#endif // POKEMON_H
