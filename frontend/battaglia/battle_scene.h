#ifndef BATTLE_SCENE_H
#define BATTLE_SCENE_H

#include "frontend/battaglia/info_widget.h"
#include "backend/battle/battle.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>

class BattleScene: public QWidget
{
    Q_OBJECT
private:
    QPushButton* _attackButton;
    QLabel* _playerLabel;
    QLabel* _npcLabel;
    QVBoxLayout* _vLayout;
    InfoWidget* _playerWidget;
    InfoWidget* _npcWidget;
    QTextEdit* _notificationText;
    Battle _battle;
public:
    BattleScene(Battle battle, QWidget* parent = nullptr);
private slots:
    //void onAttackButtonClick();
};

#endif // BATTLE_SCENE_H
