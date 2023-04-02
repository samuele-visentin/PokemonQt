#ifndef STATUS_H
#define STATUS_H

#include <string>
#include "backend/pokemons/pokemon.h"

class Status {
private:
    unsigned _duration;
    float _probability;
protected:
    static const std::string NAME;
public:
    Status(unsigned duration, float probability);
    virtual ~Status() = default;
    std::string getName() const;
    unsigned getDuration() const; 
    float getProbability() const;
    virtual void effect(Pokemon&)=0;
    virtual bool blockActions() const=0;
    virtual Status* clone() const=0;
};

#endif // STATUS_H
