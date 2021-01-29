#include "qmongodb.h"
#include <QFile>
#include <QDebug>

QMongoDB::QMongoDB(){}

QMongoDB::~QMongoDB(){}

QJsonObject QMongoDB::ObjectFromString(const QString &in)
{
    QByteArray br = in.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(br);

    QJsonObject obj = doc.object();
    return obj;
}


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

QJsonArray QMongoDB::getData(QNodeData Node)
{
    mongocxx::instance instance{};
    mongocxx::uri uri("mongodb://" + hostnames.at(0).toStdString() + ":27017");
    mongocxx::client client(uri);

    mongocxx::database db = client[Node.database.toStdString()];
    mongocxx::collection coll = db[Node.collection.toStdString()];

    mongocxx::cursor cursor = coll.find({});
    QJsonArray data;
    int i = 0;
    for (auto doc : cursor){
        std::string temp =  bsoncxx::to_json(doc);
        data[i] =  ObjectFromString(QString::fromStdString(temp));
        i++;
    }
    return data;
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


