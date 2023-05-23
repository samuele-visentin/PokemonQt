#include "entity.h"

Entity::Entity(const std::string& name, const std::list<Pokemon*>& pokemons)
    : _name(name),
      _pokemons(pokemons),
      _currentPokemon(nullptr)
{}

Entity::Entity(const Entity& e)
    : _name(e._name),
      _currentPokemon(e._currentPokemon ? e._currentPokemon->clone() : nullptr)
{
    for (Pokemon* p: e._pokemons) {
        _pokemons.push_back(p->clone());
    }
}

Entity& Entity::operator=(const Entity& e) {
    if(this != &e) {
        for (Pokemon* p: _pokemons) {
            delete p;
        }
        _pokemons.clear();
        _name = e._name;
        for(Pokemon* p: e._pokemons){
            _pokemons.push_back(p->clone());
        }
        _currentPokemon = e._currentPokemon ? e._currentPokemon : nullptr;
    }
    return *this;
}

Entity::~Entity() {
    for(Pokemon* p: _pokemons){
        delete p;
    }
}

const std::string& Entity::getName() const { return _name; }
Pokemon& Entity::getPokemon(int index) {
    auto it = _pokemons.begin();
    std::advance(it, index);
    return **it;
}
int Entity::getTeamSize() const { return _pokemons.size(); }
Pokemon* Entity::getCurrentPokemon() { return _currentPokemon; }
Pokemon& Entity::setCurrentPokemon(int index) {
    auto it = _pokemons.begin();
    std::advance(it, index);
    _currentPokemon = *it;
    return *_currentPokemon;
}
const std::list<Pokemon*>& Entity::getListPokemon() {
    return _pokemons;
}
