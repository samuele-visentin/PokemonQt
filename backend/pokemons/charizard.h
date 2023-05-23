#ifndef CHARIZARD_H
#define CHARIZARD_H

#include "backend/pokemons/pokemon.h"

class Charizard : public Pokemon
{
private:

public:
    Charizard(int level, int health,
              int attack, int defend, int specialAttack,
              int specialDefense, int speed, const std::list<Attack>& vec,
              const std::string& username = _name);
    Charizard* clone() const override;
};

#endif // CHARIZARD_H
