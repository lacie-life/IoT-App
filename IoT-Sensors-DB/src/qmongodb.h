#ifndef QMONGODB_H
#define QMONGODB_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QVector>

#include <nlohmann/json.hpp>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/types.hpp>
#include <bsoncxx/document/element.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

struct QNodeData{
    QString database;
    QString collection;
};

class QMongoDB : public QObject
{
    Q_OBJECT
public:
    QMongoDB();
    ~QMongoDB();

    int initHosting();
    QJsonArray getData(QNodeData Node);
    bool insertData(QJsonObject item, QNodeData Node);
    bool deleteData(QJsonObject item, QNodeData Node);
    bool changeData(QJsonObject item, QNodeData Node);
    QVector<QNodeData> Nodes;

private:
    QVector<QString> mongodb_uri;
    QVector<QString> hostnames;

    QJsonObject ObjectFromString(const QString& in);
    std::string StringFromObject(const QJsonObject& in);
    bsoncxx::document::view toBson(const QJsonObject& in);
    QJsonObject toJson(bsoncxx::document::view view);
    QString StringFromBson(bsoncxx::document::view view, std::string key);
};

#endif // QMONGODB_H
