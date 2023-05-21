#include "battle.h"
#include "backend/pokemons/pokemon.h"

Battle::Battle(std::list<Pokemon*> player,std::list<Pokemon*> npc,
               const std::string& playerName,
               const std::string& npcName) :
    _player(player), _npc(npc),
    _playerName(playerName), _npcName(npcName)
{}

Battle::~Battle() {
    for (auto it: _player) {
        delete it;
    }
    for (auto it: _npc) {
        delete it;
    }
}

Battle::Battle(const Battle& b)
    : _playerName(b._playerName),
      _npcName(b._npcName)
{
    for (Pokemon* pokemon: _player) {
        _player.push_back(pokemon->clone());
    }
    for(Pokemon* pokemon: _npc){
        _npc.push_back(pokemon->clone());
    }
}

Battle& Battle::operator=(const Battle& b) {
    if(this != &b) {
        _playerName = b._playerName;
        _npcName = b._npcName;
        for (Pokemon* pokemon: _player) {
            delete pokemon;
        }
        for(Pokemon* pokemon: _npc){
            delete pokemon;
        }
        for (Pokemon* p : b._player) {
            _player.push_back(p->clone());
        }
        for (Pokemon* p : b._npc) {
            _npc.push_back(p->clone());
        }
    }
    return *this;
}

std::string Battle::getNpcName() const
{ return _npcName; }

std::string Battle::getPlayerName() const
{ return _playerName; }

Pokemon& Battle::getPlayerPokemon(int index) {
    auto it = _player.begin();
    std::advance(it, index);
    return **it;
}

Pokemon& Battle::getNpcPokemon(int index) {
    auto it = _npc.begin();
    std::advance(it, index);
    return **it;
}
