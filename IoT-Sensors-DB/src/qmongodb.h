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

class QMongoDB
{
public:
    QMongoDB();
    ~QMongoDB();

    int initHosting();
    QJsonObject getData(QString database, QString collection);
    bool insertData(QJsonObject item);
    bool deleteData(QJsonObject item);
    bool changeData(QJsonObject item);

private:
    QVector<QString> database;
    QVector<QString> collection;
    QString mongodb_uri;

};

#endif // QMONGODB_H
