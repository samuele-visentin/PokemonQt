#include "battle.h"

Battle::Battle(const Player& player, const Enemy& enemy)
    : _player(player), _enemy(enemy){}

Player& Battle::getPlayer() { return _player; }

Enemy& Battle::getEnemy() { return _enemy; }
