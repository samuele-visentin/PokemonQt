#ifndef POKEMON_H
#define POKEMON_H

#include <list>
#include <string>
#include <vector>
#include "backend/type.h"
#include "backend/attacks/attack.h"

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
    std::list<Attack> attacks;
public:
    Pokemon(const std::string& username, int level, int health,
            int attack, int defense, int specialAttack,
            int specialDefense, int speed, const std::list<Attack>& vec
    );
    Pokemon(const Pokemon& p);
    Pokemon& operator=(const Pokemon& p);
    virtual ~Pokemon();
    virtual Pokemon* clone() const=0;
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
};

#endif // POKEMON_H
