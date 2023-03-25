#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "list.h"
#include "pokemon_status.h"
#include "type.h"

class Pokemon {
protected:
    std::string _name;
    List<int> move;
    unsigned int _level;
    PokemonStatus status;
    Type type;
    unsigned _maxHp;
    unsigned hp; //current vitality
    int _attack;
    int _defense;
    int _specialAttack;
    int _specialDefense;
    int _speed;
    bool isDead;

public:
    Pokemon(
            int attack,
            int defense,
            int specialAttack,
            int specialDefense,
            int speed = 100, 
            unsigned level = 1,
            unsigned maxHp = 100) :
        _level(level), _maxHp(maxHp), hp(maxHp),
        _attack(attack), _defense(defense), _specialAttack(specialAttack),
        _specialDefense(specialDefense), _speed(speed), isDead(false) {}
    virtual ~Pokemon() =default; //TODO: cambiare, forse
    virtual void takeDemage()=0;
    virtual void dealDemage()=0;
};

#endif // POKEMON_H
