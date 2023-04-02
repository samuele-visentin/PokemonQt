#include "info.h"
#include "backend/status/status.h"
#include <QHBoxLayout>

Info::Info(Pokemon& pokemon, QWidget* parent) : QWidget(parent), _pokemon(pokemon)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    name = new QLabel(QString::fromStdString(pokemon.getName()));
    layout->addWidget(name);

    healthBar = new QProgressBar();
    layout->addWidget(healthBar);

    health = new QLabel(QString::number(pokemon.getHealth()) + " / " + QString::number(pokemon.getMaxHealth()));
    layout->addWidget(health);

    if(pokemon.hasStatus()) {
        status = new QLabel(QString::fromStdString(pokemon.getStatus().getName()));
        layout->addWidget(status);
    }
}
