#ifndef QMONGODB_H
#define QMONGODB_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QVector>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

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
    QJsonObject getData(QNodeData Node);
    bool insertData(QJsonObject item, QNodeData Node);
    bool deleteData(QJsonObject item, QNodeData Node);
    bool changeData(QJsonObject item, QNodeData Node);
    QVector<QNodeData> Nodes;

private:
    QString mongodb_uri;
    QVector<QString> hostnames;

};

#endif // QMONGODB_H
