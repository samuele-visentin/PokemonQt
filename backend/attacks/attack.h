#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include "../pokemons/pokemon.h"

class Attack {
protected:
    std::string name;
    unsigned short maxUsage; //aka cc, forse
    unsigned short currentUsage;
    int power;
    float accuracy;
public:
    Attack(const std::string& s, unsigned short cc, int power, float accuracy);
    virtual ~Attack() = default;
    unsigned short getMaxUsage() const;
    unsigned short getCurrentUsage() const;
    virtual void useMove(Pokemon& attacker, Pokemon& defender)=0;
};

#endif // ATTACK_H
