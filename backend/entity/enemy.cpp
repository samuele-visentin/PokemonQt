#include "enemy.h"

Enemy::Enemy(const std::string& name, const std::list<Pokemon*>& pokemons)
    : Entity(name, pokemons)
{}

void Enemy::accept(EntityVisitorInterface& visitor) {
    visitor.visitEnemy(*this);
}

std::string Enemy::getSprite() const { return ":/assets/enemy.png"; }
