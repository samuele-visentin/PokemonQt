#include "info.h"
#include "backend/status/status.h"
#include "backend/pokemons/pokemon.h"
#include <QHBoxLayout>

Info::Info(Pokemon& pokemon, QWidget* parent) : QWidget(parent), _pokemon(pokemon)
{   
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    name = new QLabel(QString::fromStdString(pokemon.getName()));
    layout->addWidget(name);

    healthBar = new QProgressBar();
    healthBar->setMaximum(pokemon.getMaxHealth());
    healthBar->setMinimum(0);
    layout->addWidget(healthBar);

    health = new QLabel(QString::number(pokemon.getHealth()) + " / " + QString::number(pokemon.getMaxHealth()));
    layout->addWidget(health);

    if(pokemon.hasStatus()) {
        status = new QLabel(QString::fromStdString(pokemon.getStatus().getName()));
        layout->addWidget(status);
    }
}

void Info::show() const {
    name->setText(QString::fromStdString(_pokemon.getName()));
    healthBar->setValue(_pokemon.getHealth());
    health->setText(QString::number(_pokemon.getHealth()));
    if(_pokemon.hasStatus())
        status->setText(QString::fromStdString(_pokemon.getStatus().getName()));
}
