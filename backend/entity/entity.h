#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "backend/entity/entityvisitorinterface.h"
#include "backend/pokemons/pokemon.h"

class Entity
{
protected:
    std::string _name;
    std::list<Pokemon*> _pokemons;
    Pokemon* _currentPokemon;
public:
    Entity(const std::string& name, const std::list<Pokemon*>&);
    Entity(const Entity& e);
    Entity& operator=(const Entity& e);
    virtual ~Entity();
    const std::string& getName() const;
    Pokemon& getPokemon(int index);
    int getTeamSize() const;
    virtual void accept(EntityVisitorInterface& visitor)=0;
    virtual std::string getSprite() const=0;
    Pokemon* getCurrentPokemon();
    const std::list<Pokemon*>& getListPokemon();
    Pokemon& setCurrentPokemon(int index);
};

#endif // ENTITY
