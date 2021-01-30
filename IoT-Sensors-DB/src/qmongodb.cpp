#include "qmongodb.h"
#include <QFile>
#include <QDebug>

using json = nlohmann::json;

QMongoDB::QMongoDB(){}

QMongoDB::~QMongoDB(){}

QJsonObject QMongoDB::ObjectFromString(const QString &in)
{
    QByteArray br = in.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(br);

    QJsonObject obj = doc.object();
    return obj;
}

std::string QMongoDB::StringFromObject(const QJsonObject &in)
{
    QJsonDocument doc(in);
    QString strFromObj = doc.toJson(QJsonDocument::Compact).toStdString().c_str();
    std::string temp = strFromObj.toStdString();

    return temp;
}

bsoncxx::document::view QMongoDB::toBson(const QJsonObject &in)
{
    if(in.isEmpty()){
        return ::bsoncxx::document::view();
    }

    QJsonDocument doc(in);
    std::string json = doc.toJson().data();
    return bsoncxx::from_json(json).view();
}

QJsonObject QMongoDB::toJson(bsoncxx::document::view view)
{
    if(view.empty()){
        return QJsonObject();
    }

    std::string json = bsoncxx::to_json(view);
    QJsonDocument doc = QJsonDocument::fromJson(QByteArray::fromStdString(json));

    if(doc.isObject()){
        return doc.object();
    }
    else {
        return QJsonObject();
    }
}

QString QMongoDB::StringFromBson(bsoncxx::document::view view, std::string key)
{
    if(view.empty()){
        return QString();
    }

    bsoncxx::document::element element = view[key];
    if(element.type() == bsoncxx::type::k_utf8){
        std::string value = element.get_utf8().value.to_string();
        return QString::fromStdString(value);
    }
    else {
        return QString();
    }
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
        mongodb_uri.push_back("mongodb://" + hostnames.at(i) + ":27017");
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
    mongocxx::instance instance{};
    mongocxx::uri uri("mongodb://" + hostnames.at(0).toStdString() + ":27017");
    mongocxx::client client(uri);

    mongocxx::database db = client[Node.database.toStdString()];
    mongocxx::collection coll = db[Node.collection.toStdString()];

    bsoncxx::document::view doc = toBson(item);
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(doc);

    return true;
}

bool QMongoDB::deleteData(QJsonObject item, QNodeData Node)
{

}

bool QMongoDB::changeData(QJsonObject item, QNodeData Node)
{

}


