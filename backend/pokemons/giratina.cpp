#include "giratina.h"

Giratina::Giratina(int health, int attack, int defense, int speed, const std::string& name)
    : Pokemon(Type::DRAGON_TYPE, "giratina.png", name, {
        Attack::SHADOW_BALL, Attack::NIGHT_SHADE, Attack::ENERGY_BALL, Attack::BITE
      }, health, attack, defense, speed)
{}

PokemonTypology::typology Giratina::getTypology() const { return PokemonTypology::typology::giratina; }

Giratina* Giratina::clone() const {
    return new Giratina(*this);
}
