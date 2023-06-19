#ifndef BATTLE_SCENE_H
#define BATTLE_SCENE_H

#include "frontend/battaglia/attack_widget.h"
#include "frontend/battaglia/info_widget.h"
#include "backend/battle/battle.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include "notification_text.h"

class BattleScene: public QWidget
{
    Q_OBJECT
private:
    QPushButton* _attackButton;
    QButtonGroup* _groupButton;
    InfoWidget* _playerWidget;
    InfoWidget* _enemyWidget;
    NotificationText* _notificationText;
    AttackWidget* _attackWidget;
    QVBoxLayout* pokemons_column;
    Battle _battle;
    int indexPokemon;
    void turn(Pokemon& attacker, Pokemon& defender, Attack& attack);
    void disablePokemonButton();
    void playerPokemonFainted();
    void enemyPokemonFainted();
    void changeEnemyPokemon();
    void notifyStatusPokemon(Pokemon& pokemon, InfoWidget* info);
public:
    BattleScene(const Battle& battle, QWidget* parent = nullptr);
private slots:
    void onPlayerAttack(int indexAttack);
    void onChangePokemon(int index);
    void playerWin();
    void enemyWin();
signals:
    void returnToMain();
};

#endif // BATTLE_SCENE_H
