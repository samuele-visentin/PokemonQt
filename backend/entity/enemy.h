#ifndef ENEMY_H
#define ENEMY_H


#include "backend/entity/entity.h"

class Enemy: public Entity
{
private:
    int indexPokemon;
public:
    Enemy(const std::string& name);
    Enemy() = default;
    void accept(EntityVisitorInterface& visitor) override;
    Enemy* clone() const override;
    Pokemon& changePokemon();
};

#endif // ENEMY_H
