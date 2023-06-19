#include "enemy.h"
#include "backend/pokemons/darkrai.h"
#include "backend/pokemons/giratina.h"
#include "backend/pokemons/infernape.h"

Enemy::Enemy(const std::string& name)
    : Entity(name, {
        new Giratina(300, 100, 100, 100, "Destructor"),
        new Darkrai(300, 120, 120, 120, "Nightmare"),
        new Infernape(500, 250, 250, 250, "Allfire")
    }), indexPokemon(0)
{}

void Enemy::accept(EntityVisitorInterface& visitor) {
    visitor.visitEnemy(*this);
}

Pokemon& Enemy::changePokemon() {
    auto it = _pokemons.begin();
    std::advance(it, ++indexPokemon);
    _currentPokemon = *it;
    return *_currentPokemon;
}

Enemy* Enemy::clone() const {
    return new Enemy(*this);
}
