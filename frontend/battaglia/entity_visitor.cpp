#include "entity_visitor.h"
#include "backend/entity/player.h"
#include "backend/entity/enemy.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#define P_SIZE 80

QWidget* EntityVisitor::getWidget() { return widget; }

void EntityVisitor::visitPlayer(Player& player)  {
    Pokemon* pokemon = player.getCurrentPokemon();
    if(!pokemon) {
        characterSprite(player);
        return;
    }
    QLabel* label = new QLabel();
    QString path = ":assets/pokemons/back/" +
            QString::fromStdString(pokemon->getSprite());
    QPixmap spriteMap(path);
    label->setPixmap(spriteMap.scaled(QSize(P_SIZE,P_SIZE),Qt::KeepAspectRatio));
    label->setFixedHeight(P_SIZE);
    widget = label;
}

void EntityVisitor::visitEnemy(Enemy& enemy) {
    Pokemon* pokemon = enemy.getCurrentPokemon();
    if(!pokemon) {
        characterSprite(enemy);
        return;
    }
    QLabel* label = new QLabel();
    QString path = ":assets/pokemons/front/" + QString::fromStdString(pokemon->getSprite());
    QPixmap spriteMap(path);
    label->setPixmap(spriteMap.scaled(QSize(P_SIZE,P_SIZE),Qt::KeepAspectRatio));
    label->setFixedHeight(P_SIZE);
    widget = label;
}

void EntityVisitor::characterSprite(Entity& character) {
    QLabel* label = new QLabel();
    QPixmap sprite(QString::fromStdString(character.getSprite()));
    label->setPixmap(sprite);
    widget = label;
}

