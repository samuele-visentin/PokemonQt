#ifndef STATUS_H
#define STATUS_H

#include <string>

class Status {
private:
    std::string _name;
    unsigned _duration;
    bool _blocksActions;
public:
    Status(const std::string& name, unsigned duration, bool blocksActions);
    const std::string& getName() const;
    unsigned getDuration() const;
    bool blockActions() const;
};

#endif // STATUS_H
