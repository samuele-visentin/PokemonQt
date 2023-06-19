#ifndef SCAREDSTATUS_H
#define SCAREDSTATUS_H

#include "status.h"

class ScaredStatus : public Status
{
private:
    int _damage;
    int _stunProbability;
public:
    ScaredStatus(int probability, int duration=2, int damage=5, int stunProbability=30);
    int statusEffect() override;
    ScaredStatus* clone() const override;
    bool canAttack() const override;
};

#endif // SCAREDSTATUS_H
