#include "status_pokemon.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "backend/status/status.h"

StatusPokemon::StatusPokemon(Pokemon* pokemon, QWidget* parent)
    : QWidget(parent), _pokemon(pokemon)
{
    QVBoxLayout* column = new QVBoxLayout(this);
    column->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    QHBoxLayout* row = new QHBoxLayout();
    row->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    name = new QLabel("<b>"+QString::fromStdString(pokemon->getName())+"</b>",this);
    column->addWidget(name);

    healthBar = new QProgressBar(this);
    healthBar->setRange(0, pokemon->getMaxHealth());
    healthBar->setValue(pokemon->getMaxHealth());
    healthBar->setFixedHeight(12);
    healthBar->setTextVisible(false);
    healthBar->setStyleSheet(
            "QProgressBar {"
            "   border: 2px solid gray;"
            "   border-radius: 5px;"
            "   background: white;"
            "   border-style: outset;"
            "}"
            "QProgressBar::chunk {"
            "   background-color: #00FF00;"
            "   border: 2px solid #00FF00;"
            "   border-radius: 3px;"
            "}");
    row->addWidget(healthBar);

    health = new QLabel(
                QString::number(pokemon->getHealth()) +
                " / " + QString::number(pokemon->getMaxHealth()),
                this
            );
    row->addWidget(health);
    column->addLayout(row);

    if(pokemon->hasStatus()) {
        status = new QLabel(QString::fromStdString(pokemon->getStatus().getName()));
        column->addWidget(status);
    }
    //setLayout()
}
