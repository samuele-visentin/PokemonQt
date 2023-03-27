#ifndef STATUS_H
#define STATUS_H

#include <string>

class Status {
private:
    unsigned _duration;
    bool _blocksActions;
    float _probability;
public:
    Status(unsigned duration, bool blocksActions, float probability);
    std::string getName() const=0;
    unsigned getDuration() const;
    bool blockActions() const;
    float getProbability() const;
    virtual void effect()=0;
};

#endif // STATUS_H
