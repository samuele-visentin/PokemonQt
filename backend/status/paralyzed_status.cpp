#include "paralyzed_status.h"

ParalyzedStatus::ParalyzedStatus(int probability, int duration, int stunProbability)
    : Status("Paralizzato", probability, duration), _stunProbability(stunProbability)
{}

ParalyzedStatus* ParalyzedStatus::clone() const {
    return new ParalyzedStatus(*this);
}

int ParalyzedStatus::statusEffect() {
    _duration -= 1;
    return 0;
}

bool ParalyzedStatus::canAttack() const {
    return (std::rand()%100) > _stunProbability;
}
