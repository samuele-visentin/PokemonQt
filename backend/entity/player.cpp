#include "player.h"

Player::Player(const std::string& name, const std::vector<Pokemon*>& pokemons)
    : Entity(name, pokemons)
{}

void Player::accept(EntityVisitorInterface& visitor) {
    visitor.visitPlayer(*this);
}

Pokemon& Player::setCurrentPokemon(int index) {
    auto it = _pokemons.begin();
    std::advance(it, index);
    _currentPokemon = *it;
    return *_currentPokemon;
}

Player* Player::clone() const {
    return new Player(*this);
}
