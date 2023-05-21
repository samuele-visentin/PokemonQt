#ifndef BATTLE_SCENE_H
#define BATTLE_SCENE_H

#include "frontend/battaglia/info_widget.h"
#include "backend/battle/battle.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class BattleScene: public QWidget
{
    Q_OBJECT
private:
    QPushButton* _attackButton;
    QLabel* _playerLabel;
    QLabel* _npcLabel;
    QVBoxLayout* _vLayout;
    InfoWidget* info1;
    InfoWidget* info2;
    Battle* _battle;
public:
    BattleScene(Battle* battle, QWidget* parent = nullptr);
    ~BattleScene();
private slots:
    //void onAttackButtonClick();
};

#endif // BATTLE_SCENE_H
