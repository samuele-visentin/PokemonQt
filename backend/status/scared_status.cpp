#include "scared_status.h"

ScaredStatus::ScaredStatus(int probability, int duration, int damage, int stunProbability)
    : Status("Impaurito", probability, duration), _damage(damage), _stunProbability(stunProbability)
{}

ScaredStatus* ScaredStatus::clone() const {
    return new ScaredStatus(*this);
}

int ScaredStatus::statusEffect()  {
    _duration -= 1;
    return (std::rand()%15) + _damage;
}

bool ScaredStatus::canAttack() const {
    return (std::rand()%100) > _stunProbability;
}
