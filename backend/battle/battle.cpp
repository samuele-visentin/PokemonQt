#include "battle.h"
#include <random>
#include <time.h>

Battle::Battle(const Player& player, const Enemy& enemy)
    : _player(player), _enemy(enemy){}

Player& Battle::getPlayer() { return _player; }

Enemy& Battle::getEnemy() { return _enemy; }

void Battle::performTurn(int indexAttack) {
    Pokemon* playerPokemon = _player.getCurrentPokemon();
    Pokemon* enemyPokemon = _enemy.getCurrentPokemon();
    if(playerPokemon->getSpeed() >= enemyPokemon->getSpeed()) {
        playerPokemon->attack(*enemyPokemon, indexAttack);
        if(!enemyPokemon->isFainted()) {
            std::srand(time(nullptr));
            int random = std::rand() % 4;
            enemyPokemon->attack(*playerPokemon, random);
        }
    }
    else {
        std::srand(time(nullptr));
        int random = std::rand() % 3;
        enemyPokemon->attack(*playerPokemon, random);
        if(!playerPokemon->isFainted()) {
            playerPokemon->attack(*enemyPokemon, indexAttack);
        }
    }
}
