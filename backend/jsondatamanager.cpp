#include "jsondatamanager.h"

JsonDataManager::JsonDataManager()
{}

Battle* JsonDataManager::loadBattleData(const QString& fileName) {
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)){
        throw "Error, cannot open file";
    }
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonParseError parseError;
    QJsonDocument json = QJsonDocument::fromJson(jsonData,&parseError);
    if(parseError.error != QJsonParseError::NoError){
        throw parseError.error;
    }
    QJsonObject root = json.object();
    //return new Battle();
    return nullptr;
}
