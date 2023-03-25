#include "type.h"

Type::Type(ElementType elementType) : _elementType(elementType) {
    // Assegnare il nome del tipo in base all'elemento
    switch (elementType) {
        case ElementType::NORMAL: _name = "Normal"; break;
        case ElementType::FIRE: _name = "Fire"; break;
        case ElementType::WATER: _name = "Water"; break;
        case ElementType::ELECTRIC: _name = "Electric"; break;
        case ElementType::GRASS: _name = "Grass"; break;
        case ElementType::ICE: _name = "Ice"; break;
        case ElementType::FIGHTING: _name = "Fighting"; break;
        case ElementType::POISON: _name = "Poison"; break;
        case ElementType::GROUND: _name = "Ground"; break;
        case ElementType::FLYING: _name = "Flying"; break;
        case ElementType::PSYCHIC: _name = "Psychic"; break;
        case ElementType::BUG: _name = "Bug"; break;
        case ElementType::ROCK: _name = "Rock"; break;
        case ElementType::GHOST: _name = "Ghost"; break;
        case ElementType::DRAGON: _name = "Dragon"; break;
        case ElementType::DARK: _name = "Dark"; break;
        case ElementType::STEEL: _name = "Steel"; break;
        case ElementType::FAIRY: _name = "Fairy"; break;
        //default: _name = "Unknown"; break;
    }
}

bool Type::isEffectiveAgainst(const Type& other) const {
    // I tipi Normal e Fighting sono efficaci contro il tipo Rock
    if ((_elementType == ElementType::NORMAL || _elementType == ElementType::FIGHTING) && other._elementType == ElementType::ROCK) {
        return true;
    }

    // Il tipo Fire è efficace contro i tipi Grass, Ice, Bug e Steel
    if (_elementType == ElementType::FIRE) {
        if (other._elementType == ElementType::GRASS || other._elementType == ElementType::ICE || other._elementType == ElementType::BUG || other._elementType == ElementType::STEEL) {
            return true;
        }
    }

    // Il tipo Water è efficace contro i tipi Fire, Ground e Rock
    if (_elementType == ElementType::WATER) {
        if (other._elementType == ElementType::FIRE || other._elementType == ElementType::GROUND || other._elementType == ElementType::ROCK) {
            return true;
        }
    }

    // Il tipo Electric è efficace contro i tipi Water e Flying
    if (_elementType == ElementType::ELECTRIC) {
        if (other._elementType == ElementType::WATER || other._elementType == ElementType::FLYING) {
            return true;
        }
    }

    // Il tipo Grass è efficace contro i tipi Water, Ground e Rock
    if (_elementType == ElementType::GRASS) {
        if (other._elementType == ElementType::WATER || other._elementType == ElementType::GROUND || other._elementType == ElementType::ROCK) {
            return true;
        }
    }

    // Il tipo Ice è efficace contro i tipi Grass, Ground, Flying e Dragon
    if (_elementType == ElementType::ICE) {
        if (other._elementType == ElementType::GRASS || other._elementType == ElementType::GROUND || other._elementType == ElementType::FLYING || other._elementType == ElementType::DRAGON) {
            return true;
        }
    }

    // Il tipo Fighting è efficace contro i tipi Normal, Ice, Rock, Dark e Steel
    if (_elementType == ElementType::FIGHTING) {
        if (other._elementType == ElementType::NORMAL || other._elementType == ElementType::ICE || other._elementType == ElementType::ROCK || other._elementType == ElementType::DARK || other._elementType == ElementType::STEEL) {
            return true;
        }
    }

    // Il tipo Poison è efficace contro i tipi Grass e Fairy
    if (_elementType == ElementType::POISON) {
        if (other._elementType == ElementType::GRASS || other._elementType == ElementType::FAIRY) {
            return true;
        }
    }

    // Il tipo Ground è efficace contro i tipi Fire, Electric, Poison, Rock e Steel
    if (_elementType == ElementType::GROUND) {
        if (other._elementType == ElementType::FIRE || other._elementType == ElementType::ELECTRIC || other._elementType == ElementType::POISON || other._elementType == ElementType::ROCK || other._elementType == ElementType::STEEL) {
            return true;
        }
    }

    // Il tipo Flying è efficace contro i tipi Grass, Fighting e Bug
    if (_elementType == ElementType::FLYING) {
        if (other._elementType == ElementType::GRASS || other._elementType == ElementType::FIGHTING || other._elementType == ElementType::BUG) {
            return true;
        }
    }

    // Il tipo Psychic è efficace contro i tipi Fighting e Poison
    if (_elementType == ElementType::PSYCHIC) {
        if (other._elementType==ElementType::FIGHTING || other._elementType == ElementType::POISON) {
            return true;
        }
    }

    // Il tipo Bug è efficace contro i tipi Grass, Psychic e Dark
    if (_elementType == ElementType::BUG) {
        if (other._elementType == ElementType::GRASS || other._elementType == ElementType::PSYCHIC || other._elementType == ElementType::DARK) {
            return true;
        }
    }

    // Il tipo Rock è efficace contro i tipi Fire, Ice, Flying e Bug
    if (_elementType == ElementType::ROCK) {
        if (other._elementType == ElementType::FIRE || other._elementType == ElementType::ICE || other._elementType == ElementType::FLYING || other._elementType == ElementType::BUG) {
            return true;
        }
    }

    // Il tipo Ghost è efficace contro i tipi Psychic e Ghost
    if (_elementType == ElementType::GHOST) {
        if (other._elementType == ElementType::PSYCHIC || other._elementType == ElementType::GHOST) {
            return true;
        }
    }

    // Il tipo Dragon è efficace contro il tipo Dragon
    if (_elementType == ElementType::DRAGON) {
        if (other._elementType == ElementType::DRAGON) {
            return true;
        }
    }

    // Il tipo Dark è efficace contro i tipi Psychic e Ghost
    if (_elementType == ElementType::DARK) {
        if (other._elementType == ElementType::PSYCHIC || other._elementType == ElementType::GHOST) {
            return true;
        }
    }

    // Il tipo Steel è efficace contro i tipi Ice, Rock e Fairy
    if (_elementType == ElementType::STEEL) {
        if (other._elementType == ElementType::ICE || other._elementType == ElementType::ROCK || other._elementType == ElementType::FAIRY) {
            return true;
        }
    }

    // Il tipo Fairy è efficace contro i tipi Fighting, Dragon e Dark
    if (_elementType == ElementType::FAIRY) {
        if (other._elementType == ElementType::FIGHTING || other._elementType == ElementType::DRAGON || other._elementType == ElementType::DARK) {
            return true;
        }
    }

    // Se nessuna delle condizioni sopra si verifica, i tipi non sono efficaci l'uno contro l'altro
    return false;
}


bool Type::isResistantTo(const Type& other) const {

    // Il tipo Electric è resistente contro i tipi Electric e Steel
    if (_elementType == ElementType::ELECTRIC) {
        if (other._elementType == ElementType::ELECTRIC || other._elementType == ElementType::STEEL) {
            return true;
        }
    }

    // Il tipo Grass è resistente contro i tipi Water, Electric, Grass e Ground
    if (_elementType == ElementType::GRASS) {
        if (other._elementType == ElementType::WATER || other._elementType == ElementType::ELECTRIC || other._elementType == ElementType::GRASS || other._elementType == ElementType::GROUND) {
            return true;
        }
    }

    // Il tipo Fighting è resistente contro i tipi Bug, Rock e Dark
    if (_elementType == ElementType::FIGHTING) {
        if (other._elementType == ElementType::BUG || other._elementType == ElementType::ROCK || other._elementType == ElementType::DARK) {
            return true;
        }
    }

    // Il tipo Poison è resistente contro i tipi Fighting, Poison, Bug, Grass e Fairy
    if (_elementType == ElementType::POISON) {
        if (other._elementType == ElementType::FIGHTING || other._elementType == ElementType::POISON || other._elementType == ElementType::BUG || other._elementType == ElementType::GRASS || other._elementType == ElementType::FAIRY) {
            return true;
        }
    }

    // Il tipo Ground è resistente contro i tipi Poison, Rock e Electric
    if (_elementType == ElementType::GROUND) {
        if (other._elementType == ElementType::POISON || other._elementType == ElementType::ROCK || other._elementType == ElementType::ELECTRIC) {
            return true;
        }
    }

    // Il tipo Flying è resistente contro i tipi Fighting, Bug e Grass
    if (_elementType == ElementType::FLYING) {
        if (other._elementType == ElementType::FIGHTING || other._elementType == ElementType::BUG || other._elementType == ElementType::GRASS) {
            return true;
        }
    }

    // Il tipo Psychic è resistente contro i tipi Fighting e Psychic
    if (_elementType == ElementType::PSYCHIC) {
        if (other._elementType == ElementType::FIGHTING || other._elementType == ElementType::PSYCHIC) {
            return true;
        }
    }

    // Il tipo Bug è resistente contro i tipi Fighting, Ground e Grass
    if (_elementType == ElementType::BUG) {
        if (other._elementType == ElementType::FIGHTING || other._elementType == ElementType::GROUND || other._elementType == ElementType::GRASS) {
            return true;
        }
    }

    // Il tipo Rock è resistente contro i tipi Normal, Flying, Poison e Fire
    if (_elementType == ElementType::ROCK) {
        if (other._elementType == ElementType::NORMAL || other._elementType == ElementType::FLYING || other._elementType == ElementType::POISON || other._elementType == ElementType::FIRE) {
            return true;
        }
    }

    // Il tipo Ghost è resistente contro il tipo Normal e Fighting
    if (_elementType == ElementType::GHOST) {
        if (other._elementType == ElementType::NORMAL || other._elementType == ElementType::FIGHTING) {
            return true;
        }
    }
    // Il tipo Dragon è resistente contro il tipo Electric, Fire, Grass e Water
    if (_elementType == ElementType::DRAGON) {
        if (other._elementType == ElementType::ELECTRIC || other._elementType == ElementType::FIRE || other._elementType == ElementType::GRASS || other._elementType == ElementType::WATER) {
            return true;
        }
    }

    // Il tipo Steel è resistente contro il tipo Normal, Flying, Poison, Rock, Bug, Steel, Grass, Psychic, Ice, Dragon e Fairy
    if (_elementType == ElementType::STEEL) {
        if (other._elementType == ElementType::NORMAL || other._elementType == ElementType::FLYING || other._elementType == ElementType::POISON || other._elementType == ElementType::ROCK || other._elementType == ElementType::BUG || other._elementType == ElementType::STEEL || other._elementType == ElementType::GRASS || other._elementType == ElementType::PSYCHIC || other._elementType == ElementType::ICE || other._elementType == ElementType::DRAGON || other._elementType == ElementType::FAIRY) {
            return true;
        }
    }

    // Il tipo Fairy è resistente contro il tipo Fighting, Bug e Dark
    if (_elementType == ElementType::FAIRY) {
        if (other._elementType == ElementType::FIGHTING || other._elementType == ElementType::BUG || other._elementType == ElementType::DARK) {
            return true;
        }
    }

    // Se il tipo non è resistente, restituisci false
    return false;

}


bool Type::isWeakTo(const Type& other) const {
    return other.isEffectiveAgainst(*this);
}

std::string Type::getName() const {
    return _name;
}
