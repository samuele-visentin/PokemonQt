#include "status_pokemon.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "backend/status/status.h"

StatusPokemonWidget::StatusPokemonWidget(Pokemon& pokemon, QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* column = new QVBoxLayout(this);
    column->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    QHBoxLayout* rowHealth = new QHBoxLayout();
    rowHealth->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    QHBoxLayout* rowName = new QHBoxLayout();
    name = new QLabel("<b>"+QString::fromStdString(pokemon.getName())+"</b>",this);
    rowName->addWidget(name);
    type = new QLabel(
        "Tipo: " + QString::fromStdString(pokemon.getPokemonType().getName()),
        this);
    rowName->addWidget(type);
    column->addLayout(rowName);

    healthBar = new QProgressBar(this);
    healthBar->setRange(0, pokemon.getMaxHealth());
    healthBar->setValue(pokemon.getMaxHealth());
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
    rowHealth->addWidget(healthBar);

    health = new QLabel(
                QString::number(pokemon.getHealth()) +
                " / " + QString::number(pokemon.getMaxHealth()),
                this
            );
    rowHealth->addWidget(health);
    column->addLayout(rowHealth);

    if(pokemon.hasStatus()) {
        status = new QLabel(QString::fromStdString(pokemon.getStatus().getName()));
    } else {
        status = new QLabel(this);
        status->hide();
    }
    column->addWidget(status);
}

void StatusPokemonWidget::refreshHealth(const Pokemon& pokemon) {
    healthBar->setValue(pokemon.getHealth());
    health->setText(
        QString::number(pokemon.getHealth()) +
        " / " + QString::number(pokemon.getMaxHealth()));
}

void StatusPokemonWidget::changePokemon(const Pokemon& pokemon) {
    name->setText("<b>"+QString::fromStdString(pokemon.getName())+"</b>");
    type->setText("Tipo: " + QString::fromStdString(pokemon.getPokemonType().getName()));

    healthBar->setRange(0, pokemon.getMaxHealth());
    healthBar->setValue(pokemon.getMaxHealth());
    health->setText(
                QString::number(pokemon.getHealth()) +
                " / " + QString::number(pokemon.getMaxHealth()));

    if(pokemon.hasStatus()) {
        status->setText(QString::fromStdString(pokemon.getStatus().getName()));
    }
}

void StatusPokemonWidget::refreshStatus(const Pokemon& pokemon) {
    if(pokemon.hasStatus()) {
        status->setText(QString::fromStdString(pokemon.getStatus().getName()));
        status->setVisible(true);
    } else {
        status->hide();
    }
}


