#include "pikachu.h"

Pikachu::Pikachu(int health, int attack, int defense, int speed, const std::string& name)
    : Pokemon(Type::ELECTRIC_TYPE, "pikachu.png", name, {
        Attack::THUNDER_SHOCK, Attack::THUNDERBOLT, Attack::THUNDER_SHOCK, Attack::QUICK_ATTACK
    }, health, attack, defense, speed)
{}

PokemonTypology::typology Pikachu::getTypology() const { return PokemonTypology::typology::pikachu; }

Pikachu* Pikachu::clone() const {
    return new Pikachu(*this);
}
