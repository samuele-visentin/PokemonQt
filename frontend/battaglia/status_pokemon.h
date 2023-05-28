#ifndef STATUSPOKEMON_H
#define STATUSPOKEMON_H

#include "backend/pokemons/pokemon.h"
#include <QWidget>
#include <QLabel>
#include <QProgressBar>

class StatusPokemon: public QWidget
{
    Q_OBJECT
private:
    Pokemon* _pokemon;
    QLabel* name;
    QProgressBar* healthBar;
    QLabel* health;
    QLabel* status;
public:
    StatusPokemon(Pokemon* pokemon, QWidget* parent = nullptr);
};

#endif // STATUSPOKEMON_H
