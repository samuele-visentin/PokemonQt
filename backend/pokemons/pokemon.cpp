#include "pokemon.h"
#include "backend/attacks/attack.h"

Pokemon::Pokemon(const std::string& username, int level, int health, int attack, int defense, int specialAttack, int specialDefense, int speed, const std::vector<Attack>& vec) :
    _username(username), _level(level), _maxHealth(health), _health(health), _attack(attack), _defense(defense), _specialAttack(specialAttack), _specialDefense(specialDefense), _speed(speed), _status(nullptr), attacks(vec) {}

Pokemon::Pokemon(const Pokemon& p) :
    _username(p._username), _level(p._level), _maxHealth(p._maxHealth), _health(p._health), _attack(p._attack), _defense(p._defense), _specialAttack(p._specialAttack), _specialDefense(p._specialDefense), _speed(p._speed),
    _status(p.hasStatus() ? new Status(*(p._status)) : nullptr),
    attacks(p.attacks) {}

Pokemon& Pokemon::operator=(const Pokemon& p) {
    if(this != &p) {
        if(hasStatus())
           delete _status;
        _username = p._username;
        _maxHealth = p._maxHealth;
        _health = p._health;
        _attack = p._attack;
        _defense = p._defense;
        _specialAttack = p._specialAttack;
        _specialDefense = p._specialDefense;
        _speed = p._speed;
        _status = p.hasStatus() ? new Status(*(p._status)) : nullptr;
    }
    return *this;
}

Pokemon::~Pokemon() {
    if(hasStatus())
       delete _status;
}

std::string Pokemon::getName() const { return _username; }
int Pokemon::getLevel() const { return _level; }
int Pokemon::getMaxHealth() const { return _maxHealth; }
int Pokemon::getHealth() const { return _health; }
int Pokemon::getAttack() const { return _attack; }
int Pokemon::getDefense() const { return _defense; }
int Pokemon::getSpecialAttack() const { return _specialAttack; }
int Pokemon::getSpecialDefense() const { return _specialDefense; }
int Pokemon::getSpeed() const { return _speed; }
Type Pokemon::getType() const { return _type; }

void Pokemon::setStatus(const Status& status) {
    _status = new Status(status);
}

void Pokemon::removeStatus() {
    if(hasStatus()) {
       delete _status;
       _status = nullptr;
    }
}

bool Pokemon::hasStatus() const { return _status != nullptr; }

void Pokemon::setHealth(int health) { _health = health; }

void Pokemon::takeDamage(int damage) {
    _health = _health - damage;
}

void Pokemon::attack(Pokemon& defender, int attackIndex) {
    if (attackIndex < 0 || attackIndex >= (int)attacks.size()) {
        throw "Error attack";
    }
    (attacks[attackIndex]).useMove(*this, defender);
}
