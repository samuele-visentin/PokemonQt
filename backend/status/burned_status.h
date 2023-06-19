#ifndef BURNEDSTATUS_H
#define BURNEDSTATUS_H

#include "status.h"

class BurnedStatus : public Status
{
private:
    int _damage;
public:
    BurnedStatus(int probability = 75, int damage = 10, int duration=3);
    BurnedStatus* clone() const override;
    int statusEffect() override;
    bool canAttack() const override;
};

#endif // BURNEDSTATUS_H
