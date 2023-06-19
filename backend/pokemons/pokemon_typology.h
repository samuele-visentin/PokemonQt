#ifndef POKEMONTYPOLOGY_H
#define POKEMONTYPOLOGY_H

#include <string>
#include <vector>

class PokemonTypology
{
public:
    enum class typology {
        infernape, darkrai, giratina, pikachu, charizard
    };
private:
    const std::string _name;
    const typology _type;
    const std::string _sprite;
    PokemonTypology(const typology& typology, const std::string& name, const std::string& sprite);
public:
    typology getTypology() const;
    std::string getName() const;
    std::string getSprite() const;
    static std::vector<const PokemonTypology*> getAllTypology();
    static const PokemonTypology infernape;
    static const PokemonTypology darkrai;
    static const PokemonTypology giratina;
    static const PokemonTypology pikachu;
    static const PokemonTypology charizard;
};

#endif // POKEMONTYPOLOGY_H
