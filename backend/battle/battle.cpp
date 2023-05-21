#include "battle.h"
#include "backend/pokemons/pokemon.h"

Battle::Battle(std::list<Pokemon*> player,std::list<Pokemon*> npc,
               const std::string& playerName,
               const std::string& npcName) :
    _player(player), _npc(npc),
    _playerName(playerName), _npcName(npcName)
{}

std::string Battle::getNpcName() const
{ return _npcName; }

std::string Battle::getPlayerName() const
{ return _playerName; }
