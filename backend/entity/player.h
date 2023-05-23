#ifndef PLAYER_H
#define PLAYER_H


#include "backend/entity/entity.h"

class Player: public Entity
{
public:
    Player(const std::string& name, const std::list<Pokemon*>&);
    void accept(EntityVisitorInterface& visitor) override;
    std::string getSprite() const override;
};

#endif // PLAYER_H
