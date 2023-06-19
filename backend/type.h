#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type {
public:
    enum class ElementType {
        NORMAL, FIRE, WATER, ELECTRIC, GRASS, ICE, FIGHTING, POISON,
        GROUND, FLYING, PSYCHIC, BUG, ROCK, GHOST, DRAGON, DARK, STEEL, FAIRY
    };
private:
    Type(ElementType el, const std::string& name);
    ElementType _elementType;
    std::string _name;
public: 
    bool isEffectiveAgainst(ElementType other) const;
    bool isResistantTo(ElementType other) const;
    std::string getName() const;
    Type::ElementType getElementType() const;

    static const Type NORMAL_TYPE;
    static const Type FIRE_TYPE;
    static const Type WATER_TYPE;
    static const Type ELECTRIC_TYPE;
    static const Type GRASS_TYPE;
    static const Type ICE_TYPE;
    static const Type FIGHTING_TYPE;
    static const Type POISON_TYPE;
    static const Type GROUND_TYPE;
    static const Type FLYING_TYPE;
    static const Type PSYCHIC_TYPE;
    static const Type BUG_TYPE;
    static const Type ROCK_TYPE;
    static const Type GHOST_TYPE;
    static const Type DRAGON_TYPE;
    static const Type DARK_TYPE;
    static const Type STEEL_TYPE;
    static const Type FAIRY_TYPE;
};

#endif // TYPE_H
