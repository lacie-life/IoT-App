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
//        qDebug() << i << "-" << hostnames[i];

        QJsonArray db_array = t_obj["databases"].toArray();
//        qDebug() << i << "-" << db_array.size();

        for (int j = 0; j < db_array.size(); j++){

            QJsonObject t_db = db_array[j].toObject();
            QJsonArray collection_array = t_db["collection"].toArray();

            for (int k = 0; k < collection_array.size(); k++){
                QNodeData t_node;
                t_node.database = t_db["name"].toString();
                t_node.collection = collection_array[k].toString();
                Nodes.push_back(t_node);
            }
        }

    }
    return 0;
}

QJsonObject QMongoDB::getData(QNodeData Node)
{

}

bool QMongoDB::insertData(QJsonObject item, QNodeData Node)
{

}

bool QMongoDB::deleteData(QJsonObject item, QNodeData Node)
{

}

bool QMongoDB::changeData(QJsonObject item, QNodeData Node)
{

}
