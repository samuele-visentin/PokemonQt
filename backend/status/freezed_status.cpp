#include "freezed_status.h"

FreezedStatus::FreezedStatus(int probability, int duration)
    : Status("Congelato", probability, duration)
{}

int FreezedStatus::statusEffect() {
    _duration -= 1;
    return 0;
}

FreezedStatus* FreezedStatus::clone() const {
    return new FreezedStatus(*this);
}

bool FreezedStatus::canAttack() const { return false; }
