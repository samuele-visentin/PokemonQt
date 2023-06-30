#include "battle.h"
#include <random>
#include <time.h>

Battle::Battle(const Player& player, const Enemy& enemy)
    : _player(player), _enemy(enemy){}

Player& Battle::getPlayer() { return _player; }

Enemy& Battle::getEnemy() { return _enemy; }

Attack& Battle::getPlayerAttack(int index) {
    return _player.getCurrentPokemon().getAttackMove(index);
}

Attack& Battle::getEnemyAttack() {
    std::srand(time(nullptr));
    int random = std::rand() % 4;
    return _enemy.getCurrentPokemon().getAttackMove(random);
}
