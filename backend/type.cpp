#include "type.h"

Type::Type(ElementType elementType, const std::string& name)
    : _elementType(elementType), _name(name){}

const Type Type::NORMAL_TYPE(Type::ElementType::NORMAL, "Normal");
const Type Type::FIRE_TYPE(Type::ElementType::FIRE, "Fire");
const Type Type::WATER_TYPE(Type::ElementType::WATER, "Water");
const Type Type::ELECTRIC_TYPE(Type::ElementType::ELECTRIC, "Electric");
const Type Type::GRASS_TYPE(Type::ElementType::GRASS, "Grass");
const Type Type::ICE_TYPE(Type::ElementType::ICE, "Ice");
const Type Type::FIGHTING_TYPE(Type::ElementType::FIGHTING, "Fighting");
const Type Type::POISON_TYPE(Type::ElementType::POISON, "Poison");
const Type Type::GROUND_TYPE(Type::ElementType::GROUND, "Ground");
const Type Type::FLYING_TYPE(Type::ElementType::FLYING, "Flying");
const Type Type::PSYCHIC_TYPE(Type::ElementType::PSYCHIC, "Psychic");
const Type Type::BUG_TYPE(Type::ElementType::BUG, "Bug");
const Type Type::ROCK_TYPE(Type::ElementType::ROCK, "Rock");
const Type Type::GHOST_TYPE(Type::ElementType::GHOST, "Ghost");
const Type Type::DRAGON_TYPE(Type::ElementType::DRAGON, "Dragon");
const Type Type::DARK_TYPE(Type::ElementType::DARK, "Dark");
const Type Type::STEEL_TYPE(Type::ElementType::STEEL, "Steel");
const Type Type::FAIRY_TYPE(Type::ElementType::FAIRY, "Fairy");

bool Type::isEffectiveAgainst(ElementType elementType) const {
    switch (elementType) {
        case ElementType::NORMAL:
            return false;
        case ElementType::FIRE:
            return _elementType == ElementType::GRASS ||
                   _elementType == ElementType::ICE ||
                   _elementType == ElementType::BUG ||
                   _elementType == ElementType::STEEL;
        case ElementType::WATER:
            return _elementType == ElementType::FIRE ||
                   _elementType == ElementType::GROUND ||
                   _elementType == ElementType::ROCK;
        case ElementType::ELECTRIC:
            return _elementType == ElementType::WATER ||
                   _elementType == ElementType::FLYING;
        case ElementType::GRASS:
            return _elementType == ElementType::WATER ||
                   _elementType == ElementType::GROUND ||
                   _elementType == ElementType::ROCK;
        case ElementType::ICE:
            return _elementType == ElementType::GRASS ||
                   _elementType == ElementType::GROUND ||
                   _elementType == ElementType::FLYING ||
                   _elementType == ElementType::DRAGON;
        case ElementType::FIGHTING:
            return _elementType == ElementType::NORMAL ||
                   _elementType == ElementType::ICE ||
                   _elementType == ElementType::ROCK ||
                   _elementType == ElementType::DARK ||
                   _elementType == ElementType::STEEL;
        case ElementType::POISON:
            return _elementType == ElementType::GRASS ||
                   _elementType == ElementType::FAIRY;
        case ElementType::GROUND:
            return _elementType == ElementType::FIRE ||
                   _elementType == ElementType::ELECTRIC ||
                   _elementType == ElementType::POISON ||
                   _elementType == ElementType::ROCK ||
                   _elementType == ElementType::STEEL;
        case ElementType::FLYING:
            return _elementType == ElementType::GRASS ||
                   _elementType == ElementType::FIGHTING ||
                   _elementType == ElementType::BUG;
        case ElementType::PSYCHIC:
            return _elementType == ElementType::FIGHTING ||
                   _elementType == ElementType::POISON;
        case ElementType::BUG:
            return _elementType == ElementType::GRASS ||
                   _elementType == ElementType::PSYCHIC ||
                   _elementType == ElementType::DARK;
        case ElementType::ROCK:
            return _elementType == ElementType::FIRE ||
                   _elementType == ElementType::ICE ||
                   _elementType == ElementType::FLYING ||
                   _elementType == ElementType::BUG;
        case ElementType::GHOST:
            return _elementType == ElementType::PSYCHIC ||
                   _elementType == ElementType::GHOST;
        case ElementType::DRAGON:
            return _elementType == ElementType::DRAGON;
        case ElementType::DARK:
            return _elementType == ElementType::PSYCHIC ||
                   _elementType == ElementType::GHOST;
        case ElementType::STEEL:
            return _elementType == ElementType::ICE ||
                   _elementType == ElementType::ROCK ||
                   _elementType == ElementType::FAIRY;
        default:
            return false;
    }
}


bool Type::isResistantTo(ElementType elementType) const {
    switch (elementType) {
        case ElementType::NORMAL:
            return _elementType == ElementType::ROCK ||
                   _elementType == ElementType::STEEL;
        case ElementType::FIRE:
            return _elementType == ElementType::FIRE ||
                   _elementType == ElementType::GRASS ||
                   _elementType == ElementType::ICE ||
                   _elementType == ElementType::BUG ||
                   _elementType == ElementType::STEEL;
        case ElementType::WATER:
            return _elementType == ElementType::WATER ||
                   _elementType == ElementType::ELECTRIC ||
                   _elementType == ElementType::STEEL;
        case ElementType::ELECTRIC:
            return _elementType == ElementType::ELECTRIC ||
                   _elementType == ElementType::FLYING ||
                   _elementType == ElementType::STEEL;
        case ElementType::GRASS:
            return _elementType == ElementType::WATER ||
                   _elementType == ElementType::GROUND ||
                   _elementType == ElementType::ROCK;
        case ElementType::ICE:
            return _elementType == ElementType::ICE ||
                   _elementType == ElementType::GRASS ||
                   _elementType == ElementType::GROUND ||
                   _elementType == ElementType::FLYING;
        case ElementType::FIGHTING:
            return _elementType == ElementType::BUG ||
                   _elementType == ElementType::ROCK ||
                   _elementType == ElementType::DARK;
        case ElementType::POISON:
            return _elementType == ElementType::GRASS ||
                   _elementType == ElementType::FAIRY;
        case ElementType::GROUND:
            return _elementType == ElementType::WATER ||
                   _elementType == ElementType::GRASS ||
                   _elementType == ElementType::ICE;
        case ElementType::FLYING:
            return _elementType == ElementType::ELECTRIC ||
                   _elementType == ElementType::ROCK ||
                   _elementType == ElementType::STEEL;
        case ElementType::PSYCHIC:
            return _elementType == ElementType::FIGHTING ||
                   _elementType == ElementType::POISON;
        case ElementType::BUG:
            return _elementType == ElementType::GRASS ||
                   _elementType == ElementType::PSYCHIC ||
                   _elementType == ElementType::DARK;
        case ElementType::ROCK:
            return _elementType == ElementType::FIRE ||
                   _elementType == ElementType::ICE ||
                   _elementType == ElementType::FLYING ||
                   _elementType == ElementType::BUG;
        case ElementType::GHOST:
            return _elementType == ElementType::GHOST ||
                   _elementType == ElementType::PSYCHIC;
        case ElementType::DRAGON:
            return _elementType == ElementType::DRAGON;
        case ElementType::DARK:
            return _elementType == ElementType::FIGHTING ||
                   _elementType == ElementType::DARK ||
                   _elementType == ElementType::FAIRY;
        case ElementType::STEEL:
            return _elementType == ElementType::FIRE ||
                   _elementType == ElementType::FIGHTING ||
                   _elementType == ElementType::GROUND ||
                   _elementType == ElementType::BUG ||
                   _elementType == ElementType::NORMAL ||
                   _elementType == ElementType::FLYING ||
                   _elementType == ElementType::GRASS ||
                   _elementType == ElementType::PSYCHIC ||
                   _elementType == ElementType::ICE ||
                   _elementType == ElementType::ROCK ||
                   _elementType == ElementType::DRAGON ||
                   _elementType == ElementType::STEEL;
        case ElementType::FAIRY:
            return _elementType == ElementType::FIGHTING ||
                   _elementType == ElementType::DRAGON ||
                   _elementType == ElementType::DARK;
        default:
            return false;
    }
}


std::string Type::getName() const {
    return _name;
}

Type::ElementType Type::getElementType() const { return _elementType; }
