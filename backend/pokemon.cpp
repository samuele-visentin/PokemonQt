#include "pokemon.h"

Pokemon::Pokemon(const std::string& name, const Type& type, int level, int health, int attack, int defense, int specialAttack, int specialDefense, int speed) :
    _name(name), _type(type), _level(level), _maxHealth(health), _health(health), _attack(attack), _defense(defense), _specialAttack(specialAttack), _specialDefense(specialDefense), _speed(speed), _status(nullptr) {}

Pokemon::Pokemon(const Pokemon& p) :
    _name(p._name), _type(p._type), _level(p._level), _maxHealth(p._maxHealth), _health(p._health), _attack(p._attack), _defense(p._defense), _specialAttack(p._specialAttack), _specialDefense(p._specialDefense), _speed(p._speed),
    _status(new Status()) {}

std::string Pokemon::getName() const { return _name; }
Type Pokemon::getType() const { return _type; }
int Pokemon::getLevel() const { return _level; }
int Pokemon::getMaxHealth() const { return _maxHealth; };
int Pokemon::getHealth() const { return _health; }
int Pokemon::getAttack() const { return _attack; }
int Pokemon::getDefense() const { return _defense; }
int Pokemon::getSpecialAttack() const { return _specialAttack; }
int Pokemon::getSpecialDefense() const { return _specialDefense; }
int Pokemon::getSpeed() const { return _speed; }

void Pokemon::applyStatus(Status* status) {
    _status = status;
}

void Pokemon::removeStatus() {
    if(hasStatus()) {
        delete _status;
        _status = nullptr;
    }
}

bool Pokemon::hasStatus() const { return _status != nullptr; }

void Pokemon::setHealth(int health) { _health = health; }
