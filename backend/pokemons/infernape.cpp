#include "infernape.h"

Infernape::Infernape(int health, int attack, int defense, int speed, const std::string& name)
    : Pokemon(Type::FIRE_TYPE, "infernape.png", name,
        {Attack::FIRE_BLAST, Attack::FLAMETHROWER, Attack::FLAME_WHEEL, Attack::EMBER},
        health, attack, defense, speed)
{}


PokemonTypology::typology Infernape::getTypology() const { return PokemonTypology::typology::infernape; }

Infernape* Infernape::clone() const {
    return new Infernape(*this);
}
