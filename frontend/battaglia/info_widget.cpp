#include "info_widget.h"
#include "frontend/battaglia/entity_visitor.h"
#include <QHBoxLayout>

InfoWidget::InfoWidget(Entity& character, QWidget* parent)
   : QWidget(parent), _character(character)
{
    EntityVisitor visitor;
    character.accept(visitor);
    visitorWidget = visitor.getWidget();
    row = new QHBoxLayout(this);
    row->addWidget(visitorWidget);
    statusPokemon = new StatusPokemonWidget(character.getCurrentPokemon(), this);
    row->addWidget(statusPokemon);
    row->setAlignment(Qt::AlignCenter);
}

void InfoWidget::refreshHealth() {
    statusPokemon->refreshHealth(_character.getCurrentPokemon());
    statusPokemon->refreshStatus(_character.getCurrentPokemon());
}

void InfoWidget::refreshInfo() {
    row->removeWidget(visitorWidget);
    delete visitorWidget;
    EntityVisitor visitor;
    _character.accept(visitor);
    visitorWidget = visitor.getWidget();
    row->insertWidget(0, visitorWidget);
    statusPokemon->changePokemon(_character.getCurrentPokemon());
}

void InfoWidget::refreshStatus() {
    statusPokemon->refreshStatus(_character.getCurrentPokemon());
}
