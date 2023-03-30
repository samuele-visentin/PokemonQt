#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include "../pokemons/pokemon.h"

class Attack {
private:
    std::string name;
    unsigned short maxUsage; //aka cc, forse
    unsigned short currentUsage;
    int power;
    float accuracy;
public:
    Attack(const std::string& s, unsigned short cc, int power, float accuracy);
    virtual ~Attack() = default;
    std::string getName() const;
    unsigned short getMaxUsage() const;
    unsigned short getCurrentUsage() const;
    virtual void useMove(Pokemon& attacker, Pokemon& defender)=0;
    int getPower() const;
    float getAccuracy() const;
};

#endif // ATTACK_H
