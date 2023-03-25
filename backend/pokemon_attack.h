#ifndef POKEMON_ATTACK_H
#define POKEMON_ATTACK_H

#include <string>
#include "type.h"

class PokemonAttack {
protected:
    std::string name;
    unsigned short maxUsage; //aka cc, forse
    Type type;
    unsigned short currentUsage;
public:
    PokemonAttack(const std::string& s, unsigned short cc, const Type& t);
    Type getType() const;
    unsigned short getMaxUsage() const;
    unsigned short getCurrentUsage() const;
    void useMove();
};

#endif // POKEMON_ATTACK_H
