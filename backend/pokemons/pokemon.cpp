#include "pokemon.h"
#include "backend/attacks/attack.h"
#include "backend/status/status.h"

Pokemon::Pokemon(const std::string& username, int level, int health, int attack, int defense, int speed, const std::vector<Attack>& listAttacks) :
    _username(username), _level(level), _maxHealth(health), _health(health), _attack(attack), _defense(defense), _speed(speed), _status(nullptr), attacks(listAttacks) {}

Pokemon::Pokemon(const Pokemon& p) :
    _username(p._username), _level(p._level), _maxHealth(p._maxHealth), _health(p._health), _attack(p._attack), _defense(p._defense), _speed(p._speed),
    _status(p.hasStatus() ? p._status->clone() : nullptr),
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
        _speed = p._speed;
        _status = p.hasStatus()
                ? p._status->clone() : nullptr;
        attacks = p.attacks;
    }
    return *this;
}

Pokemon::~Pokemon() {
    if(hasStatus())
       delete _status;
}

std::string Pokemon::getName() const { return _username; }
std::string Pokemon::getSprite() const { return sprite; }
int Pokemon::getLevel() const { return _level; }
int Pokemon::getMaxHealth() const { return _maxHealth; }
int Pokemon::getHealth() const { return _health; }
int Pokemon::getAttack() const { return _attack; }
int Pokemon::getDefense() const { return _defense; }
int Pokemon::getSpeed() const { return _speed; }
Type Pokemon::getType() const { return _type; }
const Status& Pokemon::getStatus() const { return *_status; }

Attack& Pokemon::getAttackMove(int index) {
    auto it = attacks.begin();
    std::advance(it, index);
    return *it;
}

std::vector<Attack>& Pokemon::getAttackList() {
    return attacks;
}

void Pokemon::setStatus(Status* status) {
    if(hasStatus()) {
        delete _status;
    }
    _status = status;
}

void Pokemon::removeStatus() {
    setStatus(nullptr);
}

bool Pokemon::hasStatus() const { return _status != nullptr; }

void Pokemon::setHealth(int health) { _health = health; }

void Pokemon::takeDamage(int damage) {
    _health = _health > damage ? _health - damage : 0;
}

bool Pokemon::isFainted() const {
    return _health <= 0;
}

void Pokemon::attack(Pokemon& enemy, int indexAttack) {

}
