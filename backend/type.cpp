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

bool Type::isEffectiveAgainst(const Type& other) const {
    switch (_elementType) {
        case ElementType::NORMAL:
            return false;
        case ElementType::FIRE:
            return other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::ICE ||
                   other._elementType == ElementType::BUG ||
                   other._elementType == ElementType::STEEL;
        case ElementType::WATER:
            return other._elementType == ElementType::FIRE ||
                   other._elementType == ElementType::GROUND ||
                   other._elementType == ElementType::ROCK;
        case ElementType::ELECTRIC:
            return other._elementType == ElementType::WATER ||
                   other._elementType == ElementType::FLYING;
        case ElementType::GRASS:
            return other._elementType == ElementType::WATER ||
                   other._elementType == ElementType::GROUND ||
                   other._elementType == ElementType::ROCK;
        case ElementType::ICE:
            return other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::GROUND ||
                   other._elementType == ElementType::FLYING ||
                   other._elementType == ElementType::DRAGON;
        case ElementType::FIGHTING:
            return other._elementType == ElementType::NORMAL ||
                   other._elementType == ElementType::ICE ||
                   other._elementType == ElementType::ROCK ||
                   other._elementType == ElementType::DARK ||
                   other._elementType == ElementType::STEEL;
        case ElementType::POISON:
            return other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::FAIRY;
        case ElementType::GROUND:
            return other._elementType == ElementType::FIRE ||
                   other._elementType == ElementType::ELECTRIC ||
                   other._elementType == ElementType::POISON ||
                   other._elementType == ElementType::ROCK ||
                   other._elementType == ElementType::STEEL;
        case ElementType::FLYING:
            return other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::FIGHTING ||
                   other._elementType == ElementType::BUG;
        case ElementType::PSYCHIC:
            return other._elementType == ElementType::FIGHTING ||
                   other._elementType == ElementType::POISON;
        case ElementType::BUG:
            return other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::PSYCHIC ||
                   other._elementType == ElementType::DARK;
        case ElementType::ROCK:
            return other._elementType == ElementType::FIRE ||
                   other._elementType == ElementType::ICE ||
                   other._elementType == ElementType::FLYING ||
                   other._elementType == ElementType::BUG;
        case ElementType::GHOST:
            return other._elementType == ElementType::PSYCHIC ||
                   other._elementType == ElementType::GHOST;
        case ElementType::DRAGON:
            return other._elementType == ElementType::DRAGON;
        case ElementType::DARK:
            return other._elementType == ElementType::PSYCHIC ||
                   other._elementType == ElementType::GHOST;
        case ElementType::STEEL:
            return other._elementType == ElementType::ICE ||
                   other._elementType == ElementType::ROCK ||
                   other._elementType == ElementType::FAIRY;
        default:
            return false;
    }
}


bool Type::isResistantTo(const Type& other) const {
    switch (_elementType) {
        case ElementType::NORMAL:
            return other._elementType == ElementType::ROCK ||
                   other._elementType == ElementType::STEEL;
        case ElementType::FIRE:
            return other._elementType == ElementType::FIRE ||
                   other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::ICE ||
                   other._elementType == ElementType::BUG ||
                   other._elementType == ElementType::STEEL;
        case ElementType::WATER:
            return other._elementType == ElementType::WATER ||
                   other._elementType == ElementType::ELECTRIC ||
                   other._elementType == ElementType::STEEL;
        case ElementType::ELECTRIC:
            return other._elementType == ElementType::ELECTRIC ||
                   other._elementType == ElementType::FLYING ||
                   other._elementType == ElementType::STEEL;
        case ElementType::GRASS:
            return other._elementType == ElementType::WATER ||
                   other._elementType == ElementType::GROUND ||
                   other._elementType == ElementType::ROCK;
        case ElementType::ICE:
            return other._elementType == ElementType::ICE ||
                   other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::GROUND ||
                   other._elementType == ElementType::FLYING;
        case ElementType::FIGHTING:
            return other._elementType == ElementType::BUG ||
                   other._elementType == ElementType::ROCK ||
                   other._elementType == ElementType::DARK;
        case ElementType::POISON:
            return other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::FAIRY;
        case ElementType::GROUND:
            return other._elementType == ElementType::WATER ||
                   other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::ICE;
        case ElementType::FLYING:
            return other._elementType == ElementType::ELECTRIC ||
                   other._elementType == ElementType::ROCK ||
                   other._elementType == ElementType::STEEL;
        case ElementType::PSYCHIC:
            return other._elementType == ElementType::FIGHTING ||
                   other._elementType == ElementType::POISON;
        case ElementType::BUG:
            return other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::PSYCHIC ||
                   other._elementType == ElementType::DARK;
        case ElementType::ROCK:
            return other._elementType == ElementType::FIRE ||
                   other._elementType == ElementType::ICE ||
                   other._elementType == ElementType::FLYING ||
                   other._elementType == ElementType::BUG;
        case ElementType::GHOST:
            return other._elementType == ElementType::GHOST ||
                   other._elementType == ElementType::PSYCHIC;
        case ElementType::DRAGON:
            return other._elementType == ElementType::DRAGON;
        case ElementType::DARK:
            return other._elementType == ElementType::FIGHTING ||
                   other._elementType == ElementType::DARK ||
                   other._elementType == ElementType::FAIRY;
        case ElementType::STEEL:
            return other._elementType == ElementType::FIRE ||
                   other._elementType == ElementType::FIGHTING ||
                   other._elementType == ElementType::GROUND ||
                   other._elementType == ElementType::BUG ||
                   other._elementType == ElementType::NORMAL ||
                   other._elementType == ElementType::FLYING ||
                   other._elementType == ElementType::GRASS ||
                   other._elementType == ElementType::PSYCHIC ||
                   other._elementType == ElementType::ICE ||
                   other._elementType == ElementType::ROCK ||
                   other._elementType == ElementType::DRAGON ||
                   other._elementType == ElementType::STEEL;
        case ElementType::FAIRY:
            return other._elementType == ElementType::FIGHTING ||
                   other._elementType == ElementType::DRAGON ||
                   other._elementType == ElementType::DARK;
        default:
            return false;
    }
}


bool Type::isWeakTo(const Type& other) const {
    return other.isEffectiveAgainst(*this);
}

std::string Type::getName() const {
    return _name;
}
