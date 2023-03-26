#include "status.h"

Status::Status(const std::string& name, unsigned duration, bool blockActions, float probability) :
    _name(name), _duration(duration), _blocksActions(blockActions), _probability(probability){}

const std::string& Status::getName() const {
    return _name;
}

unsigned Status::getDuration() const {
    return _duration;
}

bool Status::blockActions() const {
    return _blocksActions;
}

float Status::getProbability() const {
    return _probability;
}

const Status Status::BURNED("Burned", 5, false, 0.3f);
const Status Status::PARALYZED("Paralyzed", 1, true, 0.3f);
const Status Status::ASLEEP("Asleep", 3, true, 0.15f);
