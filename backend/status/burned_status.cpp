#include "burned_status.h"

BurnedStatus::BurnedStatus(int damage, unsigned duration, float probability)
    : Status(duration, probability), _damage(damage){}

BurnedStatus* BurnedStatus::clone() const {
    return new BurnedStatus(*this);
}

const std::string BurnedStatus::Status::NAME = "Bruciato";

bool BurnedStatus::blockActions() const { return false; }
void BurnedStatus::effect(Pokemon& p) {
    if (p.getType().isWeakTo(Type::FIRE_TYPE)) {
        //TODO calcolare danno
    } else if(p.getType().isResistantTo(Type::FIRE_TYPE)) {
        //TODO
    } else {
        //TODO
    }
}
