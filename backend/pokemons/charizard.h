#ifndef CHARIZARD_H
#define CHARIZARD_H

#include "backend/pokemons/pokemon.h"

class Charizard : public Pokemon
{
private:

public:
    Charizard(int level, int health,
              int attack, int defend, int specialAttack,
              int specialDefense, int speed, const std::vector<Attack*>& vec,
              const std::string& username = _name);
};

#endif // CHARIZARD_H
