#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include <QDataStream>
#include "backend/type.h"
#include "backend/attacks/attack.h"
#include "backend/status/status.h"
#include "backend/pokemons/pokemon_typology.h"

class Pokemon {
    friend QDataStream& operator<<(QDataStream& out, const Pokemon& pokemon);
    friend QDataStream& operator>>(QDataStream& in, Pokemon*& pokemon);
private:
    Type _type;
    std::string _sprite;
    std::string _name;
    int _maxHealth;
    int _health;
    int _attack;
    int _defense;
    int _speed;
    Status* _status;
    std::vector<Attack> _attacks;
public:
    Pokemon(const Type& type, const std::string& sprite,
            const std::string& name, const std::vector<Attack>& attacks,
            int health, int attack,
            int defense, int speed
    );
    Pokemon(const Pokemon& p);
    Pokemon& operator=(const Pokemon& p);
    virtual ~Pokemon();
    virtual Pokemon* clone() const=0;
    bool operator==(const Pokemon& pokemon) const;
    virtual PokemonTypology::typology getTypology() const=0;
    std::string getName() const;
    std::string getSprite() const;
    int getMaxHealth() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getSpeed() const;
    Attack& getAttackMove(int index);
    std::vector<Attack>& getAttackList();
    Type getPokemonType() const;
    void setStatus(const Status& status);
    const Status& getStatus() const;
    void statusEffect();
    void removeStatus();
    bool hasStatus() const;
    bool isFainted() const;
    void doAttack(Pokemon& enemy, Attack& attack) const;
    void takeDamage(int damage);
};

#endif // POKEMON_H
