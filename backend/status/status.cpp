#include "status.h"

Status::Status(unsigned duration, bool blockActions, float probability) :
    _duration(duration), _blocksActions(blockActions), _probability(probability){}

unsigned Status::getDuration() const {
    return _duration;
}

bool Status::blockActions() const {
    return _blocksActions;
}

float Status::getProbability() const {
    return _probability;
}
