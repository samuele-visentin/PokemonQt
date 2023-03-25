#ifndef POKEMON_STATUS_H
#define POKEMON_STATUS_H

#include <string>

class PokemonStatus {
protected:
    std::string nameStatus;
    unsigned times;
public:
    PokemonStatus(const std::string& s);
    virtual void effect()=0;
    virtual void turns()=0;
};

#endif // POKEMON_STATUS_H
