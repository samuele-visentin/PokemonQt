#include "status.h"

Status::Status(const std::string& name, int probability, int duration) :
    _name(name), _probability(probability), _duration(duration)
{}

unsigned Status::getDuration() const {
    return _duration;
}

float Status::getProbability() const {
    return _probability;
}

std::string Status::getName() const  {
    return _name;
}

bool Status::isFinish() const { return _duration<=0;}

