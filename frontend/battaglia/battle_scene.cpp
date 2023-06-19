#include "battle_scene.h"
#include "backend/battle/battle.h"
#include <QRadioButton>
#include <QAction>

BattleScene::BattleScene(const Battle& battle, QWidget* parent)
    : QWidget(parent), _battle(battle), indexPokemon(0)
{
    QVBoxLayout* primary_column = new QVBoxLayout(this);
    QPushButton* exitButton = new QPushButton("Ritorna al menu", this);
    connect(exitButton, &QPushButton::clicked, this, &BattleScene::returnToMain);
    exitButton->setFixedWidth(150);
    primary_column->addWidget(exitButton, 0, Qt::AlignRight);
    QHBoxLayout* primary_row = new QHBoxLayout();
    //impostiamo la schermata della battaglia a sinistra
    primary_row->addStretch(1);
    QVBoxLayout* battle_column = new QVBoxLayout();
    battle_column->setAlignment(Qt::AlignCenter);
    battle_column->addStretch(1);
    _enemyWidget = new InfoWidget(_battle.getEnemy(), this);
    _enemyWidget->setContentsMargins(0,0,50,0);
    battle_column->addWidget(_enemyWidget, 0, Qt::AlignRight);
    battle_column->addSpacing(10);
    _playerWidget = new InfoWidget(_battle.getPlayer(), this);
    _playerWidget->setContentsMargins(50,0,0,0);
    battle_column->addWidget(_playerWidget, 0, Qt::AlignLeft);
    _notificationText = new NotificationText(this);
    _notificationText->setContentsMargins(0,20,0,20);
    battle_column->addWidget(_notificationText,0,Qt::AlignCenter);
    _attackWidget = new AttackWidget(_battle.getPlayer().getCurrentPokemon().getAttackList(), this);
    battle_column->addWidget(_attackWidget);
    connect(_attackWidget, &AttackWidget::attackSelected, this, &BattleScene::onPlayerAttack);
    battle_column->addStretch(1);
    primary_row->addLayout(battle_column);
    primary_row->addSpacing(50);
    //impostiamo la schermata di scambio pokemon a destra
    _groupButton = new QButtonGroup(this);
    int index=0;
    pokemons_column = new QVBoxLayout();
    pokemons_column->setAlignment(Qt::AlignCenter);
    for(Pokemon* pokemon: _battle.getPlayer().getPokemons()) {
        QPushButton* button = new QPushButton(
            QString::fromStdString(pokemon->getName()), this);
        button->setObjectName(QString::number(index));
        if(index==0) button->setChecked(true);
        _groupButton->addButton(button, index);
        pokemons_column->addWidget(button);
        ++index;
    }
    connect(_groupButton, &QButtonGroup::idClicked, this, &BattleScene::onChangePokemon);
    primary_row->addLayout(pokemons_column);
    primary_row->addStretch(1);
    primary_column->addLayout(primary_row);

    //Aggiungiamo gli shortcut
    QAction* backAction = new QAction("Back",this);
    backAction->setShortcut(QKeySequence::fromString("Ctrl+B"));
    connect(backAction, &QAction::triggered, this, &BattleScene::returnToMain);
    this->addAction(backAction);
    QAction* winAction = new QAction("Win", this);
    winAction->setShortcut(QKeySequence::fromString("Ctrl+W"));
    connect(winAction, &QAction::triggered, this, &BattleScene::playerWin);
    this->addAction(winAction);
    QAction* loseAction = new QAction("Lose", this);
    loseAction->setShortcut(QKeySequence::fromString("Ctrl+L"));
    connect(loseAction, &QAction::triggered, this, &BattleScene::enemyWin);
    this->addAction(loseAction);
}

void BattleScene::playerWin() {
    for(QAbstractButton* button: _groupButton->buttons()) {
        if(dynamic_cast<QPushButton*>(button))
            static_cast<QPushButton*>(button)->setEnabled(false);
    }
    _attackWidget->setEnabled(false);
    _notificationText->notify(_battle.getPlayer().getName() + " ha vinto!!!");
}

void BattleScene::enemyWin() {
    for(QAbstractButton* button: _groupButton->buttons()) {
        if(dynamic_cast<QPushButton*>(button))
            static_cast<QPushButton*>(button)->setEnabled(false);
    }
    _attackWidget->setEnabled(false);
    _notificationText->notify(_battle.getEnemy().getName() + " ha vinto!!!");
}

void BattleScene::turn(Pokemon& attacker, Pokemon& defender, Attack& attack) {
    if(!attacker.hasStatus() || attacker.getStatus().canAttack()) {
        _notificationText->notify(attacker.getName() + " usa " + attack.getName());
        attacker.doAttack(defender, attack);
        if(!defender.hasStatus() && attack.applyStatus()) {
            defender.setStatus(attack.getStatus());
            _notificationText->notify(defender.getName() + " è stato " + defender.getStatus().getName());
        }
    } else {
        _notificationText->notify(attacker.getName() + " non può attaccare!");
    }
}

void BattleScene::playerPokemonFainted() {
    disablePokemonButton();
    if(_battle.getPlayer().hasPokemonAlive()) {
        _notificationText->notify("Cambia pokemon!!!");
    } else {
       enemyWin();
    }
}

void BattleScene::enemyPokemonFainted() {
    if(_battle.getEnemy().hasPokemonAlive()) {
        _battle.getEnemy().changePokemon();
        _notificationText->notify(_battle.getEnemy().getName() + " entra in campo " + _battle.getEnemy().getCurrentPokemon().getName() + "!");
        _enemyWidget->refreshInfo();
        _attackWidget->setEnabled(true);
    } else {
        playerWin();
    }
}

void BattleScene::onPlayerAttack(int indexAttack) {
    _attackWidget->setEnabled(false);   
    Attack& playerAttack = _battle.getPlayerAttack(indexAttack);
    Attack& enemyAttack = _battle.getEnemyAttack();
    _notificationText->notify("Hai selezionato: " + playerAttack.getName());
    Pokemon& playerPokemon = _battle.getPlayer().getCurrentPokemon();
    Pokemon& enemyPokemon = _battle.getEnemy().getCurrentPokemon();
    if(playerPokemon.getSpeed() >= enemyPokemon.getSpeed()) {
        turn(playerPokemon, enemyPokemon, playerAttack);
        _enemyWidget->refreshHealth();
        if(enemyPokemon.isFainted()) {
            enemyPokemonFainted();
            return;
        }
        turn(enemyPokemon, playerPokemon, enemyAttack);
        _playerWidget->refreshHealth();
        if(playerPokemon.isFainted()) {
            playerPokemonFainted();
            return;
        }
    }
    else {
        turn(enemyPokemon, playerPokemon, enemyAttack);
        _playerWidget->refreshHealth();
        if(playerPokemon.isFainted()) {
            playerPokemonFainted();
            return;
        }
        turn(playerPokemon, enemyPokemon, playerAttack);
        _enemyWidget->refreshHealth();
        if(enemyPokemon.isFainted()) {
            enemyPokemonFainted();
            return;
        }
    }
    notifyStatusPokemon(enemyPokemon, _enemyWidget);
    if(enemyPokemon.isFainted()) {
        enemyPokemonFainted();
        return;
    }
    notifyStatusPokemon(playerPokemon, _playerWidget);
    if(playerPokemon.isFainted()) {
        playerPokemonFainted();
        return;
    }
    _attackWidget->setEnabled(true);
}

void BattleScene::onChangePokemon(int index) {
    if(index==indexPokemon) return;
    indexPokemon = index;
    Pokemon& pokemon = _battle.getPlayer().setCurrentPokemon(index);
    _playerWidget->refreshInfo();
    _attackWidget->updateAttacks(pokemon.getAttackList());
    if(!_attackWidget->isEnabled()) _attackWidget->setEnabled(true);
    _notificationText->notify("Entra in campo " + pokemon.getName());
}

void BattleScene::disablePokemonButton() {
    QPushButton* button = qobject_cast<QPushButton*>(pokemons_column->itemAt(indexPokemon)->widget());
    button->setDisabled(true);
}

void BattleScene::notifyStatusPokemon(Pokemon& pokemon, InfoWidget* info) {
    if(pokemon.hasStatus()) {
        if(pokemon.getStatus().isFinish()) {
            _notificationText->notify(pokemon.getName() + " non è più affetto dallo stato " + pokemon.getStatus().getName());
            pokemon.removeStatus();
            info->refreshStatus();
        } else {
            pokemon.statusEffect();
            _notificationText->notify(pokemon.getName() + " è ancora effetto dallo stato " + pokemon.getStatus().getName());
            info->refreshHealth();
        }
    }
}
