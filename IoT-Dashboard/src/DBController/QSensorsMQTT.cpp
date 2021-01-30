#include "../../hdr/DBController/QSensorsMQTT.h"

QSensorsMQTT::QSensorsMQTT(){}

QSensorsMQTT::~QSensorsMQTT(){}

int QSensorsMQTT::initBrokerHost()
{
    QFile f(broker_path);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = f.readAll();
    QJsonArray array = QJsonDocument::fromJson(val.toUtf8()).array();
    for(int i = 0; i < array.size(); i++){
        QJsonObject t_obj = array[i].toObject();
        brokerHosts.push_back(t_obj["hostname"].toString());
//        qDebug()<< i << "-" <<hostnames[i];
    }
    return 0;
}

int QSensorsMQTT::loadSensorsParamenters(int index)
{
    QFile file(device_path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = file.readAll();
    file.close();
    QJsonArray a = QJsonDocument::fromJson(val.toUtf8()).array();

    for (int i = 0; i < a.count(); ++i) {
        QJsonValue v = a[i];
        SensorNode node;
        node.topic_data = v["topic-sensor"].toString();
        node.topic_control = v["topic-control"].toString();
        node.token = v["token"].toString();
        node.mac_address = v["mac_address"].toString();
        sensorsNode.push_back(node);
    }
    return 0;
}

void QSensorsMQTT::publish(SensorNode node, QString mess)
{

}

void QSensorsMQTT::subcrib(SensorNode node)
{

}
