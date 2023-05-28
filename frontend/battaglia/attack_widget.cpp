#include "attack_widget.h"
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QLabel>
#include "backend/attacks/attack.h"
#include <QPushButton>

AttackWidget::AttackWidget(std::vector<Attack>& attacks, QWidget *parent)
    : QWidget{parent}, _attacks(&attacks)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("<b>Seleziona un attacco: </b>", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);

    QButtonGroup* buttonGroup = new QButtonGroup(this);
    connect(buttonGroup, &QButtonGroup::idClicked, this, &AttackWidget::handleAttackSelection);

    QHBoxLayout* row = new QHBoxLayout();
    grid = new QGridLayout();
    grid->setSpacing(10);
    int index = 0;
    for (const Attack& attack : attacks) {
        QString text = QString::fromStdString(attack.getName()) +
                "\n" + QString::number(attack.getCurrentUsage()) +
                " / " + QString::number(attack.getMaxUsage());
        QPushButton* button = new QPushButton(text, this);
        button->setFixedSize(QSize(140,40));
        button->setObjectName(QString::number(index));
        buttonGroup->addButton(button, index);
        grid->addWidget(button, index / 2, index % 2);
        index++;
    }
    grid->setHorizontalSpacing(10);
    grid->setVerticalSpacing(10);
    row->addStretch(1);
    row->addLayout(grid);
    row->addStretch(1);
    layout->addLayout(row);
    layout->setAlignment(Qt::AlignCenter);
}

void AttackWidget::updateAttacks(std::vector<Attack>& attacks) {
    _attacks = &attacks;
    refresh();
}

void AttackWidget::refresh() {
    for(int i=0;i<4;++i){
        QLayoutItem* item = grid->itemAtPosition(i/2,i%2);
        QPushButton* button = qobject_cast<QPushButton*>(item->widget());
        Attack& attack = (*_attacks)[i];
        QString text = QString::fromStdString(attack.getName()) +
                "\n" + QString::number(attack.getCurrentUsage()) +
                " / " + QString::number(attack.getMaxUsage());
        button->setText(text);
        if(attack.getCurrentUsage() == 0) {
            button->setEnabled(false);
        }
    }
}

void AttackWidget::handleAttackSelection(int attackIndex) {
    Attack& attack = (*_attacks)[attackIndex];
    attack.consume();
    QLayoutItem* item = grid->itemAt(attackIndex);
    QPushButton* button = qobject_cast<QPushButton*>(item->widget());
    QString text = QString::fromStdString(attack.getName()) +
            "\n" + QString::number(attack.getCurrentUsage()) +
            " / " + QString::number(attack.getMaxUsage());
    button->setText(text);
    if(attack.getCurrentUsage() == 0) {
        button->setEnabled(false);
    }
    emit attackSelected(attackIndex);
}
