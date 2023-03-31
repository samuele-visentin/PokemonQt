#ifndef STATUS_H
#define STATUS_H

class Pokemon;
#include <string>

class Status {
private:
    unsigned _duration;
    bool _blocksActions;
    float _probability;
protected:
    static const std::string NAME;
public:
    Status(unsigned duration, bool blocksActions, float probability);
    virtual ~Status();
    Status(const Status&);
    std::string getName() const;
    unsigned getDuration() const;
    bool blockActions() const;
    float getProbability() const;
    virtual void effect(Pokemon&)=0;
};

#endif // STATUS_H
