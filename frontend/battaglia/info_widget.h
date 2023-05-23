#ifndef INFO_H
#define INFO_H

#include "backend/entity/entity.h"
#include "backend/pokemons/pokemon.h"
#include <QWidget>
#include <QProgressBar>
#include <QLabel>

class InfoWidget : public QWidget
{
    Q_OBJECT
private:
    Entity& _character;
    QProgressBar* healthBar;
    QLabel* name;
    QLabel* health;
    QLabel* status;
public:
    InfoWidget(Entity& character, QWidget* parent = 0);
    void refresh();
};

#endif // INFO_H
