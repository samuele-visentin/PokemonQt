#include "entity_visitor.h"

QWidget* EntityVisitor::getWidget() { return widget; }

void EntityVisitor::visitPlayer(Player& player)  {

}

void EntityVisitor::visitEnemy(Enemy& enemy) {

}

void EntityVisitor::characterSprite(Entity& character) {
    widget = new QLabel();
}

