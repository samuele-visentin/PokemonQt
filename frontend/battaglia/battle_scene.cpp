#include "battle_scene.h"
#include "backend/battle/battle.h"
#include <QTimer>

BattleScene::BattleScene(const Battle& battle, QWidget* parent)
    : QWidget(parent), _battle(battle)
{
    QVBoxLayout* column = new QVBoxLayout(this);
    column->setAlignment(Qt::AlignCenter);
    column->addStretch(1);
    InfoWidget* enemy = new InfoWidget(_battle.getEnemy(), this);
    enemy->setContentsMargins(0,0,180,0);
    column->addWidget(enemy, 0, Qt::AlignRight);
    column->addSpacing(10);
    InfoWidget* player = new InfoWidget(_battle.getPlayer(), this);
    player->setContentsMargins(180,0,0,0);
    column->addWidget(player, 0, Qt::AlignLeft);
    _notificationText = new NotificationText(this);
    _notificationText->setContentsMargins(0,20,0,20);
    column->addWidget(_notificationText,0,Qt::AlignCenter);
    _attackWidget = new AttackWidget(_battle.getPlayer().getCurrentPokemon()->getAttackList(), this);
    column->addWidget(_attackWidget);
    connect(_attackWidget, &AttackWidget::attackSelected, this, &BattleScene::onPlayerAttack);
    column->addStretch(1);
}

void BattleScene::onPlayerAttack(int indexAttack) {
    _attackWidget->setEnabled(false);
    _notificationText->notify("SUS LA ZAZA ");
    _battle.performTurn(indexAttack);
    _attackWidget->setEnabled(true);
}

