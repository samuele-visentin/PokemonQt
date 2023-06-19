#include "pokemon_typology.h"

PokemonTypology::PokemonTypology(const typology& typology,
    const std::string& name, const std::string& sprite)
    : _name(name), _type(typology), _sprite(sprite)
{}

PokemonTypology::typology PokemonTypology::getTypology() const {
    return _type;
}

std::string PokemonTypology::getName() const {
    return _name;
}

std::string PokemonTypology::getSprite() const {
    return _sprite;
}

std::vector<const PokemonTypology*> PokemonTypology::getAllTypology() {
    std::vector<const PokemonTypology*> vec = {
        &infernape,
        &darkrai,
        &giratina,
        &pikachu,
        &charizard
    };
    return vec;
}

const PokemonTypology PokemonTypology::infernape(PokemonTypology::typology::infernape, "Infernape", ":assets/pokemons/front/infernape.png");
const PokemonTypology PokemonTypology::darkrai(PokemonTypology::typology::darkrai, "Darkrai", ":assets/pokemons/front/darkrai.png");
const PokemonTypology PokemonTypology::giratina(PokemonTypology::typology::giratina, "Giratina", ":assets/pokemons/front/giratina.png");
const PokemonTypology PokemonTypology::pikachu(PokemonTypology::typology::pikachu, "Pikachu", ":assets/pokemons/front/pikachu.png");
const PokemonTypology PokemonTypology::charizard(PokemonTypology::typology::charizard, "Charizard", ":assets/pokemons/front/charizard.png");
