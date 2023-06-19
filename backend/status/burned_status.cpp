#include "burned_status.h"

BurnedStatus::BurnedStatus(int probability, int damage, int duration)
    : Status("Bruciato", probability, duration), _damage(damage){}

BurnedStatus* BurnedStatus::clone() const {
    return new BurnedStatus(*this);
}

bool BurnedStatus::canAttack() const {
    return true;
}

int BurnedStatus::statusEffect() {
    _duration -= 1;
    return (_damage*(std::rand()%2));
}

