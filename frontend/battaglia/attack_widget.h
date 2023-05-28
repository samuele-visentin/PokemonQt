#ifndef ATTACKWIDGET_H
#define ATTACKWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "backend/attacks/attack.h"

class AttackWidget : public QWidget
{
    Q_OBJECT
private:
    std::vector<Attack>* _attacks;
    QGridLayout* grid;
public:
    AttackWidget(std::vector<Attack>& attacks, QWidget *parent = nullptr);
    void updateAttacks(std::vector<Attack>& attacks);
    void refresh();
signals:
    void attackSelected(int attackIndex);
private slots:
    void handleAttackSelection(int attackIndex);
};

#endif // ATTACKWIDGET_H
