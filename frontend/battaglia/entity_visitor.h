#ifndef ENTITYVISITOR_H
#define ENTITYVISITOR_H

#include "backend/entity/entityvisitorinterface.h"
#include <QWidget>

class EntityVisitor: public EntityVisitorInterface
{
private:
    QWidget* widget;
public:
    QWidget* getWidget();
    void visitPlayer(Player& player) override;
    void visitEnemy(Enemy& enemy) override;
};

#endif // ENTITYVISITOR_H
