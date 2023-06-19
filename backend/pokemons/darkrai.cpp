#include "darkrai.h"

Darkrai::Darkrai(int health, int attack, int defense, int speed, const std::string& name)
    : Pokemon(Type::DARK_TYPE, "darkrai.png", name,
        {Attack::DIG, Attack::NIGHT_SHADE, Attack::DARK_PULSE, Attack::SHADOW_BALL},
        health, attack, defense, speed)
{}

PokemonTypology::typology Darkrai::getTypology() const { return PokemonTypology::typology::darkrai; }

Darkrai* Darkrai::clone() const {
    return new Darkrai(*this);
}
