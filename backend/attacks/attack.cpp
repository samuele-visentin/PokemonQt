#include "attack.h"

int Attack::getPower() const
{
    return power;
}

float Attack::getAccuracy() const
{
    return accuracy;
}

Attack::Attack(const std::string& s, unsigned short cc, int pow, float acc) :
    name(s), maxUsage(cc), currentUsage(cc), power(pow), accuracy(acc){}


unsigned short Attack::getMaxUsage() const {
    return maxUsage;
}

unsigned short Attack::getCurrentUsage() const {
    return currentUsage;
}


