#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include <vector>
#include "backend/status/status.h"
#include "backend/type.h"
#include <QDataStream>

class Attack {
private:
    std::string name;
    unsigned short maxUsage;
    unsigned short currentUsage;
    int power;
    int accuracy;
    Type::ElementType _type;
    Status* _status;
public:
    Attack(Type::ElementType type,
           const std::string& name = "none",
           unsigned short usage=0,
           int power=0,
           int accuracy=0,
           Status* status = nullptr);
    Attack(const Attack& attack);
    Attack& operator=(const Attack& attack);
    ~Attack();
    std::string getName() const;
    unsigned short getMaxUsage() const;
    unsigned short getCurrentUsage() const;
    void consume();
    int calculateDamage(int attack, int defense);
    const Status& getStatus() const;
    bool applyStatus() const;
    Type::ElementType getType() const;

    static std::vector<const Attack*> getAllAttacks();
    static const Attack TACKLE;
    static const Attack HEADBUTT;
    static const Attack QUICK_ATTACK;
    static const Attack RETURN;

    // Tipo: FIRE
    static const Attack EMBER;
    static const Attack FLAMETHROWER;
    static const Attack FIRE_BLAST;
    static const Attack FLAME_WHEEL;

    // Tipo: WATER
    static const Attack WATER_GUN;
    static const Attack SURF;
    static const Attack HYDRO_PUMP;
    static const Attack AQUA_TAIL;

    // Tipo: GRASS
    static const Attack RAZOR_LEAF;
    static const Attack GRASS_KNOT;
    static const Attack LEAF_STORM;
    static const Attack ENERGY_BALL;

    // Tipo: ELECTRIC
    static const Attack THUNDER_SHOCK;
    static const Attack THUNDERBOLT;
    static const Attack THUNDER;
    static const Attack VOLT_TACKLE;

    // Tipo: FLYING
    static const Attack GUST;
    static const Attack AERIAL_ACE;
    static const Attack FLY;
    static const Attack AIR_SLASH;

    // Tipo: DARK
    static const Attack BITE;
    static const Attack CRUNCH;
    static const Attack PURSUIT;
    static const Attack DARK_PULSE;

    // Tipo: GHOST
    static const Attack SHADOW_BALL;
    static const Attack NIGHT_SHADE;
    static const Attack SHADOW_CLAW;
    static const Attack SHADOW_SNEAK;

    // Tipo: GROUND
    static const Attack EARTHQUAKE;
    static const Attack DIG;
    static const Attack EARTH_POWER;
    static const Attack SANDSTORM;

    // Tipo: ROCK
    static const Attack ROCK_SLIDE;
    static const Attack STONE_EDGE;
    static const Attack ROCK_TOMB;
    static const Attack ROCK_POLISH;

    // Tipo: ICE
    static const Attack ICE_BEAM;
    static const Attack AVALANCHE;
    static const Attack ICE_SHARD;
    static const Attack BLIZZARD;
};

#endif // ATTACK_H
