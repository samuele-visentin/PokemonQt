#include "pokemon_attack.h"

PokemonAttack::PokemonAttack(const std::string& s, unsigned short cc, const Type& t) :
    name(s), maxUsage(cc), type(t), currentUsage(cc){}

Type PokemonAttack::getType() const {
    return type;
}

unsigned short PokemonAttack::getMaxUsage() const {
    return maxUsage;
}

unsigned short PokemonAttack::getCurrentUsage() const {
    return currentUsage;
}

void PokemonAttack::useMove() {
    if(currentUsage == 0) throw "CC Underflow"; //TODO
    currentUsage -= 1;
}
