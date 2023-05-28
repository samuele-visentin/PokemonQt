#ifndef BATTLE_H
#define BATTLE_H

#include "backend/entity/enemy.h"
#include "backend/entity/player.h"

class Battle
{
private:
    Player _player;
    Enemy _enemy;
public:
    Battle(const Player& player, const Enemy& enemy);
    Player& getPlayer();
    Enemy& getEnemy();
    void performTurn(int indexAttack);
};

#endif // BATTLE_H
