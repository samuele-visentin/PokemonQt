#include "battle_scene.h"

BattleScene::BattleScene(Battle* battle, QWidget* parent)
    : QWidget(parent), _battle(battle)
{
    _playerLabel =
            new QLabel(QString::fromStdString(battle->getPlayerName()), this);
    _npcLabel =
            new QLabel(QString::fromStdString(battle->getPlayerName()), this);

    _attackButton = new QPushButton("Attack", this);

    // Crea un layout verticale per organizzare i widget
    _vLayout = new QVBoxLayout();
    _vLayout->addWidget(_playerLabel);
    _vLayout->addWidget(_npcLabel);
    //_vLayout->addWidget(attackButton);

    // Connetti il pulsante di attacco al slot onAttackButtonClicked()
    //connect(attackButton, &QPushButton::clicked, this, &BattleWindow::onAttackButtonClicked);
}

BattleScene::~BattleScene(){
    delete _battle;
}

