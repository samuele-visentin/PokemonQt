#include "status.h"

Status::Status(unsigned duration, float probability) :
    _duration(duration), _probability(probability){}

unsigned Status::getDuration() const {
    return _duration;
}

float Status::getProbability() const {
    return _probability;
}

std::string Status::getName() const  {
    return NAME;
}
