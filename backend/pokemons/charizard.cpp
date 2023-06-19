#include "charizard.h"

Charizard::Charizard(int health, int attack, int defense, int speed, const std::string& name)
    : Pokemon(Type::FIRE_TYPE, "charizard.png", name,
        {Attack::FIRE_BLAST, Attack::FLAMETHROWER, Attack::FLAME_WHEEL, Attack::EMBER},
        health, attack, defense, speed)
{}

PokemonTypology::typology Charizard::getTypology() const { return PokemonTypology::typology::charizard; }

Charizard* Charizard::clone() const {
    return new Charizard(*this);
}
