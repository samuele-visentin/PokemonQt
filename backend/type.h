#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type {
public:
    enum class ElementType {
        NORMAL, FIRE, WATER, ELECTRIC, GRASS, ICE, FIGHTING, POISON,
        GROUND, FLYING, PSYCHIC, BUG, ROCK, GHOST, DRAGON, DARK, STEEL, FAIRY
    };
    Type(ElementType elementType);
    bool isEffectiveAgainst(const Type& other) const;
    bool isResistantTo(const Type& other) const;
    bool isWeakTo(const Type& other) const;
    std::string getName() const;

private:
    ElementType _elementType;
    std::string _name;
};


#endif // TYPE_H
