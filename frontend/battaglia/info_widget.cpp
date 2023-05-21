#include "info_widget.h"
#include "backend/status/status.h"
#include "backend/pokemons/pokemon.h"
#include <QHBoxLayout>

InfoWidget::InfoWidget(Pokemon& pokemon, QWidget* parent) : QWidget(parent), _pokemon(pokemon)
{   
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    name = new QLabel(QString::fromStdString(pokemon.getName()),this);
    layout->addWidget(name);

    healthBar = new QProgressBar(this);
    healthBar->setRange(0, pokemon.getMaxHealth());
    healthBar->setValue(pokemon.getMaxHealth());
    layout->addWidget(healthBar);

    health = new QLabel(
                QString::number(pokemon.getHealth()) +
                " / " + QString::number(pokemon.getMaxHealth()),
                this
            );
    layout->addWidget(health);

    if(pokemon.hasStatus()) {
        status = new QLabel(QString::fromStdString(pokemon.getStatus().getName()));
        layout->addWidget(status);
    }
}

void InfoWidget::refresh() {
    name->setText(QString::fromStdString(_pokemon.getName()));
    healthBar->setValue(_pokemon.getHealth());
    health->setText(QString::number(_pokemon.getHealth()));
    if(_pokemon.hasStatus())
        status->setText(QString::fromStdString(_pokemon.getStatus().getName()));
}
