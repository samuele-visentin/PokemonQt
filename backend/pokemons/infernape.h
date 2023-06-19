#ifndef INFERNAPE_H
#define INFERNAPE_H

#include "pokemon.h"

class Infernape : public Pokemon
{
public:
    Infernape(int health, int attack, int defense, int speed, const std::string& name = "Infernape");
    PokemonTypology::typology getTypology() const override;
    Infernape* clone() const override;
};

#endif // INFERNAPE_H
