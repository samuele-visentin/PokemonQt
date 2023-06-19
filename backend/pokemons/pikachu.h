#ifndef PIKACHU_H
#define PIKACHU_H

#include "pokemon.h"

class Pikachu : public Pokemon
{
public:
    Pikachu(int health, int attack, int defense, int speed, const std::string& name = "Pikachua");
    PokemonTypology::typology getTypology() const override;
    Pikachu* clone() const override;
};

#endif // PIKACHU_H
