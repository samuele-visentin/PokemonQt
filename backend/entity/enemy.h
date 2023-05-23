#ifndef ENEMY_H
#define ENEMY_H


#include "backend/entity/entity.h"

class Enemy: public Entity
{
public:
    Enemy(const std::string& name, const std::list<Pokemon*>&);
    void accept(EntityVisitorInterface& visitor) override;
    std::string getSprite() const override;
};

#endif // ENEMY_H
