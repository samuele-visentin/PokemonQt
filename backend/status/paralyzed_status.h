#ifndef PARALYZEDSTATUS_H
#define PARALYZEDSTATUS_H

#include "status.h"

class ParalyzedStatus : public Status
{
private:
    int _stunProbability;
public:
    ParalyzedStatus(int probability, int duration=3, int stunProbability=50);
    int statusEffect() override;
    ParalyzedStatus* clone() const override;
    bool canAttack() const override;
};

#endif // PARALYZEDSTATUS_H
