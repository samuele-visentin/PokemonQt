#ifndef INFO_WIDGET_H
#define INFO_WIDGET_H

#include "backend/entity/entity.h"
#include "frontend/battaglia/status_pokemon.h"
#include <QWidget>
#include <QProgressBar>
#include <QLabel>

class InfoWidget : public QWidget
{
    Q_OBJECT
private:
    Entity& _character;
    StatusPokemon* statusPokemon;
public:
    InfoWidget(Entity& character, QWidget* parent = 0);
    void refresh();
};

#endif // INFO_WIDGET_H
