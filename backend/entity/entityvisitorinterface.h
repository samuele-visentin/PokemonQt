#ifndef ENTITYVISITORINTERFACE_H
#define ENTITYVISITORINTERFACE_H

class Player;
class Enemy;

class EntityVisitorInterface
{
public:
    virtual ~EntityVisitorInterface() = default;
    virtual void visitPlayer(Player& player)=0;
    virtual void visitEnemy(Enemy& player)=0;
};

#endif // ENTITYVISITORINTERFACE_H
