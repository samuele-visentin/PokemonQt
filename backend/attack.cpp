#include "attack.h"

Attack::Attack(const std::string& s, unsigned short cc, const Type& t) :
    name(s), maxUsage(cc), type(t), currentUsage(cc){}

Type Attack::getType() const {
    return type;
}

unsigned short Attack::getMaxUsage() const {
    return maxUsage;
}

unsigned short Attack::getCurrentUsage() const {
    return currentUsage;
}

void Attack::useMove() {
    if(currentUsage == 0) throw "CC Underflow"; //TODO
    currentUsage -= 1;
}
