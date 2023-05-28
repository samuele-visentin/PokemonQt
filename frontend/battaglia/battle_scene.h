#ifndef BATTLE_SCENE_H
#define BATTLE_SCENE_H

#include "frontend/battaglia/attack_widget.h"
#include "frontend/battaglia/info_widget.h"
#include "backend/battle/battle.h"
#include <QPushButton>
#include <QVBoxLayout>
#include "notification_text.h"

class BattleScene: public QWidget
{
    Q_OBJECT
private:
    QPushButton* _attackButton;
    InfoWidget* _playerWidget;
    InfoWidget* _npcWidget;
    NotificationText* _notificationText;
    AttackWidget* _attackWidget;
    Battle _battle;

    void notifyText(const std::string& string);
public:
    BattleScene(const Battle& battle, QWidget* parent = nullptr);
private slots:
    void onPlayerAttack(int indexAttack);
};

#endif // BATTLE_SCENE_H
