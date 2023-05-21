#include "battle_scene.h"

BattleScene::BattleScene(Battle battle, QWidget* parent)
    : QWidget(parent), _battle(battle)
{
    _playerWidget = new InfoWidget(_battle.getPlayerPokemon(0), this);
    _npcWidget = new InfoWidget(_battle.getNpcPokemon(0), this);
    _vLayout = new QVBoxLayout(this);
    _vLayout->addWidget(_playerWidget);
    _vLayout->addWidget(_npcWidget);
    setLayout(_vLayout);
}


