#include "info_widget.h"
#include "backend/pokemons/pokemon.h"
#include <QHBoxLayout>
#include "backend/status/status.h"
#include "frontend/battaglia/entity_visitor.h"

InfoWidget::InfoWidget(Entity& character, QWidget* parent)
   : QWidget(parent), _character(character), _currentPokemon(&character.getPokemon(0))
{   
    QVBoxLayout* column = new QVBoxLayout(this);
    column->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    QHBoxLayout* row = new QHBoxLayout();
    row->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    name = new QLabel("<b>"+QString::fromStdString(_currentPokemon->getName())+"</b>",this);
    column->addWidget(name);

    EntityVisitor visitor;
    character.accept(visitor);
    row->addWidget(visitor.getWidget());

    healthBar = new QProgressBar(this);
    healthBar->setRange(0, _currentPokemon->getMaxHealth());
    healthBar->setValue(_currentPokemon->getMaxHealth());
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
                QString::number(_currentPokemon->getHealth()) +
                " / " + QString::number(_currentPokemon->getMaxHealth()),
                this
            );
    row->addWidget(health);
    column->addLayout(row);

    if(_currentPokemon->hasStatus()) {
        status = new QLabel(QString::fromStdString(_currentPokemon->getStatus().getName()));
        column->addWidget(status);
    }
    setLayout(column);
}

void InfoWidget::refresh() {
    name->setText(QString::fromStdString(_currentPokemon->getName()));
    healthBar->setValue(_currentPokemon->getHealth());
    health->setText(QString::number(_currentPokemon->getHealth()));
    if(_currentPokemon->hasStatus())
        status->setText(QString::fromStdString((_currentPokemon->getStatus()).getName()));
}
