#include "pokemon.h"
#include "backend/attacks/attack.h"
#include "backend/pokemons/charizard.h"
#include "backend/pokemons/darkrai.h"
#include "backend/pokemons/giratina.h"
#include "backend/pokemons/infernape.h"
#include "backend/pokemons/pikachu.h"
#include "backend/status/status.h"
#include <QString>

Pokemon::Pokemon(
    const Type& type, const std::string& sprite,
    const std::string& name, const std::vector<Attack>& attacks,
    int health, int attack,
    int defense, int speed)
    : _type(type), _sprite(sprite),
      _name(name), _maxHealth(health),
      _health(health), _attack(attack),
      _defense(defense), _speed(speed),
      _status(nullptr), _attacks(attacks)
{}

Pokemon::Pokemon(const Pokemon& p) :
    _type(p._type), _sprite(p._sprite),
    _name(p._name), _maxHealth(p._maxHealth),
    _health(p._health), _attack(p._attack),
    _defense(p._defense), _speed(p._speed),
    _status(p.hasStatus() ? p._status->clone() : nullptr),
    _attacks(p._attacks)
{}

Pokemon& Pokemon::operator=(const Pokemon& p) {
    if(this != &p) {
        if(_status)
           delete _status;
        _type = p._type;
        _sprite = p._sprite;
        _name = p._name;
        _maxHealth = p._maxHealth;
        _health = p._health;
        _attack = p._attack;
        _defense = p._defense;
        _speed = p._speed;
        _status = p.hasStatus()
                ? p._status->clone() : nullptr;
        _attacks = p._attacks;
    }
    return *this;
}

Pokemon::~Pokemon() {
    if(_status)
       delete _status;
}

std::string Pokemon::getName() const { return _name; }
std::string Pokemon::getSprite() const { return _sprite; }
int Pokemon::getMaxHealth() const { return _maxHealth; }
int Pokemon::getHealth() const { return _health; }
int Pokemon::getAttack() const { return _attack; }
int Pokemon::getDefense() const { return _defense; }
int Pokemon::getSpeed() const { return _speed; }
Type Pokemon::getPokemonType() const { return _type; }

Attack& Pokemon::getAttackMove(int index) {
    auto it = _attacks.begin();
    std::advance(it, index);
    return *it;
}

std::vector<Attack>& Pokemon::getAttackList() {
    return _attacks;
}

void Pokemon::setStatus(const Status& status) {
    if(_status) {
        delete _status;
    }
    _status = status.clone();
}

const Status& Pokemon::getStatus() const { return *_status; }

void Pokemon::removeStatus() {
    if(_status) delete _status;
    _status = nullptr;
}

bool Pokemon::hasStatus() const { return _status != nullptr; }

bool Pokemon::isFainted() const {
    return _health <= 0;
}

void Pokemon::doAttack(Pokemon& enemy, Attack& attack) const {
    int damage = attack.calculateDamage(_attack, enemy._defense);
    if (_type.isResistantTo(enemy._type.getElementType()))
        damage *= 0.5;
    else if(_type.isEffectiveAgainst(enemy._type.getElementType()))
        damage *= 1.5;
    enemy._health = enemy._health > damage ? enemy._health - damage : 0;
}

void Pokemon::statusEffect() {
    int damage = _status->statusEffect();
    _health = _health > damage ? _health-damage : 0;
}

QDataStream& operator<<(QDataStream& out, const Pokemon& pokemon) {
    return out << static_cast<int>(pokemon.getTypology())
                << QString::fromStdString(pokemon._name)
                << pokemon._maxHealth << pokemon._attack
                << pokemon._defense << pokemon._speed;
}

QDataStream& operator>>(QDataStream& in, Pokemon*& pokemon) {
    if(pokemon != nullptr) delete pokemon;
    int typeClass;
    QString name;
    int health, attack, defense, speed;
    in >> typeClass >> name >> health >> attack >> defense >> speed;
    switch(static_cast<PokemonTypology::typology>(typeClass)) {
        case PokemonTypology::typology::charizard:
            pokemon = new Charizard(health, attack, defense, speed, name.toStdString());
            break;
        case PokemonTypology::typology::darkrai:
            pokemon = new Darkrai(health, attack, defense, speed, name.toStdString());
            break;
        case PokemonTypology::typology::giratina:
            pokemon = new Giratina(health, attack, defense, speed, name.toStdString());
            break;
        case PokemonTypology::typology::infernape:
            pokemon = new Infernape(health, attack, defense, speed, name.toStdString());
            break;
        case PokemonTypology::typology::pikachu:
            pokemon = new Pikachu(health, attack, defense, speed, name.toStdString());
            break;
    }
    return in;
}
