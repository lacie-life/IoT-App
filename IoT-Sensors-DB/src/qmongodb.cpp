#include "qmongodb.h"
#include <QFile>

QMongoDB::QMongoDB(){}

QMongoDB::~QMongoDB(){}

int QMongoDB::initHosting()
{
    QFile f(":data/mongodb.json");
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = f.readAll();
    QJsonArray array = QJsonDocument::fromJson(val.toUtf8()).array();


}

QJsonObject QMongoDB::getData(QString database, QString collection)
{

}

bool QMongoDB::insertData(QJsonObject item)
{

}

bool QMongoDB::deleteData(QJsonObject item)
{

}

bool QMongoDB::changeData(QJsonObject item)
{

}
