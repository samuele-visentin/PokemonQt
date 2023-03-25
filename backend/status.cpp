#include "status.h"

Status::Status(const std::string& name, unsigned duration, bool blockActions) :
    _name(name), _duration(duration), _blocksActions(blockActions){}

const std::string& Status::getName() const {
    return _name;
}

unsigned Status::getDuration() const {
    return _duration;
}

bool Status::blockActions() const {
    return _blocksActions;
}
