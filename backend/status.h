#ifndef STATUS_H
#define STATUS_H

#include <string>

class Status {
private:
    std::string _name;
    unsigned _duration;
    bool _blocksActions;
    float _probability;
    Status(const std::string& name, unsigned duration, bool blocksActions, float probability);
public:
    const std::string& getName() const;
    unsigned getDuration() const;
    bool blockActions() const;
    float getProbability() const;
    static const Status BURNED;
    static const Status PARALYZED;
    static const Status ASLEEP;
};

#endif // STATUS_H
