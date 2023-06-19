#ifndef INFO_WIDGET_H
#define INFO_WIDGET_H

#include "backend/entity/entity.h"
#include "frontend/battaglia/status_pokemon.h"
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QHBoxLayout>

class InfoWidget : public QWidget
{
    Q_OBJECT
private:
    Entity& _character;
    QHBoxLayout* row;
    QWidget* visitorWidget;
    StatusPokemonWidget* statusPokemon;
public:
    InfoWidget(Entity& character, QWidget* parent = 0);
    void refreshHealth();
    void refreshInfo();
    void refreshStatus();
};

#endif // INFO_WIDGET_H
