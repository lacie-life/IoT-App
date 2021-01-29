#include "qmongodb.h"
#include <QFile>
#include <QDebug>

QMongoDB::QMongoDB(){}

QMongoDB::~QMongoDB(){}

int QMongoDB::initHosting()
{
    QFile f("/home/lacie/Github/IoT-App/IoT-Sensors-DB/data/mongodb.json");
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = f.readAll();
    QJsonArray array = QJsonDocument::fromJson(val.toUtf8()).array();
    qDebug() << array.size();
    for(int i = 0; i < array.size(); i++){
        QJsonObject t_obj = array[i].toObject();
        hostnames.push_back(t_obj["hostname"].toString());
        qDebug() << i << "-" << hostnames[i];
    }
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
