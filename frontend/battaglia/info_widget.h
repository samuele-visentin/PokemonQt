#ifndef INFO_H
#define INFO_H

#include "backend/pokemons/pokemon.h"
#include <QWidget>
#include <QProgressBar>
#include <QLabel>

class InfoWidget : public QWidget
{
    Q_OBJECT
private:
    Pokemon& _pokemon;
    QProgressBar* healthBar;
    QLabel* name;
    QLabel* health;
    QLabel* status;
public:
    InfoWidget(Pokemon& pokemon,
               QWidget* parent = 0
            );
    void refresh();
};

#endif // INFO_H
