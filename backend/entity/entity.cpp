#include "entity.h"

Entity::Entity(const std::string& name, const std::vector<Pokemon*>& pokemons)
    : _name(name),
      _pokemons(pokemons),
      _currentPokemon(_pokemons.begin() != _pokemons.end() ? *_pokemons.begin() : nullptr)
{}

Entity::Entity(const Entity& e)
    : _name(e._name)
{
    _pokemons.reserve(e._pokemons.size());
    for (Pokemon* p : e._pokemons) {
        _pokemons.push_back(p->clone());
    }
    _currentPokemon = _pokemons.begin() != _pokemons.end() ? *_pokemons.begin() : nullptr;
}

Entity& Entity::operator=(const Entity& e) {
    if(this != &e) {
        _name = e._name;
        for(Pokemon* p: _pokemons) delete p;
        _pokemons.clear();
        _pokemons.reserve(e._pokemons.size());
        for(Pokemon* p: e._pokemons) {
            _pokemons.push_back(p->clone());
        }
        _currentPokemon = _pokemons.begin() != _pokemons.end() ? *_pokemons.begin() : nullptr;
    }
    return *this;
}

Entity::~Entity() {
    for(Pokemon* p: _pokemons) delete p;
}

const std::string& Entity::getName() const { return _name; }

Pokemon& Entity::getPokemon(int index) {
    auto it = _pokemons.begin();
    std::advance(it, index);
    return **it;
}

int Entity::getTeamSize() const { return _pokemons.size(); }

Pokemon& Entity::getCurrentPokemon() { return *_currentPokemon; }

std::vector<Pokemon*>& Entity::getPokemons() {
    return _pokemons;
}

bool Entity::hasPokemonAlive() const {
    for (Pokemon* p: _pokemons) {
        if(!(p->isFainted())) {
            return true;
        }
    }
    return false;
}
