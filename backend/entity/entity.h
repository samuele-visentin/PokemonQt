#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "backend/entity/entityvisitorinterface.h"
#include "backend/pokemons/pokemon.h"

class Entity
{
private:
    std::string _name;
protected:
    std::vector<Pokemon*> _pokemons;
    Pokemon* _currentPokemon;
public:
    Entity(const std::string& name, const std::vector<Pokemon*>&);
    Entity() = default;
    Entity(const Entity& e);
    Entity& operator=(const Entity& e);
    virtual ~Entity();
    virtual Entity* clone() const = 0;
    virtual void accept(EntityVisitorInterface& visitor)=0;
    const std::string& getName() const;
    Pokemon& getPokemon(int index);
    int getTeamSize() const; 
    Pokemon& getCurrentPokemon();
    std::vector<Pokemon*>& getPokemons();
    bool hasPokemonAlive() const;
};

#endif // ENTITY
