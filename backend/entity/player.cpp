#include "player.h"

Player::Player(const std::string& name, const std::list<Pokemon*>& pokemons)
    : Entity(name, pokemons)
{}

void Player::accept(EntityVisitorInterface& visitor) {
    visitor.visitPlayer(*this);
}

std::string Player::getSprite() const { return ":/assets/player.png"; }

