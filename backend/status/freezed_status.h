#ifndef FREEZEDSTATUS_H
#define FREEZEDSTATUS_H

#include "status.h"

class FreezedStatus : public Status
{
public:
    FreezedStatus(int probability, int duration=1);
    int statusEffect() override;
    FreezedStatus* clone() const override;
    bool canAttack() const override;
};

#endif // FREEZEDSTATUS_H
