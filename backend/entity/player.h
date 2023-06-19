#ifndef PLAYER_H
#define PLAYER_H


#include "backend/entity/entity.h"

class Player: public Entity
{
public:
    Player(const std::string& name, const std::vector<Pokemon*>&);
    Player() = default;
    void accept(EntityVisitorInterface& visitor) override;
    Player* clone() const override;
    Pokemon& setCurrentPokemon(int index);
};

#endif // PLAYER_H
