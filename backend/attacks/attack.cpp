#include "attack.h"

int Attack::getPower() const
{
    return power;
}

int Attack::getAccuracy() const
{
    return accuracy;
}

Attack::Attack(Type::ElementType type, const std::string& s, unsigned short cc, int pow, int acc) :
    name(s), maxUsage(cc), currentUsage(cc), power(pow), accuracy(acc), _type(type)
{}


unsigned short Attack::getMaxUsage() const {
    return maxUsage;
}

unsigned short Attack::getCurrentUsage() const {
    return currentUsage;
}

std::string Attack::getName() const {
    return name;
}

void Attack::consume() { --currentUsage; }

std::vector<const Attack*> Attack::getAllAttacks() {
    std::vector<const Attack*> allAttacks = {
        &TACKLE,
        &HEADBUTT,
        &QUICK_ATTACK,
        &RETURN,
        &EMBER,
        &FLAMETHROWER,
        &FIRE_BLAST,
        &FLAME_WHEEL,
        &WATER_GUN,
        &SURF,
        &HYDRO_PUMP,
        &AQUA_TAIL,
        &RAZOR_LEAF,
        &GRASS_KNOT,
        &LEAF_STORM,
        &ENERGY_BALL,
        &THUNDER_SHOCK,
        &THUNDERBOLT,
        &THUNDER,
        &VOLT_TACKLE,
        &GUST,
        &AERIAL_ACE,
        &FLY,
        &AIR_SLASH,
        &BITE,
        &CRUNCH,
        &PURSUIT,
        &DARK_PULSE,
        &SHADOW_BALL,
        &NIGHT_SHADE,
        &SHADOW_CLAW,
        &SHADOW_SNEAK,
        &EARTHQUAKE,
        &DIG,
        &EARTH_POWER,
        &SANDSTORM,
        &ROCK_SLIDE,
        &STONE_EDGE,
        &ROCK_TOMB,
        &ROCK_POLISH,
        &ICE_BEAM,
        &AVALANCHE,
        &ICE_SHARD,
        &BLIZZARD
    };
    return allAttacks;
}

// Tipo: NORMAL
const Attack Attack::TACKLE(Type::ElementType::NORMAL, "Tackle", 35, 40, 100);
const Attack Attack::HEADBUTT(Type::ElementType::NORMAL, "Testata", 15, 70, 100);
const Attack Attack::QUICK_ATTACK(Type::ElementType::NORMAL, "Attacco Rapido", 30, 40, 100);
const Attack Attack::RETURN(Type::ElementType::NORMAL, "Ritorno", 20, 0, 100);

// Tipo: FIRE
const Attack Attack::EMBER(Type::ElementType::FIRE, "Braciere", 25, 40, 100);
const Attack Attack::FLAMETHROWER(Type::ElementType::FIRE, "Lanciafiamme", 15, 90, 100);
const Attack Attack::FIRE_BLAST(Type::ElementType::FIRE, "Fuocobomba", 5, 110, 85);
const Attack Attack::FLAME_WHEEL(Type::ElementType::FIRE, "Ruotafuoco", 25, 60, 100);

// Tipo: WATER
const Attack Attack::WATER_GUN(Type::ElementType::WATER, "Pistolacqua", 25, 40, 100);
const Attack Attack::SURF(Type::ElementType::WATER, "Surf", 15, 90, 100);
const Attack Attack::HYDRO_PUMP(Type::ElementType::WATER, "Idropompa", 5, 110, 80);
const Attack Attack::AQUA_TAIL(Type::ElementType::WATER, "Idrondata", 10, 90, 90);

// Tipo: GRASS
const Attack Attack::RAZOR_LEAF(Type::ElementType::GRASS, "Foglielama", 25, 55, 95);
const Attack Attack::GRASS_KNOT(Type::ElementType::GRASS, "Groffiltiro", 20, 0, 100);
const Attack Attack::LEAF_STORM(Type::ElementType::GRASS, "Tempesta Verde", 5, 130, 90);
const Attack Attack::ENERGY_BALL(Type::ElementType::GRASS, "Energipalla", 10, 90, 100);

// Tipo: ELECTRIC
const Attack Attack::THUNDER_SHOCK(Type::ElementType::ELECTRIC, "Tuonoshock", 30, 40, 100);
const Attack Attack::THUNDERBOLT(Type::ElementType::ELECTRIC, "Fulmincolpo", 15, 90, 100);
const Attack Attack::THUNDER(Type::ElementType::ELECTRIC, "Tuono", 10, 110, 70);
const Attack Attack::VOLT_TACKLE(Type::ElementType::ELECTRIC, "Locomovolt", 10, 120, 100);

// Tipo: FLYING
const Attack Attack::GUST(Type::ElementType::FLYING, "Raffica", 35, 40, 100);
const Attack Attack::AERIAL_ACE(Type::ElementType::FLYING, "Asso Aereo", 20, 60, 0);
const Attack Attack::FLY(Type::ElementType::FLYING, "Volo", 15, 90, 95);
const Attack Attack::AIR_SLASH(Type::ElementType::FLYING, "Eterelama", 15, 75, 95);

// Tipo: DARK
const Attack Attack::BITE(Type::ElementType::DARK, "Morso", 25, 60, 100);
const Attack Attack::CRUNCH(Type::ElementType::DARK, "Sgranocchio", 15, 80, 100);
const Attack Attack::PURSUIT(Type::ElementType::DARK, "Inseguimento", 20, 40, 100);
const Attack Attack::DARK_PULSE(Type::ElementType::DARK, "Neropulsar", 15, 80, 100);

// Tipo: GHOST
const Attack Attack::SHADOW_BALL(Type::ElementType::GHOST, "Palla Ombra", 15, 80, 100);
const Attack Attack::NIGHT_SHADE(Type::ElementType::GHOST, "Ombra Notturna", 15, 0, 100);
const Attack Attack::SHADOW_CLAW(Type::ElementType::GHOST, "Ombrartiglio", 15, 70, 100);
const Attack Attack::SHADOW_SNEAK(Type::ElementType::GHOST, "Furtivombra", 30, 40, 100);

// Tipo: GROUND
const Attack Attack::EARTHQUAKE(Type::ElementType::GROUND, "Terremoto", 10, 100, 100);
const Attack Attack::DIG(Type::ElementType::GROUND, "Fossa", 10, 80, 100);
const Attack Attack::EARTH_POWER(Type::ElementType::GROUND, "Geoforza", 10, 90, 100);
const Attack Attack::SANDSTORM(Type::ElementType::GROUND, "Terrempesta", 10, 0, 0);

// Tipo: ROCK
const Attack Attack::ROCK_SLIDE(Type::ElementType::ROCK, "Frana", 10, 75, 90);
const Attack Attack::STONE_EDGE(Type::ElementType::ROCK, "Pietrataglio", 5, 100, 80);
const Attack Attack::ROCK_TOMB(Type::ElementType::ROCK, "Rocciotomba", 15, 60, 95);
const Attack Attack::ROCK_POLISH(Type::ElementType::ROCK, "Lucidatura", 20, 0, 0);

// Tipo: ICE
const Attack Attack::ICE_BEAM(Type::ElementType::ICE, "Geloraggio", 10, 90, 100);
const Attack Attack::AVALANCHE(Type::ElementType::ICE, "Slavina", 10, 60, 100);
const Attack Attack::ICE_SHARD(Type::ElementType::ICE, "Geloscheggia", 30, 40, 100);
const Attack Attack::BLIZZARD(Type::ElementType::ICE, "Bora", 5, 110, 70);
