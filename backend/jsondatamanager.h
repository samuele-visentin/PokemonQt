#ifndef JSONDATAMANAGER_H
#define JSONDATAMANAGER_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include "battle/battle.h"

class JsonDataManager
{
private:
    JsonDataManager();
    JsonDataManager(const JsonDataManager&);
public:
    static Battle* loadBattleData(const QString&);
    static QJsonObject pokemonToJson(const Pokemon&);
};

#endif // JSONDATAMANAGER_H
