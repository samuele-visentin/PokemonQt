#ifndef BURNEDSTATUS_H
#define BURNEDSTATUS_H

#include "status.h"

class BurnedStatus : public Status
{
private:
    int _damage; //Percentuale
public:
    BurnedStatus(int damage = 3, unsigned duration = 3, float probability = .2f);
    BurnedStatus* clone() const override;
    bool blockActions() const override;
    void effect(Pokemon&) override;
};

#endif // BURNEDSTATUS_H
