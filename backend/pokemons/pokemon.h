#ifndef POKEMON_H
#define POKEMON_H

#include <list>
#include <string>
#include <vector>
#include "backend/type.h"

class Attack;
class Status;

class Pokemon {
protected:
    static const Type _type;
    static const std::string _name;
    static const std::string sprite;
private:
    std::string _username;
    int _level;
    int _maxHealth;
    int _health;
    int _attack;
    int _defense;
    int _specialAttack;
    int _specialDefense;
    int _speed;
    Status* _status;
    std::list<Attack*> attacks;
    Pokemon(const Pokemon& p);
    Pokemon& operator=(const Pokemon& p);
public:
    Pokemon(const std::string& username, int level, int health,
            int attack, int defense, int specialAttack,
            int specialDefense, int speed, const std::list<Attack*>& vec
    );
    virtual ~Pokemon();
    virtual Pokemon* clone() const;
    std::string getName() const;
    int getLevel() const;
    int getMaxHealth() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getSpecialAttack() const;
    int getSpecialDefense() const;
    int getSpeed() const;
    const Attack& getAttack(int index) const;
    Type getType() const; 
    const Status& getStatus() const;
    void setStatus(Status* status);
    void removeStatus();
    bool hasStatus() const;
    void setHealth(int health);
    void takeDamage(int damage);
    void attack(Pokemon& defender, int attackIndex);
};

#endif // POKEMON_H
