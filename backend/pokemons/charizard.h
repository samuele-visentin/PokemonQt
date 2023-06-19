#ifndef CHARIZARD_H
#define CHARIZARD_H

#include "pokemon.h"

class Charizard : public Pokemon
{
public:
    Charizard(int health, int attack, int defense, int speed, const std::string& name = "Charizard"); 
    Charizard* clone() const override;
    PokemonTypology::typology getTypology() const override;
};

#endif // CHARIZARD_H
