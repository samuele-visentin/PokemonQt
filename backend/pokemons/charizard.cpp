#include "charizard.h"

Charizard::Charizard(int level, int health,
                     int attack, int defense,
                     int speed,
                     const std::vector<Attack>& vec,
                     const std::string& username) :
    Pokemon(username, level, health, attack, defense, speed, vec){}

const std::string Charizard::Pokemon::_name = "Charizard";
const Type Charizard::Pokemon::_type = Type::FIRE_TYPE;
const std::string Charizard::Pokemon::sprite= "charizard.png";

Charizard* Charizard::clone() const {
    return new Charizard(*this);
}
