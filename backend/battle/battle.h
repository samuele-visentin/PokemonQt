#ifndef BATTLE_H
#define BATTLE_H

#include <list>
#include "backend/pokemons/pokemon.h"

class Battle
{
private:
    std::list<Pokemon*> _player;
    std::list<Pokemon*> _npc;
    std::string _playerName;
    std::string _npcName;
    void performTurn();
public:
    Battle(std::list<Pokemon*>, std::list<Pokemon*>,
           const std::string&, const std::string&);
    ~Battle();
    Battle(const Battle&);
    Battle& operator=(const Battle&);
    std::string getPlayerName() const;
    std::string getNpcName() const;
    Pokemon& getNpcPokemon(int index);
    Pokemon& getPlayerPokemon(int index);
};

#endif // BATTLE_H
