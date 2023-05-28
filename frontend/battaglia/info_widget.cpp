#include "info_widget.h"
#include "frontend/battaglia/entity_visitor.h"
#include <QHBoxLayout>

InfoWidget::InfoWidget(Entity& character, QWidget* parent)
   : QWidget(parent), _character(character)
{
    EntityVisitor visitor;
    character.accept(visitor);
    QHBoxLayout* row = new QHBoxLayout(this);
    row->addWidget(visitor.getWidget());
    statusPokemon = new StatusPokemon(character.getCurrentPokemon(), this);
    row->addWidget(statusPokemon);
    row->setAlignment(Qt::AlignCenter);
}

void InfoWidget::refresh() {

}
