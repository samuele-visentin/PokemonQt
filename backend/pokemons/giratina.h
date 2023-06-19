#ifndef GIRATINA_H
#define GIRATINA_H

#include "pokemon.h"

class Giratina : public Pokemon
{
public:
    Giratina(int health, int attack, int defense, int speed, const std::string& name="Giratina");
    PokemonTypology::typology getTypology() const override;
    Giratina* clone() const override;
};

#endif // GIRATINA_H
