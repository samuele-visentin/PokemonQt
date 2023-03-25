#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include "type.h"

class Attack {
protected:
    std::string name;
    unsigned short maxUsage; //aka cc, forse
    Type type;
    unsigned short currentUsage;
public:
    Attack(const std::string& s, unsigned short cc, const Type& t);
    Type getType() const;
    unsigned short getMaxUsage() const;
    unsigned short getCurrentUsage() const;
    void useMove();
};

#endif // ATTACK_H
