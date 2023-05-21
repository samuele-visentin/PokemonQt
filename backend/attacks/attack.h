#ifndef ATTACK_H
#define ATTACK_H

#include <string>

class Attack {
private:
    std::string name;
    unsigned short maxUsage; //aka cc, forse
    unsigned short currentUsage;
    int power;
    float accuracy;
    Attack(const std::string& s = "none",
           unsigned short cc=0,
           int power=0,
           float accuracy=0);
public: 
    std::string getName() const;
    unsigned short getMaxUsage() const;
    unsigned short getCurrentUsage() const;
    Attack clone() const;
    int getPower() const;
    float getAccuracy() const;
};

#endif // ATTACK_H
