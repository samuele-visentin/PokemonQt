#ifndef DARKRAI_H
#define DARKRAI_H

#include "pokemon.h"

class Darkrai : public Pokemon
{
public:
    Darkrai(int health, int attack, int defense, int speed, const std::string& name = "Darkrai");
    PokemonTypology::typology getTypology() const override;
    Darkrai* clone() const override;
};

#endif // DARKRAI_H
