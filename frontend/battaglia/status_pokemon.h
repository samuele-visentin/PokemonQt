#ifndef STATUSPOKEMON_H
#define STATUSPOKEMON_H

#include "backend/pokemons/pokemon.h"
#include <QWidget>
#include <QLabel>
#include <QProgressBar>

class StatusPokemonWidget: public QWidget
{
    Q_OBJECT
private:
    QLabel* name;
    QLabel* type;
    QProgressBar* healthBar;
    QLabel* health;
    QLabel* status;
public:
    StatusPokemonWidget(Pokemon& pokemon, QWidget* parent = nullptr);
    void refreshHealth(const Pokemon& pokemon);
    void changePokemon(const Pokemon& pokemon);
    void refreshStatus(const Pokemon& pokemon);
};

#endif // STATUSPOKEMON_H
